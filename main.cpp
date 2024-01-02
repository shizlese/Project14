#include "LoginForm.h"
#include "RegistrationForm.h"
#include "ClientForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project14::LoginForm loginform;
	Application::Run(% loginform);
}