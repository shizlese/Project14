#pragma once
#include "ClientForm.cpp"
#include "Global.h"
namespace Project14 {
    using namespace System;
    using namespace System::Net;
    using namespace System::Net::Sockets;
    using namespace System::Text;
    using namespace Microsoft::VisualBasic;
    using namespace Global;
    public ref class ClientForm : public System::Windows::Forms::Form
    {
    public:
        ClientForm()
        {
            InitializeComponent();
            
            client = gcnew TcpClient("127.0.0.1", 1234);
            stream = client->GetStream();

            if (client == nullptr || stream == nullptr)
            {
                // ��������� ������ �������������
                System::Windows::Forms::MessageBox::Show("Failed to initialize the client or stream.");
                // ��������� ������ ����� ��� ��������� ������ ���� �� ��������� ������
            }
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
    private: System::Windows::Forms::ComboBox^ comboBoxChat;

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ joinChatButton;
    private: System::Windows::Forms::Button^ createChatButton;


           System::Windows::Forms::RichTextBox^ richTextBoxChat;

        void InitializeComponent()
        {
            this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
            this->buttonSend = (gcnew System::Windows::Forms::Button());
            this->richTextBoxChat = (gcnew System::Windows::Forms::RichTextBox());
            this->comboBoxChat = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->joinChatButton = (gcnew System::Windows::Forms::Button());
            this->createChatButton = (gcnew System::Windows::Forms::Button());
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
            this->comboBoxChat->Location = System::Drawing::Point(6, 24);
            this->comboBoxChat->Name = L"comboBoxChat";
            this->comboBoxChat->Size = System::Drawing::Size(121, 21);
            this->comboBoxChat->TabIndex = 3;
            this->comboBoxChat->DropDown += gcnew System::EventHandler(this, &ClientForm::comboBoxChat_DropDown);
            this->comboBoxChat->SelectedIndexChanged += gcnew System::EventHandler(this, &ClientForm::comboBoxChat_SelectedIndexChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(7, 5);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(65, 13);
            this->label1->TabIndex = 4;
            this->label1->Text = L"����� ����";
            // 
            // joinChatButton
            // 
            this->joinChatButton->Location = System::Drawing::Point(6, 213);
            this->joinChatButton->Name = L"joinChatButton";
            this->joinChatButton->Size = System::Drawing::Size(117, 20);
            this->joinChatButton->TabIndex = 5;
            this->joinChatButton->Text = L"��������������";
            this->joinChatButton->UseVisualStyleBackColor = true;
            this->joinChatButton->Click += gcnew System::EventHandler(this, &ClientForm::joinButton_Click);
            // 
            // createChatButton
            // 
            this->createChatButton->Location = System::Drawing::Point(6, 236);
            this->createChatButton->Name = L"createChatButton";
            this->createChatButton->Size = System::Drawing::Size(117, 20);
            this->createChatButton->TabIndex = 6;
            this->createChatButton->Text = L"������� ���";
            this->createChatButton->UseVisualStyleBackColor = true;
            this->createChatButton->Click += gcnew System::EventHandler(this, &ClientForm::createChatButton_Click);
            // 
            // ClientForm
            // 
            this->ClientSize = System::Drawing::Size(504, 350);
            this->Controls->Add(this->createChatButton);
            this->Controls->Add(this->joinChatButton);
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
        public:
            String^ currentUser = GlobalData::CurrentUser;
            delegate void UpdateChatBoxDelegate(String^ message);
            delegate void DisplayMessageDelegate(String^ sender, String^ message, bool isCurrentClient);

            

        void UpdateChatBox(String^ message) {
            // ��������� �������� ���������� ���������� � ������� ������
            if (richTextBoxChat->InvokeRequired) {
                Invoke(gcnew UpdateChatBoxDelegate(this, &ClientForm::UpdateChatBox), message);
            }
            else {
                richTextBoxChat->AppendText(message + "\n");
            }
        }

        void DisplayMessage(String^ sender, String^ message, bool isCurrentClient) {
            String^ formattedMessage;

            // �������������� ��������� � ������ ������������
            if (isCurrentClient) {
                formattedMessage = String::Format("[You] {0} ({1}): {2}", sender, DateTime::Now.ToString("HH:mm:ss"), message);
            }
            else {
                formattedMessage = String::Format("[{0}] {1} ({2}): {3}", sender, DateTime::Now.ToString("HH:mm:ss"), message);
            }

            // ���������� ��������� � richTextBoxChat � ������ ������������
            if (richTextBoxChat->InvokeRequired) {
                DisplayMessageDelegate^ displayDelegate = gcnew DisplayMessageDelegate(this, &ClientForm::DisplayMessage);
                BeginInvoke(displayDelegate, sender, message, isCurrentClient);
            }
            else {
                richTextBoxChat->AppendText(formattedMessage + "\n");
            }
        }
        void FillChatList() {
            String^ condition = "";
            String^ value = comboBoxChat->Text;
            String^ getChatListRequest = "get_chat_list_request:" + value;
            array<Byte>^ data = Encoding::UTF8->GetBytes(getChatListRequest);

            try {
                // ����������� � �������
                TcpClient^ client = gcnew TcpClient("127.0.0.1", 1234);
                NetworkStream^ stream = client->GetStream();

                // �������� ������� �� ��������� ������ �����
                stream->Write(data, 0, data->Length);

                // ��������� ������ �� ������� (������ �����)
                array<Byte>^ responseBytes = gcnew array<Byte>(1024);
                int bytesRead = stream->Read(responseBytes, 0, responseBytes->Length);
                String^ chatList = Encoding::UTF8->GetString(responseBytes, 0, bytesRead);
                // ��������� ������ ����� � ���������� �� � comboBoxChat

                    array<String^>^ chatNames = chatList->Split(',');

                    comboBoxChat->Items->Clear(); // ������� ������� �������� � comboBoxChat

                    for each (String ^ chatName in chatNames) {
                        comboBoxChat->Items->Add(chatName->Trim()); // ������� ������ ��� ���� � comboBoxChat
                    }
                

                // �������� �����������
                client->Close();
            }
            catch (Exception^ ex) {
                Console::WriteLine("Error: " + ex->Message);
                // �������� ��������� ������ ��� ����������� � ������� ��� �������� ������
            }
        }


        System::Void buttonSend_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ message = textBoxMessage->Text;
            array<Byte>^ data = Encoding::UTF8->GetBytes(message);
            stream->Write(data, 0, data->Length);
            DisplayMessage(currentUser, message, true);
            // �������� ����� ��� ��� ��������� ����������� ������ �� ������� (���� ����������)
            textBoxMessage->Clear();
           
        }

        // �������� ��������� ������ ��� ����������� �����
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
        // ���������� ������ ��� �������� �� ������
        String^ createChatRequest = "create_chat_request:" + newChatName;
        array<Byte>^ data = Encoding::UTF8->GetBytes(createChatRequest);

        try {
            // ����������� � �������
            TcpClient^ client = gcnew TcpClient("127.0.0.1", 1234);
            NetworkStream^ stream = client->GetStream();

            // �������� ������ �� ������
            stream->Write(data, 0, data->Length);

            // ��������� ������ �� ������� (���� ����������)
            array<Byte>^ responseBytes = gcnew array<Byte>(1024);
            int bytesRead = stream->Read(responseBytes, 0, responseBytes->Length);
            String^ response = Encoding::UTF8->GetString(responseBytes, 0, bytesRead);

            // ��������� ������ (��������, �� ������ ������� ��� � �������)
            Console::WriteLine("Server response: {0}", response);

            // �������� �����������
            client->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error: " + ex->Message);
            // �������� ��������� ������ ��� ����������� � ������� ��� �������� ������
        }
    }
}
};
}
