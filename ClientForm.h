#pragma once
#include "ClientForm.cpp"
#include "Global.h"
namespace Project14 {
    using namespace System;
    using namespace System::Net;
    using namespace System::Net::Sockets;
    using namespace System::Text;
    using namespace Microsoft::VisualBasic;
    public ref class ClientForm : public System::Windows::Forms::Form
    {
    public:
        ClientForm()
        {
            InitializeComponent();
        }

    protected:
        ~ClientForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:

        System::Windows::Forms::TextBox^ textBoxMessage;
        System::Windows::Forms::Button^ buttonSend;
    private: System::Windows::Forms::ComboBox^ comboBoxChat;

    private: System::Windows::Forms::Label^ label1;

    private: System::Windows::Forms::Button^ createChatButton;
    private: System::Windows::Forms::Label^ CurrentChat;


           System::Windows::Forms::RichTextBox^ richTextBoxChat;

        void InitializeComponent()
        {
            this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
            this->buttonSend = (gcnew System::Windows::Forms::Button());
            this->richTextBoxChat = (gcnew System::Windows::Forms::RichTextBox());
            this->comboBoxChat = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->createChatButton = (gcnew System::Windows::Forms::Button());
            this->CurrentChat = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBoxMessage
            // 
            this->textBoxMessage->Location = System::Drawing::Point(133, 236);
            this->textBoxMessage->Name = L"textBoxMessage";
            this->textBoxMessage->Size = System::Drawing::Size(200, 20);
            this->textBoxMessage->TabIndex = 0;
            // 
            // buttonSend
            // 
            this->buttonSend->Location = System::Drawing::Point(339, 236);
            this->buttonSend->Name = L"buttonSend";
            this->buttonSend->Size = System::Drawing::Size(75, 20);
            this->buttonSend->TabIndex = 1;
            this->buttonSend->Text = L"Send";
            this->buttonSend->UseVisualStyleBackColor = true;
            this->buttonSend->Click += gcnew System::EventHandler(this, &ClientForm::buttonSend_Click);
            // 
            // richTextBoxChat
            // 
            this->richTextBoxChat->Location = System::Drawing::Point(133, 24);
            this->richTextBoxChat->Name = L"richTextBoxChat";
            this->richTextBoxChat->ReadOnly = true;
            this->richTextBoxChat->Size = System::Drawing::Size(281, 209);
            this->richTextBoxChat->TabIndex = 2;
            this->richTextBoxChat->Text = L"";
            // 
            // comboBoxChat
            // 
            this->comboBoxChat->FormattingEnabled = true;
            this->comboBoxChat->Location = System::Drawing::Point(6, 49);
            this->comboBoxChat->Name = L"comboBoxChat";
            this->comboBoxChat->Size = System::Drawing::Size(121, 21);
            this->comboBoxChat->TabIndex = 3;
            this->comboBoxChat->DropDown += gcnew System::EventHandler(this, &ClientForm::comboBoxChat_DropDown);
            this->comboBoxChat->SelectedIndexChanged += gcnew System::EventHandler(this, &ClientForm::comboBoxChat_SelectedIndexChanged);
            this->comboBoxChat->DropDownClosed += gcnew System::EventHandler(this, &ClientForm::comboBoxChat_DropDownClosed);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(31, 24);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(65, 13);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Выбор чата";
            // 
            // createChatButton
            // 
            this->createChatButton->Location = System::Drawing::Point(6, 236);
            this->createChatButton->Name = L"createChatButton";
            this->createChatButton->Size = System::Drawing::Size(117, 20);
            this->createChatButton->TabIndex = 6;
            this->createChatButton->Text = L"создать чат";
            this->createChatButton->UseVisualStyleBackColor = true;
            this->createChatButton->Click += gcnew System::EventHandler(this, &ClientForm::createChatButton_Click);
            // 
            // CurrentChat
            // 
            this->CurrentChat->AutoSize = true;
            this->CurrentChat->Location = System::Drawing::Point(133, 5);
            this->CurrentChat->Name = L"CurrentChat";
            this->CurrentChat->Size = System::Drawing::Size(0, 13);
            this->CurrentChat->TabIndex = 7;
            // 
            // ClientForm
            // 
            this->ClientSize = System::Drawing::Size(504, 350);
            this->Controls->Add(this->CurrentChat);
            this->Controls->Add(this->createChatButton);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->comboBoxChat);
            this->Controls->Add(this->textBoxMessage);
            this->Controls->Add(this->buttonSend);
            this->Controls->Add(this->richTextBoxChat);
            this->Name = L"ClientForm";
            this->Text = L"Socket Client";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        void FillChatList() {
            String^ condition = "";
            String^ value = comboBoxChat->Text;
            String^ getChatListRequest = "get_chat_list_request:" + value;
            array<Byte>^ data = Encoding::UTF8->GetBytes(getChatListRequest);

            try {
                // Подключение к серверу
                TcpClient^ client = gcnew TcpClient("127.0.0.1", 1234);
                NetworkStream^ stream = client->GetStream();

                // Отправка запроса на получение списка чатов
                stream->Write(data, 0, data->Length);

                // Получение ответа от сервера (списка чатов)
                array<Byte>^ responseBytes = gcnew array<Byte>(1024);
                int bytesRead = stream->Read(responseBytes, 0, responseBytes->Length);
                String^ chatList = Encoding::UTF8->GetString(responseBytes, 0, bytesRead);
                // Обработка списка чатов и добавление их в comboBoxChat

                    array<String^>^ chatNames = chatList->Split(',');

                    comboBoxChat->Items->Clear(); // Очистим текущие элементы в comboBoxChat

                    for each (String ^ chatName in chatNames) {
                        comboBoxChat->Items->Add(chatName->Trim()); // Добавим каждое имя чата в comboBoxChat
                    }
                

                // Закрытие подключения
                client->Close();
            }
            catch (Exception^ ex) {
                Console::WriteLine("Error: " + ex->Message);
                // Добавьте обработку ошибок при подключении к серверу или отправке данных
            }
        }


        System::Void buttonSend_Click(System::Object^ sender, System::EventArgs^ e)
        {
            
            try 
            {
                TcpClient^ client = gcnew TcpClient("127.0.0.1", 1234);
                NetworkStream^ stream = client->GetStream();
                if (stream != nullptr) {
                    
                    String^ message = "send_message_request:" + comboBoxChat->Text + ":" + Global::GlobalData::CurrentUser + ":" + textBoxMessage->Text;
                    array<Byte>^ messageBytes = Encoding::UTF8->GetBytes(message);
                    stream->Write(messageBytes, 0, messageBytes->Length);
                    stream->Flush();
                }
                else {
                    Console::WriteLine("Error: networkStream is null");
                }
            }
			catch (Exception^ ex) {
				Console::WriteLine("Error: " + ex->Message);
			}
            
            // Очистка TextBox после отправки сообщения
            textBoxMessage->Clear();
        }

        // Вставьте следующие строки для компонентов формы
    private:
        System::ComponentModel::IContainer^ components;
    private: System::Void comboBoxChat_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

    }
private: System::Void comboBoxChat_DropDown(System::Object^ sender, System::EventArgs^ e) {
    comboBoxChat->Items->Clear();
    FillChatList();
}
private: System::Void joinButton_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ selectedChat = comboBoxChat->Text;
}
private: System::Void createChatButton_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ newChatName = Interaction::InputBox("Enter chat name:", "Create Chat", "", -1, -1);
    if (newChatName != "") {
        // Подготовка данных для отправки на сервер
        String^ createChatRequest = "create_chat_request:" + newChatName;
        array<Byte>^ data = Encoding::UTF8->GetBytes(createChatRequest);

        try {
            // Подключение к серверу
            TcpClient^ client = gcnew TcpClient("127.0.0.1", 1234);
            NetworkStream^ stream = client->GetStream();

            // Отправка данных на сервер
            stream->Write(data, 0, data->Length);

            // Получение ответа от сервера (если необходимо)
            array<Byte>^ responseBytes = gcnew array<Byte>(1024);
            int bytesRead = stream->Read(responseBytes, 0, responseBytes->Length);
            String^ response = Encoding::UTF8->GetString(responseBytes, 0, bytesRead);

            // Обработка ответа (например, вы можете вывести его в консоль)
            Console::WriteLine("Server response: {0}", response);

            // Закрытие подключения
            client->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error: " + ex->Message);
            // Добавьте обработку ошибок при подключении к серверу или отправке данных
        }
    }
}
private: System::Void comboBoxChat_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
    CurrentChat->Text = "Чат " + comboBoxChat->Text;
}
};
}
