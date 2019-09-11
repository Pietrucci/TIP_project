#include <windows.h>

#include "LoginWindow.h"
#include <iostream>
#include <pjsua2.hpp>
using namespace System;
using namespace System::Windows::Forms;
using namespace pj;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Endpoint ep;
	ep.libCreate();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TIPproj::LoginWindow form;
	Application::Run(% form);
}