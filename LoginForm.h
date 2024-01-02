#pragma once
#include "ClientForm.h"
#include "RegistrationForm.h"
namespace Project14 {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Data::SqlClient;
    public ref class LoginForm : public System::Windows::Forms::Form
    {
    public:
        LoginForm()
        {
            InitializeComponent();
        }

    protected:
        ~LoginForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ textBoxUsername;
        System::Windows::Forms::TextBox^ textBoxPassword;
        System::Windows::Forms::Button^ buttonLogin;
        System::Windows::Forms::Button^ buttonRegister;

        void InitializeComponent()
        {
            this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
            this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->buttonLogin = (gcnew System::Windows::Forms::Button());
            this->buttonRegister = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // textBoxUsername
            // 
            this->textBoxUsername->Location = System::Drawing::Point(12, 12);
            this->textBoxUsername->Name = L"textBoxUsername";
            this->textBoxUsername->Size = System::Drawing::Size(200, 20);
            this->textBoxUsername->TabIndex = 0;
            this->textBoxUsername->Text = L"Enter username";
            // 
            // textBoxPassword
            // 
            this->textBoxPassword->Location = System::Drawing::Point(12, 38);
            this->textBoxPassword->Name = L"textBoxPassword";
            this->textBoxPassword->PasswordChar = '*';
            this->textBoxPassword->Size = System::Drawing::Size(200, 20);
            this->textBoxPassword->TabIndex = 1;
            this->textBoxPassword->Text = L"Enter password";
            // 
            // buttonLogin
            // 
            this->buttonLogin->Location = System::Drawing::Point(12, 64);
            this->buttonLogin->Name = L"buttonLogin";
            this->buttonLogin->Size = System::Drawing::Size(100, 23);
            this->buttonLogin->TabIndex = 2;
            this->buttonLogin->Text = L"Login";
            this->buttonLogin->UseVisualStyleBackColor = true;
            this->buttonLogin->Click += gcnew System::EventHandler(this, &LoginForm::buttonLogin_Click);
            // 
            // buttonRegister
            // 
            this->buttonRegister->Location = System::Drawing::Point(112, 64);
            this->buttonRegister->Name = L"buttonRegister";
            this->buttonRegister->Size = System::Drawing::Size(100, 23);
            this->buttonRegister->TabIndex = 3;
            this->buttonRegister->Text = L"Register";
            this->buttonRegister->UseVisualStyleBackColor = true;
            this->buttonRegister->Click += gcnew System::EventHandler(this, &LoginForm::buttonRegister_Click);
            // 
            // LoginForm
            // 
            this->ClientSize = System::Drawing::Size(341, 178);
            this->Controls->Add(this->textBoxUsername);
            this->Controls->Add(this->textBoxPassword);
            this->Controls->Add(this->buttonLogin);
            this->Controls->Add(this->buttonRegister);
            this->Name = L"LoginForm";
            this->Text = L"Login / Register";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        bool IsLoginValid(String^ username, String^ password)
        {
            // Ваша логика проверки учетных данных в базе данных
            try
            {
                String^ connectionString = "Data Source=your_server;Initial Catalog=your_database;Integrated Security=True";
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

        System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Добавьте здесь код для обработки входа пользователя
            // Проверьте учетные данные введенные в textBoxUsername и textBoxPassword
            // Если вход успешен, откройте новую форму чата и закройте текущую форму
            this->Hide(); // Скрыть текущую форму

            Project14::ClientForm^ chatForm = gcnew ClientForm();
            chatForm->ShowDialog();

            this->Close(); // Закрыть текущую форму после успешного входа
        }

        System::Void buttonRegister_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Project14::RegistrationForm^ registrationForm = gcnew RegistrationForm();
            registrationForm->ShowDialog();
        }
    };
}
