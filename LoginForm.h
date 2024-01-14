#pragma once
#include "ClientForm.h"
#include "RegistrationForm.h"
#include "Global.h"
namespace Project14 {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Data::SqlClient;
    using namespace System::Threading::Tasks;
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
        TcpClient^ client;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ textBoxUsername;
        System::Windows::Forms::TextBox^ textBoxPassword;
        System::Windows::Forms::Button^ buttonLogin;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ labelResultLogin;
           System::Windows::Forms::Button^ buttonRegister;
           bool sendCompleted;
           bool receiveCompleted;

           String^ serverResponse;

        void InitializeComponent()
        {
            this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
            this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->buttonLogin = (gcnew System::Windows::Forms::Button());
            this->buttonRegister = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->labelResultLogin = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBoxUsername
            // 
            this->textBoxUsername->Location = System::Drawing::Point(96, 85);
            this->textBoxUsername->Name = L"textBoxUsername";
            this->textBoxUsername->Size = System::Drawing::Size(200, 20);
            this->textBoxUsername->TabIndex = 0;
            // 
            // textBoxPassword
            // 
            this->textBoxPassword->Location = System::Drawing::Point(96, 134);
            this->textBoxPassword->Name = L"textBoxPassword";
            this->textBoxPassword->Size = System::Drawing::Size(200, 20);
            this->textBoxPassword->TabIndex = 1;
            // 
            // buttonLogin
            // 
            this->buttonLogin->Location = System::Drawing::Point(146, 160);
            this->buttonLogin->Name = L"buttonLogin";
            this->buttonLogin->Size = System::Drawing::Size(100, 23);
            this->buttonLogin->TabIndex = 2;
            this->buttonLogin->Text = L"Вход";
            this->buttonLogin->UseVisualStyleBackColor = true;
            this->buttonLogin->Click += gcnew System::EventHandler(this, &LoginForm::buttonLogin_Click);
            // 
            // buttonRegister
            // 
            this->buttonRegister->Location = System::Drawing::Point(146, 189);
            this->buttonRegister->Name = L"buttonRegister";
            this->buttonRegister->Size = System::Drawing::Size(100, 23);
            this->buttonRegister->TabIndex = 3;
            this->buttonRegister->Text = L"Регистрация";
            this->buttonRegister->UseVisualStyleBackColor = true;
            this->buttonRegister->Click += gcnew System::EventHandler(this, &LoginForm::buttonRegister_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(96, 59);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(108, 13);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Введите псевдоним";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(96, 112);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(90, 13);
            this->label2->TabIndex = 5;
            this->label2->Text = L"Введите Пароль";
            // 
            // labelResultLogin
            // 
            this->labelResultLogin->AutoSize = true;
            this->labelResultLogin->Location = System::Drawing::Point(96, 31);
            this->labelResultLogin->Name = L"labelResultLogin";
            this->labelResultLogin->Size = System::Drawing::Size(0, 13);
            this->labelResultLogin->TabIndex = 6;
            // 
            // LoginForm
            // 
            this->ClientSize = System::Drawing::Size(396, 233);
            this->Controls->Add(this->labelResultLogin);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBoxUsername);
            this->Controls->Add(this->textBoxPassword);
            this->Controls->Add(this->buttonLogin);
            this->Controls->Add(this->buttonRegister);
            this->Name = L"LoginForm";
            this->Text = L"Вход\\Регистрация";
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginForm::LoginForm_FormClosed);
            this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ username = textBoxUsername->Text;
            String^ password = textBoxPassword->Text;
            try
            {
                TcpClient ^ client = gcnew TcpClient("127.0.0.1", 1234);
                NetworkStream^ stream = client->GetStream();

                String^ loginData = "login_request:" + username + ":" + password;
                array<Byte>^ sendData = Encoding::UTF8->GetBytes(loginData);

                // Отправка данных на сервер
                stream->Write(sendData, 0, sendData->Length);

                // Получение ответа от сервера
                array<Byte>^ buffer = gcnew array<Byte>(1024);
                int bytesRead = stream->Read(buffer, 0, buffer->Length);
                String^ response = Encoding::UTF8->GetString(buffer, 0, bytesRead);

                // Обработка полученного ответа
                if (response == "Login successful")
                {
                    // Вход успешен, открываем форму чата (ClientForm)
                    Global::GlobalData::CurrentUser = username;
                    ClientForm^ clientForm = gcnew ClientForm();
                    clientForm->Show();
                    this->Hide(); // Скрываем форму входа
                }
                else if (response == "Login failed")
                {
                    // Неверные учетные данные, обработайте соответственно
                    labelResultLogin->Text = ("неверный логин или пароль");
                }

                client->Close();
            }
                catch (Exception^ ex)
            {
                // Обработка ошибок соединения с сервером
                    labelResultLogin->Text=("Error connecting to the server: " + ex->Message);
            }
        }

        void buttonRegister_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ username = textBoxUsername->Text;
            String^ password = textBoxPassword->Text;
            try
            {
                TcpClient^ client = gcnew TcpClient("127.0.0.1", 1234);
                NetworkStream^ stream = client->GetStream();

                String^ loginData = "register_request:" + username + ":" + password;
                array<Byte>^ sendData = Encoding::UTF8->GetBytes(loginData);

                // Отправка данных на сервер
                stream->Write(sendData, 0, sendData->Length);

                // Получение ответа от сервера
                array<Byte>^ buffer = gcnew array<Byte>(1024);
                int bytesRead = stream->Read(buffer, 0, buffer->Length);
                String^ response = Encoding::UTF8->GetString(buffer, 0, bytesRead);

                // Обработка полученного ответа
                if (response == "Registration successful")
                {
                    // Вход успешен, открываем форму чата (ClientForm)
                    labelResultLogin->Text = "новый пользователь успешно создан";
                }
                else if (response == "Username already exists")
                {
                    // Неверные учетные данные, обработайте соответственно
                    labelResultLogin->Text = "пользователь с таким именем уже существует";
                }

                client->Close();
            }
            catch (Exception^ ex)
            {
                // Обработка ошибок соединения с сервером
                labelResultLogin->Text=("Error connecting to the server: " + ex->Message);
            }
        }

        
private: System::Void LoginForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
        
    }
private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {

}
};
};
