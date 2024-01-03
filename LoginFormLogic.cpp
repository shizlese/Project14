bool IsLoginValid(String^ username, String^ password)
{
    // Ваша логика проверки учетных данных в базе данных
    try
    {
        String^ connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=chat;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        connection->Open();

        // Защита от SQL-инъекций - лучше использовать параметризованные запросы
        String^ query = "SELECT * FROM users WHERE username = @username AND password = @password";
        SqlCommand^ command = gcnew SqlCommand(query, connection);
        command->Parameters->AddWithValue("@username", username);
        command->Parameters->AddWithValue("@password", password);
        SqlDataReader^ reader = command->ExecuteReader();

        if (reader->HasRows)
        {
            // Вход успешен
            reader->Close();
            connection->Close();
            return true;
        }
        else
        {
            // Неверный логин или пароль
            reader->Close();
            connection->Close();
            return false;
        }
    }
    catch (Exception^ ex)
    {
        // Обработка ошибок подключения к базе данных
        Console::WriteLine(ex->Message);
        return false;
    }
}
bool IsLoginValidTask()
{
    return IsLoginValid(textBoxUsername->Text, textBoxPassword->Text);
}

void LoginAsync(System::Threading::CancellationToken cancellationToken)
{
    System::Threading::Tasks::Task<bool>^ loginTask = System::Threading::Tasks::Task::Run(gcnew System::Func<bool>(this, &LoginForm::IsLoginValidTask), cancellationToken);

    loginTask->ContinueWith(gcnew System::Action<System::Threading::Tasks::Task<bool>^>(this, &LoginForm::OnLoginCompleted));
}

void OnLoginCompleted(System::Threading::Tasks::Task<bool>^ task)
{
    try
    {
        bool result = task->Result;

        if (result)
        {
            // Вход успешен
            this->Invoke(gcnew System::Action(this, &LoginForm::HideForm)); // Вызов метода HideForm из потока UI
        }
        else
        {
            // Неверный логин или пароль
            this->Invoke(gcnew System::Action<String^>(this, &LoginForm::SetStatusLabel), "Неправильный логин или пароль");
        }
    }
    catch (System::Threading::Tasks::TaskCanceledException^)
    {
        // Операция была отменена (например, при закрытии формы до завершения задачи)
    }
}
void HideForm()
{
    this->Hide();
    Project14::ClientForm^ chatForm = gcnew ClientForm();
    chatForm->ShowDialog();
    this->Close(); // Закрыть текущую форму после успешного входа
}

void SetStatusLabel(String^ message)
{
    labelResultLogin->Text = message;
}
System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e)
{
    cts = gcnew System::Threading::CancellationTokenSource();
    LoginAsync(cts->Token);

}