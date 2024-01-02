#pragma once
#include "ClientForm.cpp"
namespace Project14 {

    using namespace System;
    using namespace System::Net;
    using namespace System::Net::Sockets;
    using namespace System::Text;

    public ref class ClientForm : public System::Windows::Forms::Form
    {
    public:
        ClientForm()
        {
            InitializeComponent();
            client = gcnew TcpClient("127.0.0.1", 1234);
            stream = client->GetStream();
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
        TcpClient^ client;
        NetworkStream^ stream;

        System::Windows::Forms::TextBox^ textBoxMessage;
        System::Windows::Forms::Button^ buttonSend;
        System::Windows::Forms::RichTextBox^ richTextBoxChat;

        void InitializeComponent()
        {
            this->components = gcnew System::ComponentModel::Container();
            this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
            this->buttonSend = (gcnew System::Windows::Forms::Button());
            this->richTextBoxChat = (gcnew System::Windows::Forms::RichTextBox());

            this->SuspendLayout();

            // textBoxMessage
            this->textBoxMessage->Location = System::Drawing::Point(12, 12);
            this->textBoxMessage->Name = L"textBoxMessage";
            this->textBoxMessage->Size = System::Drawing::Size(200, 20);
            this->textBoxMessage->TabIndex = 0;

            // buttonSend
            this->buttonSend->Location = System::Drawing::Point(218, 10);
            this->buttonSend->Name = L"buttonSend";
            this->buttonSend->Size = System::Drawing::Size(75, 23);
            this->buttonSend->TabIndex = 1;
            this->buttonSend->Text = L"Send";
            this->buttonSend->UseVisualStyleBackColor = true;
            this->buttonSend->Click += gcnew System::EventHandler(this, &ClientForm::buttonSend_Click);

            // richTextBoxChat
            this->richTextBoxChat->Location = System::Drawing::Point(12, 41);
            this->richTextBoxChat->Name = L"richTextBoxChat";
            this->richTextBoxChat->Size = System::Drawing::Size(280, 209);
            this->richTextBoxChat->TabIndex = 2;
            this->richTextBoxChat->Text = L"";
            this->richTextBoxChat->ReadOnly = true;

            // ClientForm
            this->ClientSize = System::Drawing::Size(304, 261);
            this->Controls->Add(this->textBoxMessage);
            this->Controls->Add(this->buttonSend);
            this->Controls->Add(this->richTextBoxChat);
            this->Name = L"ClientForm";
            this->Text = L"Socket Client";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        System::Void buttonSend_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ message = textBoxMessage->Text;
            array<Byte>^ data = Encoding::UTF8->GetBytes(message);
            stream->Write(data, 0, data->Length);

            // Добавьте здесь код для обработки полученного ответа от сервера (если необходимо)

            textBoxMessage->Text = "";
        }

        // Вставьте следующие строки для компонентов формы
    private:
        System::ComponentModel::IContainer^ components;
    };
}
