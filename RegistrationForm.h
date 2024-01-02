#pragma once

namespace Project14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� RegistrationForm
	/// </summary>
	public ref class RegistrationForm : public System::Windows::Forms::Form
	{
	public:
		RegistrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
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

        // �������� ����� ������ ���������� �����, ���� ��� ����

        System::ComponentModel::Container^ components;  // ����������� ���������� components

        void InitializeComponent()
        {
            // ������������� ����������� �����
            this->components = gcnew System::ComponentModel::Container();
            this->textBoxNewUsername = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNewPassword = (gcnew System::Windows::Forms::TextBox());
            this->buttonCreateAccount = (gcnew System::Windows::Forms::Button());

            // ��������� ��� ��� ������������� �����������

            this->SuspendLayout();

            // ��������� ��� ��� ���������� ����������� �� �����
        }

        System::Void buttonCreateAccount_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // �������� ��������� ������������� ����� � ������ ��� ����� ������� ������
            String^ newUsername = textBoxNewUsername->Text;
            String^ newPassword = textBoxNewPassword->Text;

            // �������� ����� ��� ��� �������� ����� ������� ������
            // ��������, ��������� SQL-������ ��� ���������� ������ ������������ � ���� ������
            // ��� ��������� ������� ������ � �����, ���� ����������� ������ �������� ��������

            // ����� �������� �����������, �� ������ ������� ����� ����������� ��� ��������� ������ ��������
            this->Close();
        }
    };
}
