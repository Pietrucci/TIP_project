#include "MainWindow.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main2(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TIPproj::MainWindow form;
	Application::Run(% form);
}