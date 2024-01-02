#pragma once

namespace Project14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RegistrationForm
	/// </summary>
	public ref class RegistrationForm : public System::Windows::Forms::Form
	{
	public:
		RegistrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

    protected:
        ~RegistrationForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ textBoxNewUsername;
        System::Windows::Forms::TextBox^ textBoxNewPassword;
        System::Windows::Forms::Button^ buttonCreateAccount;

        // Добавьте здесь другие компоненты формы, если они есть

        System::ComponentModel::Container^ components;  // Определение переменной components

        void InitializeComponent()
        {
            // Инициализация компонентов формы
            this->components = gcnew System::ComponentModel::Container();
            this->textBoxNewUsername = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNewPassword = (gcnew System::Windows::Forms::TextBox());
            this->buttonCreateAccount = (gcnew System::Windows::Forms::Button());

            // Остальной код для инициализации компонентов

            this->SuspendLayout();

            // Остальной код для размещения компонентов на форме
        }

        System::Void buttonCreateAccount_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Получаем введенные пользователем логин и пароль для новой учетной записи
            String^ newUsername = textBoxNewUsername->Text;
            String^ newPassword = textBoxNewPassword->Text;

            // Добавьте здесь код для создания новой учетной записи
            // Например, выполните SQL-запрос для добавления нового пользователя в базу данных
            // Или сохраните учетные данные в файле, если используете другой механизм хранения

            // После успешной регистрации, вы можете закрыть форму регистрации или выполнить другие действия
            this->Close();
        }
    };
}
