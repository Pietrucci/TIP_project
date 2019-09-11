#pragma once
#include <pjsua2.hpp>
#include <windows.h>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "MyAccount.h"
#include "MyCall.h"
using namespace pj;


namespace TIPproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace pj;


	public ref class LoginWindow : public System::Windows::Forms::Form
	{
	public:
		LoginWindow(void)
		{
			InitializeComponent();
			AppInit();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ server_textbox;
	protected:

	protected:
	private: System::Windows::Forms::Label^ server_label;
	private: System::Windows::Forms::Label^ number_label;
	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::TextBox^ number_textbox;
	private: System::Windows::Forms::TextBox^ password_textbox;
	private: System::Windows::Forms::Button^ connect_buton;
	private: Endpoint& ep = Endpoint::instance();
	private: MyAccount* acc;
	private: MyCall* active_call;
	private: System::Windows::Forms::Label^ connection_status_label;
	private: System::Windows::Forms::GroupBox^ connected_group;


	private: System::Windows::Forms::Button^ call_button;
	private: System::Windows::Forms::TextBox^ dialer_textbox;
	private: System::Windows::Forms::Button^ hangup_button;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->server_textbox = (gcnew System::Windows::Forms::TextBox());
			this->server_label = (gcnew System::Windows::Forms::Label());
			this->number_label = (gcnew System::Windows::Forms::Label());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->number_textbox = (gcnew System::Windows::Forms::TextBox());
			this->password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->connect_buton = (gcnew System::Windows::Forms::Button());
			this->connection_status_label = (gcnew System::Windows::Forms::Label());
			this->connected_group = (gcnew System::Windows::Forms::GroupBox());
			this->dialer_textbox = (gcnew System::Windows::Forms::TextBox());
			this->hangup_button = (gcnew System::Windows::Forms::Button());
			this->call_button = (gcnew System::Windows::Forms::Button());
			this->connected_group->SuspendLayout();
			this->SuspendLayout();
			// 
			// server_textbox
			// 
			this->server_textbox->Location = System::Drawing::Point(22, 25);
			this->server_textbox->MaxLength = 15;
			this->server_textbox->Name = L"server_textbox";
			this->server_textbox->Size = System::Drawing::Size(100, 20);
			this->server_textbox->TabIndex = 0;
			this->server_textbox->Text = L"10.0.0.136:5160";
			this->server_textbox->TextChanged += gcnew System::EventHandler(this, &LoginWindow::Server_textbox_TextChanged);
			// 
			// server_label
			// 
			this->server_label->AutoSize = true;
			this->server_label->Location = System::Drawing::Point(19, 9);
			this->server_label->Name = L"server_label";
			this->server_label->Size = System::Drawing::Size(78, 13);
			this->server_label->TabIndex = 1;
			this->server_label->Text = L"Server address";
			this->server_label->Click += gcnew System::EventHandler(this, &LoginWindow::Server_label_Click);
			// 
			// number_label
			// 
			this->number_label->AutoSize = true;
			this->number_label->Location = System::Drawing::Point(125, 9);
			this->number_label->Name = L"number_label";
			this->number_label->Size = System::Drawing::Size(44, 13);
			this->number_label->TabIndex = 2;
			this->number_label->Text = L"Number";
			this->number_label->Click += gcnew System::EventHandler(this, &LoginWindow::Label1_Click);
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Location = System::Drawing::Point(231, 9);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(53, 13);
			this->password_label->TabIndex = 3;
			this->password_label->Text = L"Password";
			// 
			// number_textbox
			// 
			this->number_textbox->Location = System::Drawing::Point(128, 25);
			this->number_textbox->MaxLength = 32;
			this->number_textbox->Name = L"number_textbox";
			this->number_textbox->Size = System::Drawing::Size(100, 20);
			this->number_textbox->TabIndex = 4;
			this->number_textbox->Text = L"9222";
			// 
			// password_textbox
			// 
			this->password_textbox->Location = System::Drawing::Point(234, 25);
			this->password_textbox->MaxLength = 32;
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->PasswordChar = '•';
			this->password_textbox->Size = System::Drawing::Size(100, 20);
			this->password_textbox->TabIndex = 5;
			this->password_textbox->Text = L"12345";
			this->password_textbox->UseSystemPasswordChar = true;
			// 
			// connect_buton
			// 
			this->connect_buton->Location = System::Drawing::Point(340, 24);
			this->connect_buton->Name = L"connect_buton";
			this->connect_buton->Size = System::Drawing::Size(75, 22);
			this->connect_buton->TabIndex = 7;
			this->connect_buton->Text = L"Connect";
			this->connect_buton->UseVisualStyleBackColor = true;
			this->connect_buton->Click += gcnew System::EventHandler(this, &LoginWindow::Connect_buton_Click);
			// 
			// connection_status_label
			// 
			this->connection_status_label->AutoSize = true;
			this->connection_status_label->ForeColor = System::Drawing::Color::Red;
			this->connection_status_label->Location = System::Drawing::Point(421, 28);
			this->connection_status_label->Name = L"connection_status_label";
			this->connection_status_label->Size = System::Drawing::Size(73, 13);
			this->connection_status_label->TabIndex = 8;
			this->connection_status_label->Text = L"Disconnected";
			// 
			// connected_group
			// 
			this->connected_group->Controls->Add(this->dialer_textbox);
			this->connected_group->Controls->Add(this->hangup_button);
			this->connected_group->Controls->Add(this->call_button);
			this->connected_group->Location = System::Drawing::Point(12, 53);
			this->connected_group->Name = L"connected_group";
			this->connected_group->Size = System::Drawing::Size(680, 376);
			this->connected_group->TabIndex = 9;
			this->connected_group->TabStop = false;
			this->connected_group->Visible = false;
			// 
			// dialer_textbox
			// 
			this->dialer_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dialer_textbox->Location = System::Drawing::Point(27, 84);
			this->dialer_textbox->MaxLength = 32;
			this->dialer_textbox->Name = L"dialer_textbox";
			this->dialer_textbox->Size = System::Drawing::Size(130, 38);
			this->dialer_textbox->TabIndex = 2;
			this->dialer_textbox->Text = L"8222";
			// 
			// hangup_button
			// 
			this->hangup_button->Location = System::Drawing::Point(100, 139);
			this->hangup_button->Name = L"hangup_button";
			this->hangup_button->Size = System::Drawing::Size(57, 47);
			this->hangup_button->TabIndex = 1;
			this->hangup_button->Text = L"Hangup";
			this->hangup_button->UseVisualStyleBackColor = true;
			this->hangup_button->Click += gcnew System::EventHandler(this, &LoginWindow::Button2_Click);
			// 
			// call_button
			// 
			this->call_button->Location = System::Drawing::Point(27, 139);
			this->call_button->Name = L"call_button";
			this->call_button->Size = System::Drawing::Size(57, 47);
			this->call_button->TabIndex = 0;
			this->call_button->Text = L"Call";
			this->call_button->UseVisualStyleBackColor = true;
			this->call_button->Click += gcnew System::EventHandler(this, &LoginWindow::Call_button_Click);
			// 
			// LoginWindow
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(704, 441);
			this->Controls->Add(this->connected_group);
			this->Controls->Add(this->connection_status_label);
			this->Controls->Add(this->connect_buton);
			this->Controls->Add(this->password_textbox);
			this->Controls->Add(this->number_textbox);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->number_label);
			this->Controls->Add(this->server_label);
			this->Controls->Add(this->server_textbox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"LoginWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TIP application";
			this->Load += gcnew System::EventHandler(this, &LoginWindow::MyForm_Load);
			this->connected_group->ResumeLayout(false);
			this->connected_group->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Server_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Server_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Connect_buton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (connect_buton->Text == "Connect") {
			password_textbox->ReadOnly = true;
			server_textbox->ReadOnly = true;
			number_textbox->ReadOnly = true;
			connect_buton->Text = "Disconnect";
			ApplicationConnect();
		}
		else if (connect_buton->Text == "Disconnect") {
			password_textbox->Text = "";
			password_textbox->ReadOnly = false;
			server_textbox->ReadOnly = false;
			number_textbox->ReadOnly = false;
			connect_buton->Text = "Connect";
			ApplicationDisonnect();
		}
	}


	public: void AppInit() {
		EpConfig ep_cfg;
		ep_cfg.logConfig.level = 4;
		ep.libInit(ep_cfg);
		TransportConfig tcfg;
		tcfg.port = 5160;
		ep.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);
		ep.libStart();
	}

	public: void AppRegister() {
		connection_status_label->Text = "Connecting...";
		connection_status_label->ForeColor = Color::DarkOrange;
		string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
		string number = msclr::interop::marshal_as<std::string>(number_textbox->Text);
		string password = msclr::interop::marshal_as<std::string>(password_textbox->Text);

		AccountConfig acc_cfg;
		acc_cfg.idUri = "sip:" + number + "@" + server;
		acc_cfg.regConfig.registrarUri = "sip:" + server;
		acc_cfg.sipConfig.authCreds.push_back(AuthCredInfo("digest", "*", number, 0, password));
		acc = new MyAccount();

		acc->create(acc_cfg);
		while (acc->getInfo().regStatus == PJSIP_SC_TRYING) {

		}
		if (acc->getInfo().regStatus != PJSIP_SC_OK) {
			MessageBox::Show(gcnew String(acc->getInfo().regStatusText.c_str()));
			connection_status_label->Text = "Disconnected";
			connection_status_label->ForeColor = Color::Red;

			password_textbox->ReadOnly = false;
			server_textbox->ReadOnly = false;
			number_textbox->ReadOnly = false;
			connect_buton->Text = "Connect";

		}
		else {
			connection_status_label->Text = "Connected";
			connection_status_label->ForeColor = Color::ForestGreen;
			connected_group->Visible = true;
		}
	}

	public: void AppMakeCall() {
		string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
		string dial_number = msclr::interop::marshal_as<std::string>(dialer_textbox->Text);

		active_call = new MyCall(*acc);
		CallOpParam prm(true);
		prm.opt.audioCount = 1;
		prm.opt.videoCount = 0;
		active_call->makeCall("sip:" + dial_number + "@" + server, prm);

	}
	public: void AppMakeHangup() {
		ep.hangupAllCalls();
	}
	private: void ApplicationConnect() {
		AppRegister();
	}

	private: void ApplicationDisonnect() {
		//need to delete all buddies here
		ep.hangupAllCalls();
		acc->shutdown();
		connection_status_label->Text = "Disconnected";
		connection_status_label->ForeColor = Color::Red;
		connected_group->Visible = false;

	}
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		AppMakeHangup();
	}
	private: System::Void Call_button_Click(System::Object^ sender, System::EventArgs^ e) {
		AppMakeCall();
	}

	public: void RegisteredCallback() {
		std::cout << "test";
	}

	public: void UnregisteredCallback() {

	}
	};

}