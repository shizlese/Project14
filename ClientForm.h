#pragma once
#include "ClientForm.cpp"
#include "Global.h"

namespace Project14 {
    using namespace System;
    using namespace System::Net;
    using namespace System::Net::Sockets;
    using namespace System::Text;
    using namespace Microsoft::VisualBasic;
    using namespace System::Threading::Tasks;
    using namespace System::Windows::Forms;
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
    private: System::Windows::Forms::Button^ updateChatButton;
    private: System::Windows::Forms::Button^ buttonSendFile;

    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanelChat;






           void InitializeComponent()
           {
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClientForm::typeid));
               this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
               this->buttonSend = (gcnew System::Windows::Forms::Button());
               this->comboBoxChat = (gcnew System::Windows::Forms::ComboBox());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->createChatButton = (gcnew System::Windows::Forms::Button());
               this->CurrentChat = (gcnew System::Windows::Forms::Label());
               this->updateChatButton = (gcnew System::Windows::Forms::Button());
               this->buttonSendFile = (gcnew System::Windows::Forms::Button());
               this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->flowLayoutPanelChat = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->SuspendLayout();
               // 
               // textBoxMessage
               // 
               this->textBoxMessage->Location = System::Drawing::Point(135, 241);
               this->textBoxMessage->Name = L"textBoxMessage";
               this->textBoxMessage->Size = System::Drawing::Size(331, 20);
               this->textBoxMessage->TabIndex = 0;
               // 
               // buttonSend
               // 
               this->buttonSend->Location = System::Drawing::Point(507, 241);
               this->buttonSend->Name = L"buttonSend";
               this->buttonSend->Size = System::Drawing::Size(75, 20);
               this->buttonSend->TabIndex = 1;
               this->buttonSend->Text = L"Отправить";
               this->buttonSend->UseVisualStyleBackColor = true;
               this->buttonSend->Click += gcnew System::EventHandler(this, &ClientForm::buttonSend_Click);
               // 
               // comboBoxChat
               // 
               this->comboBoxChat->FormattingEnabled = true;
               this->comboBoxChat->Location = System::Drawing::Point(5, 27);
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
               this->label1->Location = System::Drawing::Point(34, 11);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(65, 13);
               this->label1->TabIndex = 4;
               this->label1->Text = L"Выбор чата";
               // 
               // createChatButton
               // 
               this->createChatButton->Location = System::Drawing::Point(5, 242);
               this->createChatButton->Name = L"createChatButton";
               this->createChatButton->Size = System::Drawing::Size(121, 20);
               this->createChatButton->TabIndex = 6;
               this->createChatButton->Text = L"создать чат";
               this->createChatButton->UseVisualStyleBackColor = true;
               this->createChatButton->Click += gcnew System::EventHandler(this, &ClientForm::createChatButton_Click);
               // 
               // CurrentChat
               // 
               this->CurrentChat->AutoSize = true;
               this->CurrentChat->Location = System::Drawing::Point(132, 11);
               this->CurrentChat->Name = L"CurrentChat";
               this->CurrentChat->Size = System::Drawing::Size(0, 13);
               this->CurrentChat->TabIndex = 7;
               // 
               // updateChatButton
               // 
               this->updateChatButton->Location = System::Drawing::Point(507, 2);
               this->updateChatButton->Name = L"updateChatButton";
               this->updateChatButton->Size = System::Drawing::Size(75, 22);
               this->updateChatButton->TabIndex = 8;
               this->updateChatButton->Text = L"обновить";
               this->updateChatButton->UseVisualStyleBackColor = true;
               this->updateChatButton->Click += gcnew System::EventHandler(this, &ClientForm::updateChatButton_Click);
               // 
               // buttonSendFile
               // 
               this->buttonSendFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonSendFile.Image")));
               this->buttonSendFile->Location = System::Drawing::Point(472, 242);
               this->buttonSendFile->Name = L"buttonSendFile";
               this->buttonSendFile->Size = System::Drawing::Size(29, 20);
               this->buttonSendFile->TabIndex = 9;
               this->buttonSendFile->UseVisualStyleBackColor = true;
               this->buttonSendFile->Click += gcnew System::EventHandler(this, &ClientForm::buttonSendFile_Click);
               // 
               // openFileDialog1
               // 
               this->openFileDialog1->FileName = L"openFileDialog1";
               // 
               // flowLayoutPanelChat
               // 
               this->flowLayoutPanelChat->AutoScroll = true;
               this->flowLayoutPanelChat->Location = System::Drawing::Point(135, 27);
               this->flowLayoutPanelChat->Name = L"flowLayoutPanelChat";
               this->flowLayoutPanelChat->Size = System::Drawing::Size(447, 209);
               this->flowLayoutPanelChat->TabIndex = 10;
               // 
               // ClientForm
               // 
               this->ClientSize = System::Drawing::Size(622, 305);
               this->Controls->Add(this->flowLayoutPanelChat);
               this->Controls->Add(this->buttonSendFile);
               this->Controls->Add(this->updateChatButton);
               this->Controls->Add(this->CurrentChat);
               this->Controls->Add(this->createChatButton);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->comboBoxChat);
               this->Controls->Add(this->textBoxMessage);
               this->Controls->Add(this->buttonSend);
               this->Name = L"ClientForm";
               this->Text = L"Чат";
               this->ResumeLayout(false);
               this->PerformLayout();

           }
           TcpClient^ CreateClient() {
               // Создание TCP-клиента для подключения к серверу
               return gcnew TcpClient("127.0.0.1", 1234);
           }

           //flow

           void AddMessageToChat(String^ message) {
               Label^ messageLabel = gcnew Label();
               messageLabel->Text = message;
               messageLabel->AutoSize = true;
               this->flowLayoutPanelChat->Controls->Add(messageLabel);
           }

           void AddFileToChat(String^ fileName) {
               Button^ fileButton = gcnew Button();
               fileButton->Text = fileName;
               fileButton->AutoSize = true;
               fileButton->Click += gcnew System::EventHandler(this, &ClientForm::OnFileButtonClick);
               this->flowLayoutPanelChat->Controls->Add(fileButton);
           }

    private: System::Void OnFileButtonClick(System::Object^ sender, System::EventArgs^ e) {
        Button^ fileButton = safe_cast<Button^>(sender);
        String^ fileInfo = fileButton->Text;
        // Извлекаем имя файла из текста кнопки
        // Пример: "User отправил файл: filename.txt"
        array<String^>^ parts = fileInfo->Split(':');
        if (parts->Length >= 2) {
            String^ fileName = parts[3]->Trim();
            RequestFileDownload(fileName, comboBoxChat->Text);
        }
    }

           //flow<-

           String^ SendRequestAndGetResponse(String^ request) {
               // Отправка запроса серверу и получение ответа
               try {
                   TcpClient^ client = CreateClient();
                   NetworkStream^ stream = client->GetStream();

                   array<Byte>^ data = Encoding::UTF8->GetBytes(request);
                   stream->Write(data, 0, data->Length);

                   array<Byte>^ responseData = gcnew array<Byte>(1024);
                   int bytesRead = stream->Read(responseData, 0, responseData->Length);
                   String^ response = Encoding::UTF8->GetString(responseData, 0, bytesRead);

                   client->Close();
                   return response;
               }
               catch (Exception^ ex) {
                   Console::WriteLine("Error: " + ex->Message);
                   return "";
               }
           }

           void FillChatList() {
               // Заполнение списка чатов из ответа сервера
               String^ getChatListRequest = "get_chat_list_request:" + comboBoxChat->Text;
               String^ chatList = SendRequestAndGetResponse(getChatListRequest);

               if (!String::IsNullOrEmpty(chatList)) {
                   array<String^>^ chatNames = chatList->Split(',');

                   comboBoxChat->Items->Clear();

                   for each (String ^ chatName in chatNames) {
                       comboBoxChat->Items->Add(chatName->Trim());
                   }
               }
           }
           //sendfile
           void SendFile(array<Byte>^ requestBytes) {
               try {
                   TcpClient^ client = CreateClient();
                   NetworkStream^ stream = client->GetStream();

                   // Отправка массива байтов запроса
                   stream->Write(requestBytes, 0, requestBytes->Length);
                   stream->Flush();

                   // Получение ответа от сервера
                   array<Byte>^ responseBytes = gcnew array<Byte>(1024);
                   int bytesRead = stream->Read(responseBytes, 0, responseBytes->Length);
                   String^ response = Encoding::UTF8->GetString(responseBytes, 0, bytesRead);
                   Console::WriteLine("Server response: " + response);

                   // Закрытие соединения
                   client->Close();
               }
               catch (Exception^ ex) {
                   Console::WriteLine("Error: " + ex->Message);
               }
           }
           System::Void buttonSend_Click(System::Object^ sender, System::EventArgs^ e)
           {
               // Обработка нажатия на кнопку "Отправить"
               String^ message = "send_message_request:" + comboBoxChat->Text + ":" + Global::GlobalData::CurrentUser + ":" + textBoxMessage->Text;
               SendRequestAndGetResponse(message);
               textBoxMessage->Clear();
           }
    private: array<Byte>^ ReceiveFileData(TcpClient^ client, int fileSize) {
        NetworkStream^ stream = client->GetStream();
        array<Byte>^ fileData = gcnew array<Byte>(fileSize);
        int totalBytesRead = 0;

        while (totalBytesRead < fileSize) {
            int bufferLength = Math::Min(1024, fileSize - totalBytesRead);
            array<Byte>^ buffer = gcnew array<Byte>(bufferLength);
            int bytesRead = stream->Read(buffer, 0, bufferLength);
            if (bytesRead == 0) {
                throw gcnew ApplicationException("The file stream was closed unexpectedly.");
            }
            Array::Copy(buffer, 0, fileData, totalBytesRead, bytesRead);
            totalBytesRead += bytesRead;
        }

        return fileData;
    }


    private: System::Void RequestFileDownload(String^ fileName, String^ chatname) {
        TcpClient^ client = CreateClient();
        try {
            String^ request = String::Format("get_file_request:{0}:{1}", fileName, chatname);

            NetworkStream^ stream = client->GetStream();

            // Отправка запроса на сервер
            array<Byte>^ requestBytes = Encoding::UTF8->GetBytes(request);
            stream->Write(requestBytes, 0, requestBytes->Length);
            stream->Flush();

            // Ожидание информации о файле от сервера
            array<Byte>^ fileInfoBytes = gcnew array<Byte>(1024); // Здесь предполагается максимальная длина информации о файле
            int bytesRead = stream->Read(fileInfoBytes, 0, fileInfoBytes->Length);
            String^ fileInfo = Encoding::UTF8->GetString(fileInfoBytes, 0, bytesRead);

            // Разбор информации о файле
            array<String^>^ fileInfoParts = fileInfo->Split(':');
            if (fileInfoParts->Length == 2) {
                String^ receivedFileName = fileInfoParts[0];
                int fileSize = Int32::Parse(fileInfoParts[1]);

                // Проверка размера файла перед загрузкой (не более 20 МБ)
                if (fileSize <= 20 * 1024 * 1024) { // 20 МБ в байтах
                    // Создание буфера для данных файла
                    array<Byte>^ fileData = gcnew array<Byte>(fileSize);

                    // Чтение данных файла в буфер
                    int totalBytesReceived = 0;
                    while (totalBytesReceived < fileSize) {
                        int bytesReceived = stream->Read(fileData, totalBytesReceived, fileSize - totalBytesReceived);
                        if (bytesReceived <= 0) {
                            Console::WriteLine("Error: No data received from the server.");
                            break;
                        }
                        totalBytesReceived += bytesReceived;
                        Console::WriteLine("Received {0} bytes out of {1} bytes.", totalBytesReceived, fileSize);
                    }

                    // Сохранение файла локально
                    SaveFileLocally(receivedFileName, fileData, fileSize);
                    Console::WriteLine("File downloaded successfully. Size: {0} bytes.", fileSize);
                }
                else {
                    Console::WriteLine("File size exceeds the limit (20 MB).");
                }
            }
            else {
                Console::WriteLine("Invalid file information format received from the server.");
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error during file download: " + ex->Message);
        }
        finally {
            client->Close();
        }
    }







    private: System::Void SaveFileLocally(String^ fileName, array<Byte>^ fileData, int fileSize) {
        SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
        saveFileDialog->FileName = fileName;
        if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ filePath = saveFileDialog->FileName;
            // Сохраняем только первые fileSize байтов из массива fileData
            array<Byte>^ trimmedFileData = gcnew array<Byte>(fileSize);
            Array::Copy(fileData, trimmedFileData, fileSize);
            System::IO::File::WriteAllBytes(filePath, trimmedFileData);
            Console::WriteLine("File '{0}' saved locally at '{1}'.", fileName, filePath);
        }
        else {
            Console::WriteLine("File save operation cancelled by user.");
        }
    }






    private:
        System::ComponentModel::IContainer^ components;
    private: System::Void comboBoxChat_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

    }
           System::Void comboBoxChat_DropDown(System::Object^ sender, System::EventArgs^ e) {
               // Обновление списка чатов при раскрытии выпадающего списка
               comboBoxChat->Items->Clear();
               FillChatList();
           }
           System::Void createChatButton_Click(System::Object^ sender, System::EventArgs^ e) {
               // Создание нового чата
               String^ newChatName = Interaction::InputBox("Enter chat name:", "Create Chat", "", -1, -1);
               if (newChatName != "") {
                   String^ createChatRequest = "create_chat_request:" + newChatName;
                   String^ response = SendRequestAndGetResponse(createChatRequest);
                   Console::WriteLine("Server response: {0}", response);
               }
           }
           System::Void comboBoxChat_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
               // Обновление текста текущего чата после закрытия выпадающего списка
               CurrentChat->Text = "Чат " + comboBoxChat->SelectedText;
           }
           System::Void updateChatButton_Click(System::Object^ sender, System::EventArgs^ e) {
               // Обновление истории чата
               flowLayoutPanelChat->Controls->Clear();

               String^ getMessageListRequest = "get_chat_history_request:" + comboBoxChat->Text + ":" + Global::GlobalData::CurrentUser;
               String^ response = SendRequestAndGetResponse(getMessageListRequest);

               if (!String::IsNullOrEmpty(response)) {
                   array<String^>^ messages = response->Split('\n');
                   for each (String ^ message in messages) {
                       if (String::IsNullOrEmpty(message)) continue;

                       array<String^>^ parts = message->Split(':');
                       if (parts->Length < 3) continue;

                       String^ messageType = parts[0];
                       String^ senderName = parts[1];
                       String^ content = String::Join(":", parts, 2, parts->Length - 2);

                       if (messageType == "message") {
                           // Создаем Label для текстового сообщения
                           Label^ messageLabel = gcnew Label();
                           messageLabel->Text = String::Format("{0}: {1}", senderName, content);
                           messageLabel->AutoSize = true;
                           flowLayoutPanelChat->Controls->Add(messageLabel);
                       }
                       else if (messageType == "file") {
                           // Создаем Button для файла
                           Button^ fileButton = gcnew Button();
                           fileButton->Text = String::Format("{0} отправил файл: {1}", senderName, content);
                           fileButton->AutoSize = true;
                           fileButton->Click += gcnew System::EventHandler(this, &ClientForm::OnFileButtonClick);
                           flowLayoutPanelChat->Controls->Add(fileButton);
                       }
                   }
               }
    };
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

    }
private: System::Void buttonSendFile_Click(System::Object^ sender, System::EventArgs^ e) {
    if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        String^ filePath = this->openFileDialog1->FileName;
        String^ chatName = this->comboBoxChat->Text;
        String^ username = Global::GlobalData::CurrentUser; // Замените на реальный способ получения идентификатора пользователя
        String^ fileName = System::IO::Path::GetFileName(filePath);

        // Чтение файла в массив байтов
        array<Byte>^ fileData = System::IO::File::ReadAllBytes(filePath);

        // Создание запроса на отправку файла
        String^ requestHeader = String::Format("send_file_request:{0}:{1}:{2}:", chatName, username, fileName);
        array<Byte>^ headerBytes = Encoding::UTF8->GetBytes(requestHeader);
        array<Byte>^ requestBytes = gcnew array<Byte>(headerBytes->Length + fileData->Length);

        // Копирование заголовка и данных файла в один массив байтов
        Array::Copy(headerBytes, requestBytes, headerBytes->Length);
        Array::Copy(fileData, 0, requestBytes, headerBytes->Length, fileData->Length);

        // Отправка запроса и файла на сервер
        SendFile(requestBytes);
    }
}
       
       

private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}


};
}
