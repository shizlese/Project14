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
        System::Windows::Forms::ToolTip^ toolTip;
        System::Windows::Forms::TextBox^ textBoxMessage;
        System::Windows::Forms::Button^ buttonSend;
    private: System::Windows::Forms::ComboBox^ comboBoxChat;

    private: System::Windows::Forms::Label^ label1;

    private: System::Windows::Forms::Button^ createChatButton;

    private: System::Windows::Forms::Button^ updateChatButton;
    private: System::Windows::Forms::Button^ buttonSendFile;

    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
    private: System::Windows::Forms::GroupBox^ groupBoxChat;
    private: System::Windows::Forms::MenuStrip^ menuStrip1;
    private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
    private: System::Windows::Forms::ToolTip^ toolTip1;
    private: System::Windows::Forms::HelpProvider^ helpProvider1;
    private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItemHelp;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanelChat;






           void InitializeComponent()
           {
               this->components = (gcnew System::ComponentModel::Container());
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClientForm::typeid));
               this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
               this->buttonSend = (gcnew System::Windows::Forms::Button());
               this->comboBoxChat = (gcnew System::Windows::Forms::ComboBox());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->createChatButton = (gcnew System::Windows::Forms::Button());
               this->updateChatButton = (gcnew System::Windows::Forms::Button());
               this->buttonSendFile = (gcnew System::Windows::Forms::Button());
               this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->flowLayoutPanelChat = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->groupBoxChat = (gcnew System::Windows::Forms::GroupBox());
               this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
               this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
               this->toolStripMenuItemHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->groupBoxChat->SuspendLayout();
               this->menuStrip1->SuspendLayout();
               this->SuspendLayout();
               // 
               // textBoxMessage
               // 
               this->textBoxMessage->Location = System::Drawing::Point(150, 392);
               this->textBoxMessage->Name = L"textBoxMessage";
               this->textBoxMessage->Size = System::Drawing::Size(441, 20);
               this->textBoxMessage->TabIndex = 0;
               this->toolTip1->SetToolTip(this->textBoxMessage, L"Ввод сообщения");
               // 
               // buttonSend
               // 
               this->buttonSend->Location = System::Drawing::Point(632, 392);
               this->buttonSend->Name = L"buttonSend";
               this->buttonSend->Size = System::Drawing::Size(75, 20);
               this->buttonSend->TabIndex = 1;
               this->buttonSend->Text = L"Отправить";
               this->toolTip1->SetToolTip(this->buttonSend, L"Отправить сообщение");
               this->buttonSend->UseVisualStyleBackColor = true;
               this->buttonSend->Click += gcnew System::EventHandler(this, &ClientForm::buttonSend_Click);
               // 
               // comboBoxChat
               // 
               this->comboBoxChat->FormattingEnabled = true;
               this->comboBoxChat->Location = System::Drawing::Point(17, 73);
               this->comboBoxChat->Name = L"comboBoxChat";
               this->comboBoxChat->Size = System::Drawing::Size(121, 21);
               this->comboBoxChat->TabIndex = 3;
               this->toolTip1->SetToolTip(this->comboBoxChat, L"Выбрать чат \r\n Поиск происходит по введенному тексту \r\n Если текст пустой, то буд"
                   L"ет выполняться поиск всех чатов");
               this->comboBoxChat->DropDown += gcnew System::EventHandler(this, &ClientForm::comboBoxChat_DropDown);
               this->comboBoxChat->DropDownClosed += gcnew System::EventHandler(this, &ClientForm::comboBoxChat_DropDownClosed);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(44, 57);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(65, 13);
               this->label1->TabIndex = 4;
               this->label1->Text = L"Выбор чата";
               // 
               // createChatButton
               // 
               this->createChatButton->Location = System::Drawing::Point(17, 392);
               this->createChatButton->Name = L"createChatButton";
               this->createChatButton->Size = System::Drawing::Size(118, 20);
               this->createChatButton->TabIndex = 6;
               this->createChatButton->Text = L"создать чат";
               this->toolTip1->SetToolTip(this->createChatButton, L"Создать чат");
               this->createChatButton->UseVisualStyleBackColor = true;
               this->createChatButton->Click += gcnew System::EventHandler(this, &ClientForm::createChatButton_Click);
               // 
               // updateChatButton
               // 
               this->updateChatButton->Location = System::Drawing::Point(632, 29);
               this->updateChatButton->Name = L"updateChatButton";
               this->updateChatButton->Size = System::Drawing::Size(75, 22);
               this->updateChatButton->TabIndex = 8;
               this->updateChatButton->Text = L"обновить";
               this->toolTip1->SetToolTip(this->updateChatButton, L"Обновить чат");
               this->updateChatButton->UseVisualStyleBackColor = true;
               this->updateChatButton->Click += gcnew System::EventHandler(this, &ClientForm::updateChatButton_Click);
               // 
               // buttonSendFile
               // 
               this->buttonSendFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonSendFile.Image")));
               this->buttonSendFile->Location = System::Drawing::Point(597, 392);
               this->buttonSendFile->Name = L"buttonSendFile";
               this->buttonSendFile->Size = System::Drawing::Size(29, 20);
               this->buttonSendFile->TabIndex = 9;
               this->toolTip1->SetToolTip(this->buttonSendFile, L"Отправить файл");
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
               this->flowLayoutPanelChat->Dock = System::Windows::Forms::DockStyle::Fill;
               this->flowLayoutPanelChat->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
               this->flowLayoutPanelChat->Location = System::Drawing::Point(3, 16);
               this->flowLayoutPanelChat->Name = L"flowLayoutPanelChat";
               this->flowLayoutPanelChat->Size = System::Drawing::Size(551, 310);
               this->flowLayoutPanelChat->TabIndex = 10;
               // 
               // groupBoxChat
               // 
               this->groupBoxChat->Controls->Add(this->flowLayoutPanelChat);
               this->groupBoxChat->Location = System::Drawing::Point(150, 57);
               this->groupBoxChat->Name = L"groupBoxChat";
               this->groupBoxChat->Size = System::Drawing::Size(557, 329);
               this->groupBoxChat->TabIndex = 11;
               this->groupBoxChat->TabStop = false;
               this->groupBoxChat->Text = L"Чат";
               // 
               // menuStrip1
               // 
               this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                   this->exitToolStripMenuItem,
                       this->toolStripMenuItemHelp
               });
               this->menuStrip1->Location = System::Drawing::Point(0, 0);
               this->menuStrip1->Name = L"menuStrip1";
               this->menuStrip1->Size = System::Drawing::Size(731, 24);
               this->menuStrip1->TabIndex = 12;
               this->menuStrip1->Text = L"menuStripChat";
               // 
               // exitToolStripMenuItem
               // 
               this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
               this->exitToolStripMenuItem->Size = System::Drawing::Size(54, 20);
               this->exitToolStripMenuItem->Text = L"Выйти";
               this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &ClientForm::exitToolStripMenuItem_Click);
               // 
               // toolTip1
               // 
               // 
               // toolStripMenuItemHelp
               // 
               this->toolStripMenuItemHelp->Name = L"toolStripMenuItemHelp";
               this->toolStripMenuItemHelp->Size = System::Drawing::Size(65, 20);
               this->toolStripMenuItemHelp->Text = L"Справка";
               this->toolStripMenuItemHelp->Click += gcnew System::EventHandler(this, &ClientForm::toolStripMenuItemHelp_Click);
               // 
               // ClientForm
               // 
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
               this->ClientSize = System::Drawing::Size(731, 433);
               this->Controls->Add(this->groupBoxChat);
               this->Controls->Add(this->buttonSendFile);
               this->Controls->Add(this->updateChatButton);
               this->Controls->Add(this->createChatButton);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->comboBoxChat);
               this->Controls->Add(this->textBoxMessage);
               this->Controls->Add(this->buttonSend);
               this->Controls->Add(this->menuStrip1);
               this->MainMenuStrip = this->menuStrip1;
               this->MaximumSize = System::Drawing::Size(747, 472);
               this->MinimumSize = System::Drawing::Size(747, 472);
               this->Name = L"ClientForm";
               this->Text = L"Чат";
               this->groupBoxChat->ResumeLayout(false);
               this->menuStrip1->ResumeLayout(false);
               this->menuStrip1->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();
               //helpprovider
               //
               //
               this->helpProvider1->SetHelpNavigator(this, System::Windows::Forms::HelpNavigator::Topic);
               this->helpProvider1->SetHelpString(this, "ClientForm");

               // Добавьте справочную систему (HTML-файл) к вашему проекту
               // Убедитесь, что файл справки имеет имя "ClientFormHelp.html" и находится в папке проекта
               // Замените путь на фактический путь к файлу справки
               String^ helpFilePath = System::IO::Path::Combine(Application::StartupPath, "ClientFormHelp.html");
               this->helpProvider1->SetShowHelp(this, true);
               this->helpProvider1->HelpNamespace = helpFilePath;
           }
           TcpClient^ CreateClient() {
               // Создание TCP-клиента для подключения к серверу
               return gcnew TcpClient("127.0.0.1", 1234);
           }

           //flow

           // Функция для добавления текстового сообщения в чат
           void AddMessageToChat(String^ message) {
               Label^ messageLabel = gcnew Label();
               messageLabel->Text = message;
               messageLabel->AutoSize = true;
               messageLabel->Height = 30;
               messageLabel->Margin = System::Windows::Forms::Padding(0, 5, 0, 5);
               this->flowLayoutPanelChat->Controls->Add(messageLabel);
           }

           // Функция для добавления кнопки с файлом в чат
           void AddFileToChat(String^ fileName) {
               Button^ fileButton = gcnew Button();
               fileButton->Text = fileName;
               fileButton->AutoSize = true;
               fileButton->Height = 30;
               fileButton->Margin = System::Windows::Forms::Padding(0, 5, 0, 5);
               fileButton->Click += gcnew System::EventHandler(this, &ClientForm::OnFileButtonClick);
               this->flowLayoutPanelChat->Controls->Add(fileButton);
           }

           // Обработчик события нажатия на кнопку с файлом в чате
private: System::Void OnFileButtonClick(System::Object^ sender, System::EventArgs^ e) {
    // Извлекаем информацию о файле из текста кнопки
    Button^ fileButton = safe_cast<Button^>(sender);
    String^ fileInfo = fileButton->Text;
    array<String^>^ parts = fileInfo->Split(':');
    if (parts->Length >= 2) {
        String^ fileName = parts[3]->Trim();
        RequestFileDownload(fileName, comboBoxChat->Text);
    }
}

           //flow<-

           // Функция для отправки запроса на сервер и получения ответа
       String^ SendRequestAndGetResponse(String^ request) {
           try {
               TcpClient^ client = CreateClient();
               NetworkStream^ stream = client->GetStream();

               // Отправляем запрос на сервер
               array<Byte>^ data = Encoding::UTF8->GetBytes(request);
               stream->Write(data, 0, data->Length);

               // Получаем ответ от сервера
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

       // Функция для обновления списка чатов из ответа сервера
       void FillChatList() {
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
           // Функция для отправки файла на сервер
       void SendFile(array<Byte>^ requestBytes) {
           try {
               TcpClient^ client = CreateClient();
               NetworkStream^ stream = client->GetStream();

               // Отправляем массив байтов запроса
               stream->Write(requestBytes, 0, requestBytes->Length);
               stream->Flush();

               // Получаем ответ от сервера
               array<Byte>^ responseBytes = gcnew array<Byte>(1024);
               int bytesRead = stream->Read(responseBytes, 0, responseBytes->Length);
               String^ response = Encoding::UTF8->GetString(responseBytes, 0, bytesRead);
               Console::WriteLine("Server response: " + response);

               // Закрываем соединение
               client->Close();
           }
           catch (Exception^ ex) {
               Console::WriteLine("Error: " + ex->Message);
           }
       }
       // Обработчик события нажатия на кнопку "Отправить сообщение"
       System::Void buttonSend_Click(System::Object^ sender, System::EventArgs^ e)
       {
           // Формируем и отправляем запрос на отправку сообщения
           String^ message = "send_message_request:" + comboBoxChat->Text + ":" + Global::GlobalData::CurrentUser + ":" + textBoxMessage->Text;
           SendRequestAndGetResponse(message);
           textBoxMessage->Clear();
       }
       // Функция для приема данных файла с сервера
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


       // Функция для запроса скачивания файла с сервера
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
        array<Byte>^ fileInfoBytes = gcnew array<Byte>(1024); // Максимальная длина информации о файле
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


       // Функция для сохранения файла локально
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
        // Обработчик события раскрытия выпадающего списка чатов
private: System::Void comboBoxChat_DropDown(System::Object^ sender, System::EventArgs^ e) {
    // Обновление списка чатов при раскрытии выпадающего списка
    comboBoxChat->Items->Clear();
    FillChatList();
}
       // Обработчик события нажатия на кнопку создания нового чата
private: System::Void createChatButton_Click(System::Object^ sender, System::EventArgs^ e) {
    // Создание нового чата
    String^ newChatName = Interaction::InputBox("Enter chat name:", "Create Chat", "", -1, -1);
    if (newChatName != "") {
        String^ createChatRequest = "create_chat_request:" + newChatName;
        String^ response = SendRequestAndGetResponse(createChatRequest);
        Console::WriteLine("Server response: {0}", response);
    }
}
       // Обработчик события закрытия выпадающего списка чатов
private: System::Void comboBoxChat_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
    // Обновление текста текущего чата после закрытия выпадающего списка
    groupBoxChat->Text = "Чат " + comboBoxChat->SelectedText;
}

       // Обработчик события нажатия на кнопку обновления чата
private: System::Void updateChatButton_Click(System::Object^ sender, System::EventArgs^ e) {
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
}
       // Обработчик события нажатия на кнопку отправки файла
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
       // Обработчик события нажатия на кнопку выхода из приложения
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    Application::Exit();
}
       // Обработчик события нажатия на пункт меню "Справка"
private: System::Void toolStripMenuItemHelp_Click(System::Object^ sender, System::EventArgs^ e) {
    // Отображение справки или помощи
    System::Windows::Forms::Help::ShowHelp(this, helpProvider1->HelpNamespace, System::Windows::Forms::HelpNavigator::Topic, "ClientForm");
}
};
}
