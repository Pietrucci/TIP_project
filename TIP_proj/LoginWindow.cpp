#include <windows.h>

#include "MainWindow.h"
#include "LoginWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TIPproj::LoginWindow form;
	TIPproj::MainWindow form2;
	Application::Run(% form);
}