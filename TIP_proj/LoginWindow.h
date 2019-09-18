#pragma once
#include <mysql.h>
#include "MyAccount.h"
#include "MyBuddy.h"
#include "MyCall.h"
#include <pjsua2.hpp>
#include <windows.h>
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>

int qstate;

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
			BuddyPollTimer->Interval = 1000;
			BuddyPollTimer->Tick += gcnew System::EventHandler(this, &TIPproj::LoginWindow::PollBuddies);
			BuddyPollTimer->Start();
		}

	private: Endpoint& ep = Endpoint::instance();
	private: MyAccount* acc;
	private: System::Windows::Forms::Timer^ BuddyPollTimer;


	private: System::Windows::Forms::Button^ deafen_button;
	private: System::Windows::Forms::Button^ mute_button;

	private: System::Windows::Forms::Button^ digit1_button;
	private: System::Windows::Forms::Button^ digit_hash_button;

	private: System::Windows::Forms::Button^ digit0_button;

	private: System::Windows::Forms::Button^ digit_asterisk_button;


	private: System::Windows::Forms::Button^ digit9_button;

	private: System::Windows::Forms::Button^ digit8_button;

	private: System::Windows::Forms::Button^ digit7_button;

	private: System::Windows::Forms::Button^ digit6_button;

	private: System::Windows::Forms::Button^ digit5_button;

	private: System::Windows::Forms::Button^ digit4_button;

	private: System::Windows::Forms::Button^ digit3_button;

	private: System::Windows::Forms::Button^ digit2_button;
	private: System::Windows::Forms::GroupBox^ active_call_box;
	private: System::Windows::Forms::Label^ active_caller_id_label;
	private: System::Windows::Forms::Label^ call_time_label;
	private: System::Windows::Forms::Button^ create_button;

	private: System::Windows::Forms::Button^ hold_button;

	protected: ~LoginWindow()
	{
		if (components)
		{
			delete components;
		}
	}
	public: System::Windows::Forms::TextBox^ server_textbox;
	protected:

	private: System::Windows::Forms::Label^ server_label;
	private: System::Windows::Forms::Label^ number_label;
	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::TextBox^ number_textbox;
	private: System::Windows::Forms::TextBox^ password_textbox;
	private: System::Windows::Forms::Button^ connect_buton;
	private: System::Windows::Forms::Label^ connection_status_label;
	private: System::Windows::Forms::GroupBox^ connected_group;
	private: System::Windows::Forms::Button^ call_button;
	private: System::Windows::Forms::TextBox^ dialer_textbox;
	private: System::Windows::Forms::Button^ hangup_button;
	private: System::Windows::Forms::ContextMenuStrip^ buddy_context_menu;
	private: System::Windows::Forms::ToolStripMenuItem^ call;
	private: System::Windows::Forms::ToolStripMenuItem^ remove;
	public: System::Windows::Forms::TreeView^ buddy_tree;
	private: System::Windows::Forms::Button^ add_buddy_button;
	private: System::Windows::Forms::Label^ buddies_label;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginWindow::typeid));
				 this->buddy_context_menu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
				 this->call = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->remove = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->server_textbox = (gcnew System::Windows::Forms::TextBox());
				 this->server_label = (gcnew System::Windows::Forms::Label());
				 this->number_label = (gcnew System::Windows::Forms::Label());
				 this->password_label = (gcnew System::Windows::Forms::Label());
				 this->number_textbox = (gcnew System::Windows::Forms::TextBox());
				 this->password_textbox = (gcnew System::Windows::Forms::TextBox());
				 this->connect_buton = (gcnew System::Windows::Forms::Button());
				 this->connection_status_label = (gcnew System::Windows::Forms::Label());
				 this->connected_group = (gcnew System::Windows::Forms::GroupBox());
				 this->active_call_box = (gcnew System::Windows::Forms::GroupBox());
				 this->active_caller_id_label = (gcnew System::Windows::Forms::Label());
				 this->call_time_label = (gcnew System::Windows::Forms::Label());
				 this->mute_button = (gcnew System::Windows::Forms::Button());
				 this->deafen_button = (gcnew System::Windows::Forms::Button());
				 this->digit_hash_button = (gcnew System::Windows::Forms::Button());
				 this->digit0_button = (gcnew System::Windows::Forms::Button());
				 this->digit_asterisk_button = (gcnew System::Windows::Forms::Button());
				 this->digit9_button = (gcnew System::Windows::Forms::Button());
				 this->digit8_button = (gcnew System::Windows::Forms::Button());
				 this->digit7_button = (gcnew System::Windows::Forms::Button());
				 this->digit6_button = (gcnew System::Windows::Forms::Button());
				 this->digit5_button = (gcnew System::Windows::Forms::Button());
				 this->digit4_button = (gcnew System::Windows::Forms::Button());
				 this->digit3_button = (gcnew System::Windows::Forms::Button());
				 this->digit2_button = (gcnew System::Windows::Forms::Button());
				 this->digit1_button = (gcnew System::Windows::Forms::Button());
				 this->hold_button = (gcnew System::Windows::Forms::Button());
				 this->buddies_label = (gcnew System::Windows::Forms::Label());
				 this->add_buddy_button = (gcnew System::Windows::Forms::Button());
				 this->buddy_tree = (gcnew System::Windows::Forms::TreeView());
				 this->dialer_textbox = (gcnew System::Windows::Forms::TextBox());
				 this->hangup_button = (gcnew System::Windows::Forms::Button());
				 this->call_button = (gcnew System::Windows::Forms::Button());
				 this->BuddyPollTimer = (gcnew System::Windows::Forms::Timer(this->components));
				 this->create_button = (gcnew System::Windows::Forms::Button());
				 this->buddy_context_menu->SuspendLayout();
				 this->connected_group->SuspendLayout();
				 this->active_call_box->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // buddy_context_menu
				 // 
				 this->buddy_context_menu->ImageScalingSize = System::Drawing::Size(20, 20);
				 this->buddy_context_menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->call, this->remove });
				 this->buddy_context_menu->Name = L"buddy_context_menu";
				 this->buddy_context_menu->Size = System::Drawing::Size(179, 52);
				 // 
				 // call
				 // 
				 this->call->Name = L"call";
				 this->call->Size = System::Drawing::Size(178, 24);
				 this->call->Text = L"Call";
				 this->call->Click += gcnew System::EventHandler(this, &LoginWindow::Call_Click);
				 // 
				 // remove
				 // 
				 this->remove->Name = L"remove";
				 this->remove->Size = System::Drawing::Size(178, 24);
				 this->remove->Text = L"Remove buddy";
				 this->remove->Click += gcnew System::EventHandler(this, &LoginWindow::Remove_Click);
				 // 
				 // server_textbox
				 // 
				 this->server_textbox->Location = System::Drawing::Point(22, 25);
				 this->server_textbox->MaxLength = 32;
				 this->server_textbox->Name = L"server_textbox";
				 this->server_textbox->Size = System::Drawing::Size(100, 22);
				 this->server_textbox->TabIndex = 0;
				 this->server_textbox->Text = L"192.168.0.36:5160";
				 this->server_textbox->TextChanged += gcnew System::EventHandler(this, &LoginWindow::Server_textbox_TextChanged);
				 // 
				 // server_label
				 // 
				 this->server_label->AutoSize = true;
				 this->server_label->Location = System::Drawing::Point(19, 9);
				 this->server_label->Name = L"server_label";
				 this->server_label->Size = System::Drawing::Size(105, 17);
				 this->server_label->TabIndex = 1;
				 this->server_label->Text = L"Server address";
				 // 
				 // number_label
				 // 
				 this->number_label->AutoSize = true;
				 this->number_label->Location = System::Drawing::Point(125, 9);
				 this->number_label->Name = L"number_label";
				 this->number_label->Size = System::Drawing::Size(58, 17);
				 this->number_label->TabIndex = 2;
				 this->number_label->Text = L"Number";
				 this->number_label->Click += gcnew System::EventHandler(this, &LoginWindow::Label1_Click);
				 // 
				 // password_label
				 // 
				 this->password_label->AutoSize = true;
				 this->password_label->Location = System::Drawing::Point(231, 9);
				 this->password_label->Name = L"password_label";
				 this->password_label->Size = System::Drawing::Size(69, 17);
				 this->password_label->TabIndex = 3;
				 this->password_label->Text = L"Password";
				 // 
				 // number_textbox
				 // 
				 this->number_textbox->Location = System::Drawing::Point(128, 25);
				 this->number_textbox->MaxLength = 32;
				 this->number_textbox->Name = L"number_textbox";
				 this->number_textbox->Size = System::Drawing::Size(100, 22);
				 this->number_textbox->TabIndex = 4;
				 this->number_textbox->Text = L"9222";
				 // 
				 // password_textbox
				 // 
				 this->password_textbox->Location = System::Drawing::Point(234, 25);
				 this->password_textbox->MaxLength = 32;
				 this->password_textbox->Name = L"password_textbox";
				 this->password_textbox->PasswordChar = '';
				 this->password_textbox->Size = System::Drawing::Size(100, 22);
				 this->password_textbox->TabIndex = 5;
				 this->password_textbox->Text = L"12345";
				 this->password_textbox->UseSystemPasswordChar = true;
				 this->password_textbox->TextChanged += gcnew System::EventHandler(this, &LoginWindow::Password_textbox_TextChanged);
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
				 this->connection_status_label->ContextMenuStrip = this->buddy_context_menu;
				 this->connection_status_label->ForeColor = System::Drawing::Color::Red;
				 this->connection_status_label->Location = System::Drawing::Point(326, 4);
				 this->connection_status_label->Name = L"connection_status_label";
				 this->connection_status_label->Size = System::Drawing::Size(94, 17);
				 this->connection_status_label->TabIndex = 8;
				 this->connection_status_label->Text = L"Disconnected";
				 // 
				 // connected_group
				 // 
				 this->connected_group->Controls->Add(this->active_call_box);
				 this->connected_group->Controls->Add(this->digit_hash_button);
				 this->connected_group->Controls->Add(this->digit0_button);
				 this->connected_group->Controls->Add(this->digit_asterisk_button);
				 this->connected_group->Controls->Add(this->digit9_button);
				 this->connected_group->Controls->Add(this->digit8_button);
				 this->connected_group->Controls->Add(this->digit7_button);
				 this->connected_group->Controls->Add(this->digit6_button);
				 this->connected_group->Controls->Add(this->digit5_button);
				 this->connected_group->Controls->Add(this->digit4_button);
				 this->connected_group->Controls->Add(this->digit3_button);
				 this->connected_group->Controls->Add(this->digit2_button);
				 this->connected_group->Controls->Add(this->digit1_button);
				 this->connected_group->Controls->Add(this->hold_button);
				 this->connected_group->Controls->Add(this->buddies_label);
				 this->connected_group->Controls->Add(this->add_buddy_button);
				 this->connected_group->Controls->Add(this->buddy_tree);
				 this->connected_group->Controls->Add(this->dialer_textbox);
				 this->connected_group->Controls->Add(this->hangup_button);
				 this->connected_group->Controls->Add(this->call_button);
				 this->connected_group->Location = System::Drawing::Point(12, 53);
				 this->connected_group->Name = L"connected_group";
				 this->connected_group->Size = System::Drawing::Size(500, 301);
				 this->connected_group->TabIndex = 9;
				 this->connected_group->TabStop = false;
				 this->connected_group->Visible = false;
				 // 
				 // active_call_box
				 // 
				 this->active_call_box->Controls->Add(this->active_caller_id_label);
				 this->active_call_box->Controls->Add(this->call_time_label);
				 this->active_call_box->Controls->Add(this->mute_button);
				 this->active_call_box->Controls->Add(this->deafen_button);
				 this->active_call_box->Location = System::Drawing::Point(172, 19);
				 this->active_call_box->Name = L"active_call_box";
				 this->active_call_box->Size = System::Drawing::Size(186, 180);
				 this->active_call_box->TabIndex = 22;
				 this->active_call_box->TabStop = false;
				 this->active_call_box->Visible = false;
				 // 
				 // active_caller_id_label
				 // 
				 this->active_caller_id_label->Location = System::Drawing::Point(6, 65);
				 this->active_caller_id_label->Name = L"active_caller_id_label";
				 this->active_caller_id_label->Size = System::Drawing::Size(174, 20);
				 this->active_caller_id_label->TabIndex = 1;
				 this->active_caller_id_label->Text = L"NoCall";
				 this->active_caller_id_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // call_time_label
				 // 
				 this->call_time_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->call_time_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
				 this->call_time_label->Location = System::Drawing::Point(6, 12);
				 this->call_time_label->Name = L"call_time_label";
				 this->call_time_label->Size = System::Drawing::Size(174, 39);
				 this->call_time_label->TabIndex = 0;
				 this->call_time_label->Text = L"Calling...";
				 this->call_time_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->call_time_label->Click += gcnew System::EventHandler(this, &LoginWindow::Call_time_label_Click);
				 // 
				 // mute_button
				 // 
				 this->mute_button->FlatAppearance->BorderSize = 0;
				 this->mute_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->mute_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mute_button.Image")));
				 this->mute_button->Location = System::Drawing::Point(48, 133);
				 this->mute_button->Name = L"mute_button";
				 this->mute_button->Size = System::Drawing::Size(41, 41);
				 this->mute_button->TabIndex = 6;
				 this->mute_button->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->mute_button->UseVisualStyleBackColor = true;
				 this->mute_button->Click += gcnew System::EventHandler(this, &LoginWindow::Mute_button_Click);
				 // 
				 // deafen_button
				 // 
				 this->deafen_button->FlatAppearance->BorderSize = 0;
				 this->deafen_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->deafen_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deafen_button.Image")));
				 this->deafen_button->Location = System::Drawing::Point(96, 133);
				 this->deafen_button->Name = L"deafen_button";
				 this->deafen_button->Size = System::Drawing::Size(41, 41);
				 this->deafen_button->TabIndex = 7;
				 this->deafen_button->UseVisualStyleBackColor = true;
				 this->deafen_button->Click += gcnew System::EventHandler(this, &LoginWindow::Deafen_button_Click);
				 // 
				 // digit_hash_button
				 // 
				 this->digit_hash_button->FlatAppearance->BorderSize = 0;
				 this->digit_hash_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit_hash_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit_hash_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit_hash_button.Image")));
				 this->digit_hash_button->Location = System::Drawing::Point(104, 204);
				 this->digit_hash_button->Name = L"digit_hash_button";
				 this->digit_hash_button->Size = System::Drawing::Size(41, 41);
				 this->digit_hash_button->TabIndex = 21;
				 this->digit_hash_button->Text = L"#";
				 this->digit_hash_button->UseCompatibleTextRendering = true;
				 this->digit_hash_button->UseVisualStyleBackColor = true;
				 this->digit_hash_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit_hash_button_Click);
				 // 
				 // digit0_button
				 // 
				 this->digit0_button->FlatAppearance->BorderSize = 0;
				 this->digit0_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit0_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit0_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit0_button.Image")));
				 this->digit0_button->Location = System::Drawing::Point(57, 204);
				 this->digit0_button->Name = L"digit0_button";
				 this->digit0_button->Size = System::Drawing::Size(41, 41);
				 this->digit0_button->TabIndex = 20;
				 this->digit0_button->Text = L"0";
				 this->digit0_button->UseCompatibleTextRendering = true;
				 this->digit0_button->UseVisualStyleBackColor = true;
				 this->digit0_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit0_button_Click);
				 // 
				 // digit_asterisk_button
				 // 
				 this->digit_asterisk_button->FlatAppearance->BorderSize = 0;
				 this->digit_asterisk_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit_asterisk_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit_asterisk_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit_asterisk_button.Image")));
				 this->digit_asterisk_button->Location = System::Drawing::Point(10, 204);
				 this->digit_asterisk_button->Name = L"digit_asterisk_button";
				 this->digit_asterisk_button->Size = System::Drawing::Size(41, 41);
				 this->digit_asterisk_button->TabIndex = 19;
				 this->digit_asterisk_button->Text = L"*";
				 this->digit_asterisk_button->UseCompatibleTextRendering = true;
				 this->digit_asterisk_button->UseVisualStyleBackColor = true;
				 this->digit_asterisk_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit_asterisk_button_Click);
				 // 
				 // digit9_button
				 // 
				 this->digit9_button->FlatAppearance->BorderSize = 0;
				 this->digit9_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit9_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit9_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit9_button.Image")));
				 this->digit9_button->Location = System::Drawing::Point(104, 157);
				 this->digit9_button->Name = L"digit9_button";
				 this->digit9_button->Size = System::Drawing::Size(41, 41);
				 this->digit9_button->TabIndex = 18;
				 this->digit9_button->Text = L"9";
				 this->digit9_button->UseCompatibleTextRendering = true;
				 this->digit9_button->UseVisualStyleBackColor = true;
				 this->digit9_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit9_button_Click);
				 // 
				 // digit8_button
				 // 
				 this->digit8_button->FlatAppearance->BorderSize = 0;
				 this->digit8_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit8_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit8_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit8_button.Image")));
				 this->digit8_button->Location = System::Drawing::Point(57, 157);
				 this->digit8_button->Name = L"digit8_button";
				 this->digit8_button->Size = System::Drawing::Size(41, 41);
				 this->digit8_button->TabIndex = 17;
				 this->digit8_button->Text = L"8";
				 this->digit8_button->UseCompatibleTextRendering = true;
				 this->digit8_button->UseVisualStyleBackColor = true;
				 this->digit8_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit8_button_Click);
				 // 
				 // digit7_button
				 // 
				 this->digit7_button->FlatAppearance->BorderSize = 0;
				 this->digit7_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit7_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit7_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit7_button.Image")));
				 this->digit7_button->Location = System::Drawing::Point(10, 157);
				 this->digit7_button->Name = L"digit7_button";
				 this->digit7_button->Size = System::Drawing::Size(41, 41);
				 this->digit7_button->TabIndex = 16;
				 this->digit7_button->Text = L"7";
				 this->digit7_button->UseCompatibleTextRendering = true;
				 this->digit7_button->UseVisualStyleBackColor = true;
				 this->digit7_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit7_button_Click);
				 // 
				 // digit6_button
				 // 
				 this->digit6_button->FlatAppearance->BorderSize = 0;
				 this->digit6_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit6_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit6_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit6_button.Image")));
				 this->digit6_button->Location = System::Drawing::Point(104, 110);
				 this->digit6_button->Name = L"digit6_button";
				 this->digit6_button->Size = System::Drawing::Size(41, 41);
				 this->digit6_button->TabIndex = 15;
				 this->digit6_button->Text = L"6";
				 this->digit6_button->UseCompatibleTextRendering = true;
				 this->digit6_button->UseVisualStyleBackColor = true;
				 this->digit6_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit6_button_Click);
				 // 
				 // digit5_button
				 // 
				 this->digit5_button->FlatAppearance->BorderSize = 0;
				 this->digit5_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit5_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit5_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit5_button.Image")));
				 this->digit5_button->Location = System::Drawing::Point(57, 110);
				 this->digit5_button->Name = L"digit5_button";
				 this->digit5_button->Size = System::Drawing::Size(41, 41);
				 this->digit5_button->TabIndex = 14;
				 this->digit5_button->Text = L"5";
				 this->digit5_button->UseCompatibleTextRendering = true;
				 this->digit5_button->UseVisualStyleBackColor = true;
				 this->digit5_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit5_button_Click);
				 // 
				 // digit4_button
				 // 
				 this->digit4_button->FlatAppearance->BorderSize = 0;
				 this->digit4_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit4_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit4_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit4_button.Image")));
				 this->digit4_button->Location = System::Drawing::Point(10, 110);
				 this->digit4_button->Name = L"digit4_button";
				 this->digit4_button->Size = System::Drawing::Size(41, 41);
				 this->digit4_button->TabIndex = 13;
				 this->digit4_button->Text = L"4";
				 this->digit4_button->UseCompatibleTextRendering = true;
				 this->digit4_button->UseVisualStyleBackColor = true;
				 this->digit4_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit4_button_Click);
				 // 
				 // digit3_button
				 // 
				 this->digit3_button->FlatAppearance->BorderSize = 0;
				 this->digit3_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit3_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit3_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit3_button.Image")));
				 this->digit3_button->Location = System::Drawing::Point(104, 63);
				 this->digit3_button->Name = L"digit3_button";
				 this->digit3_button->Size = System::Drawing::Size(41, 41);
				 this->digit3_button->TabIndex = 12;
				 this->digit3_button->Text = L"3";
				 this->digit3_button->UseCompatibleTextRendering = true;
				 this->digit3_button->UseVisualStyleBackColor = true;
				 this->digit3_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit3_button_Click);
				 // 
				 // digit2_button
				 // 
				 this->digit2_button->FlatAppearance->BorderSize = 0;
				 this->digit2_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit2_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit2_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit2_button.Image")));
				 this->digit2_button->Location = System::Drawing::Point(57, 63);
				 this->digit2_button->Name = L"digit2_button";
				 this->digit2_button->Size = System::Drawing::Size(41, 41);
				 this->digit2_button->TabIndex = 11;
				 this->digit2_button->Text = L"2";
				 this->digit2_button->UseCompatibleTextRendering = true;
				 this->digit2_button->UseVisualStyleBackColor = true;
				 this->digit2_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit2_button_Click);
				 // 
				 // digit1_button
				 // 
				 this->digit1_button->FlatAppearance->BorderSize = 0;
				 this->digit1_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->digit1_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->digit1_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digit1_button.Image")));
				 this->digit1_button->Location = System::Drawing::Point(10, 63);
				 this->digit1_button->Name = L"digit1_button";
				 this->digit1_button->Size = System::Drawing::Size(41, 41);
				 this->digit1_button->TabIndex = 10;
				 this->digit1_button->Text = L"1";
				 this->digit1_button->UseCompatibleTextRendering = true;
				 this->digit1_button->UseVisualStyleBackColor = true;
				 this->digit1_button->Click += gcnew System::EventHandler(this, &LoginWindow::Digit1_button_Click);
				 // 
				 // hold_button
				 // 
				 this->hold_button->FlatAppearance->BorderSize = 0;
				 this->hold_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->hold_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hold_button.Image")));
				 this->hold_button->Location = System::Drawing::Point(57, 251);
				 this->hold_button->Name = L"hold_button";
				 this->hold_button->Size = System::Drawing::Size(41, 41);
				 this->hold_button->TabIndex = 8;
				 this->hold_button->UseVisualStyleBackColor = false;
				 this->hold_button->Click += gcnew System::EventHandler(this, &LoginWindow::Hold_button_Click);
				 // 
				 // buddies_label
				 // 
				 this->buddies_label->AutoSize = true;
				 this->buddies_label->Location = System::Drawing::Point(365, 16);
				 this->buddies_label->Name = L"buddies_label";
				 this->buddies_label->Size = System::Drawing::Size(59, 17);
				 this->buddies_label->TabIndex = 5;
				 this->buddies_label->Text = L"Buddies";
				 // 
				 // add_buddy_button
				 // 
				 this->add_buddy_button->FlatAppearance->BorderSize = 0;
				 this->add_buddy_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->add_buddy_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"add_buddy_button.Image")));
				 this->add_buddy_button->Location = System::Drawing::Point(317, 251);
				 this->add_buddy_button->Name = L"add_buddy_button";
				 this->add_buddy_button->Size = System::Drawing::Size(41, 41);
				 this->add_buddy_button->TabIndex = 4;
				 this->add_buddy_button->UseVisualStyleBackColor = true;
				 this->add_buddy_button->Click += gcnew System::EventHandler(this, &LoginWindow::Add_buddy_button_Click);
				 // 
				 // buddy_tree
				 // 
				 this->buddy_tree->Location = System::Drawing::Point(367, 31);
				 this->buddy_tree->Name = L"buddy_tree";
				 this->buddy_tree->ShowLines = false;
				 this->buddy_tree->ShowPlusMinus = false;
				 this->buddy_tree->ShowRootLines = false;
				 this->buddy_tree->Size = System::Drawing::Size(127, 261);
				 this->buddy_tree->TabIndex = 3;
				 // 
				 // dialer_textbox
				 // 
				 this->dialer_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->dialer_textbox->Location = System::Drawing::Point(10, 19);
				 this->dialer_textbox->MaxLength = 32;
				 this->dialer_textbox->Name = L"dialer_textbox";
				 this->dialer_textbox->Size = System::Drawing::Size(135, 46);
				 this->dialer_textbox->TabIndex = 2;
				 this->dialer_textbox->Text = L"8222";
				 this->dialer_textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 // 
				 // hangup_button
				 // 
				 this->hangup_button->FlatAppearance->BorderSize = 0;
				 this->hangup_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->hangup_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hangup_button.Image")));
				 this->hangup_button->Location = System::Drawing::Point(104, 251);
				 this->hangup_button->Name = L"hangup_button";
				 this->hangup_button->Size = System::Drawing::Size(41, 41);
				 this->hangup_button->TabIndex = 1;
				 this->hangup_button->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->hangup_button->UseVisualStyleBackColor = false;
				 this->hangup_button->Click += gcnew System::EventHandler(this, &LoginWindow::Hangup_button_Click);
				 // 
				 // call_button
				 // 
				 this->call_button->FlatAppearance->BorderSize = 0;
				 this->call_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->call_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"call_button.Image")));
				 this->call_button->Location = System::Drawing::Point(10, 251);
				 this->call_button->Name = L"call_button";
				 this->call_button->Size = System::Drawing::Size(41, 41);
				 this->call_button->TabIndex = 0;
				 this->call_button->UseVisualStyleBackColor = false;
				 this->call_button->Click += gcnew System::EventHandler(this, &LoginWindow::Call_button_Click);
				 // 
				 // create_button
				 // 
				 this->create_button->Location = System::Drawing::Point(421, 12);
				 this->create_button->Name = L"create_button";
				 this->create_button->Size = System::Drawing::Size(91, 43);
				 this->create_button->TabIndex = 10;
				 this->create_button->Text = L"Create account";
				 this->create_button->UseVisualStyleBackColor = true;
				 this->create_button->Click += gcnew System::EventHandler(this, &LoginWindow::create_button_Click);
				 // 
				 // LoginWindow
				 // 
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
				 this->ClientSize = System::Drawing::Size(524, 361);
				 this->Controls->Add(this->create_button);
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
				 this->buddy_context_menu->ResumeLayout(false);
				 this->connected_group->ResumeLayout(false);
				 this->connected_group->PerformLayout();
				 this->active_call_box->ResumeLayout(false);
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
			create_button->Visible = true;
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
			typedef std::function<bool(int)> FunctionPtr;

	public: void AppRegister() {
		connection_status_label->Text = "Connecting...";
		connection_status_label->ForeColor = Color::DarkOrange;
		string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
		string number = msclr::interop::marshal_as<std::string>(number_textbox->Text);
		string password = msclr::interop::marshal_as<std::string>(password_textbox->Text);
		password_textbox->Text = "";
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
			create_button->Visible = false;
			connection_status_label->Text = "Connected";
			connection_status_label->ForeColor = Color::ForestGreen;
			connected_group->Visible = true;
		}
		
		std::ifstream fin;
		std::string line;
		fin.open(number + ".txt", std::ios_base::app);
		while (getline(fin, line)) {
			if (line != "") {
				TreeNode^ new_node = gcnew TreeNode(gcnew String(line.c_str()));
				new_node->ContextMenuStrip = buddy_context_menu;
				buddy_tree->Nodes->Add(new_node);
				AppAddBuddy(gcnew String(line.c_str()), false);
			}
		}
		
	}

	public: void AppMakeCall() {
		string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
		string dial_number = msclr::interop::marshal_as<std::string>(dialer_textbox->Text);

		acc->active_call = new MyCall(*acc);
		CallOpParam prm(true);
		prm.opt.audioCount = 1;
		prm.opt.videoCount = 0;
		acc->active_call->makeCall("sip:" + dial_number + "@" + server, prm);

	}
	public: void AppMakeHangup() {
		ep.hangupAllCalls();
	}

	public: void AppAddBuddy(String^ number, boolean save) {
		BuddyConfig cfg;

		string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
		string number_string = msclr::interop::marshal_as<std::string>(number);

		cfg.uri = "sip:" + number_string + "@" + server;
		MyBuddy* buddy = new MyBuddy();
		try {
			buddy->create(*acc, cfg);
			buddy->subscribePresence(true);
		}
		catch (...) {

		}
		finally{
			acc->buddies.push_back(buddy);
		if (save) {
			std::string user_info = acc->getInfo().uri;
			user_info = user_info.substr(4);
			user_info = user_info.substr(0, user_info.find("@", 0));

			std::ofstream file;
			file.open(user_info + ".txt", std::ios_base::app);
			file << number_string << "\n";
			file.close();
		}
		}

	}
	public: void AppRemoveBuddy(String^ number) {
		string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
		string number_string = msclr::interop::marshal_as<std::string>(number);
		string to_find = "sip:" + number_string + "@" + server;
		vector<Buddy*>::iterator it = acc->buddies.begin();
		while (it != acc->buddies.end()) {
			if ((*it)->getInfo().uri == to_find) {
				(*it)->~Buddy();
				it = acc->buddies.erase(it);
			}
			else
				++it;
		}

		for each (Buddy * buddy in acc->buddies) {
			if (buddy->getInfo().uri == to_find) {

				delete buddy;
			}
		}
		
				std::string user_info = acc->getInfo().uri;
		user_info = user_info.substr(4);
		user_info = user_info.substr(0, user_info.find("@", 0));

		std::ifstream fin;
		fin.open(user_info + ".txt", std::ios_base::app);
		std::ofstream temp;
		temp.open("temp.txt");
		std::string deleteline = number_string;
		std::string line;
		while (getline(fin, line)) {
			if (line != deleteline) {
				temp << line << std::endl;
			}

		}

		temp.close();
		fin.close();
		std::string to_remove = user_info + ".txt";
		std::remove(to_remove.c_str());
		std::rename("temp.txt", to_remove.c_str());
	}

	private: void ApplicationConnect() {
		AppRegister();
	}

	private: void ApplicationDisonnect() {
		//need to delete all buddies here
		ep.hangupAllCalls();
		for (auto b : acc->buddies) {
			b->~Buddy();
			delete b;
		}
		buddy_tree->Nodes->Clear();
		acc->shutdown();
		delete acc;
		connection_status_label->Text = "Disconnected";
		connection_status_label->ForeColor = Color::Red;
		connected_group->Visible = false;

	}
	private: System::Void Hangup_button_Click(System::Object^ sender, System::EventArgs^ e) {
		AppMakeHangup();
	}
	private: System::Void Call_button_Click(System::Object^ sender, System::EventArgs^ e) {
		AppMakeCall();
	}

	private: System::Void Call_Click(System::Object^ sender, System::EventArgs^ e) {
		ToolStripMenuItem^ sen = (ToolStripMenuItem^)sender;
		Windows::Forms::ContextMenuStrip^ menu_strip = (Windows::Forms::ContextMenuStrip^)sen->GetCurrentParent();
		TreeView^ tree_view = (TreeView^)menu_strip->SourceControl;
		TreeNode^ selected_node = tree_view->SelectedNode;
		if (selected_node) {
			dialer_textbox->Text = selected_node->Text;
			AppMakeCall();
		}
	}

	private: System::Void Remove_Click(System::Object^ sender, System::EventArgs^ e) {
		ToolStripMenuItem^ sen = (ToolStripMenuItem^)sender;
		Windows::Forms::ContextMenuStrip^ menu_strip = (Windows::Forms::ContextMenuStrip^)sen->GetCurrentParent();
		TreeView^ tree_view = (TreeView^)menu_strip->SourceControl;
		TreeNode^ selected_node = tree_view->SelectedNode;
		if (selected_node) {
			buddy_tree->Nodes->Remove(selected_node);
			AppRemoveBuddy(selected_node->Text);
		}
	}
	private: System::Void Add_buddy_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dialer_textbox->Text != "") {
			TreeNode^ new_node = gcnew TreeNode(dialer_textbox->Text);
			new_node->ContextMenuStrip = buddy_context_menu;
			buddy_tree->Nodes->Add(new_node);
			AppAddBuddy(new_node->Text);
		}
	}
	private: System::Void Mute_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MyCall* call = acc->active_call;
		if (call) {

			if (call->isMuted) {
				try {
					call->aud_med.adjustRxLevel(1.0);
				}
				catch (...) {

				}
				finally{
				call->isMuted = false;
				mute_button->FlatStyle = FlatStyle::Standard;
				}
			}
			else {
				try {
					call->aud_med.adjustRxLevel(0.0);
				}
				catch (...) {

				}
				finally{
				call->isMuted = true;
				mute_button->FlatStyle = FlatStyle::Flat;
				}

			}

		}
	}
	private: System::Void Deafen_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MyCall* call = acc->active_call;
		if (call) {
			if (call->isDeafened) {
				call->aud_med.adjustTxLevel(1.0);
				call->isDeafened = false;
				deafen_button->FlatStyle = FlatStyle::Standard;

			}
			else {
				call->aud_med.adjustTxLevel(0.0);
				call->isDeafened = true;
				deafen_button->FlatStyle = FlatStyle::Flat;

			}
		}
	}
	private: System::Void Hold_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MyCall* call = acc->active_call;
		if (call) {
			CallOpParam prm(true);

			if (call->isHold) {
				prm.opt.audioCount = 1;
				prm.opt.audioCount = 0;
				prm.opt.flag = pjsua_call_flag::PJSUA_CALL_UNHOLD;
				try {
					pjsua_call_reinvite(call->getId(), prm.opt.flag, NULL);
				}
				catch (...) {

				}
				finally{
				call->isHold = false;
				}
			}
			else {
				try {
					call->setHold(prm);
				}
				catch (...) {

				}
				finally{
				call->isHold = true;
				}

			}
		}
	}
	
	private: System::Void Digit1_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "1";
	}
	private: System::Void Digit2_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "2";
	}
	private: System::Void Digit3_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "3";
	}
	private: System::Void Digit4_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "4";
	}
	private: System::Void Digit5_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "5";
	}
	private: System::Void Digit6_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "6";
	}
	private: System::Void Digit7_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "7";
	}
	private: System::Void Digit8_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "8";
	}
	private: System::Void Digit9_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "9";
	}
	private: System::Void Digit_asterisk_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "*";
	}
	private: System::Void Digit0_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "0";
	}
	private: System::Void Digit_hash_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dialer_textbox->Text += "#";
	}
			 void PollBuddies(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Call_time_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Password_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void create_button_Click(System::Object^ sender, System::EventArgs^ e) {
	string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
	string ip_address = server.substr(0,server.find(":"));
	const char* server_name = ip_address.c_str();
	MYSQL* conn;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn,server_name , "test", "adminadmin", "asterisk", 3306, NULL,0);

	if (conn) {
		string username = msclr::interop::marshal_as<std::string>(number_textbox->Text);
		string password = msclr::interop::marshal_as<std::string>(password_textbox->Text);

		string query = "SELECT * FROM users where extension = '"+username+"';";
		
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		res = mysql_store_result(conn);
		int number_of_rows = mysql_num_rows(res);
		if (number_of_rows == 0) {
			string user_query = "INSERT INTO users( \
			extension, password, name, voicemail, ringtimer, noanswer, recording,\
			outboundcid, sipname, noanswer_cid, busy_cid, chanunavail_cid,\
			noanswer_dest, busy_dest, chanunavail_dest, mohclass)\
			VALUES(\
			'"+username+"', '', '"+username+"', 'novm', '0', '', '', '"+username+"',\
			'', '', '', '', '', '', '', 'default'\
			);";

			string device_query = "INSERT INTO devices (\
			id, tech, dial, devicetype, user, description, emergency_cid)\
			VALUES('" + username + "', 'sip', 'SIP/" + username + "', 'fixed', '" + username + "', '" + username + "', '');";

			string sip_query = "INSERT INTO sip (id, keyword, data, flags)\
				VALUES\
				('" + username + "', 'secret', '" + password + "', 2), \
				('" + username + "', 'dtmfmode', 'rfc2833', 3),\
				('" + username + "', 'canreinvite', 'no', 4),\
				('" + username + "', 'context', 'from-internal', 5),\
				('" + username + "', 'host', 'dynamic', 6),\
				('" + username + "', 'defaultuser', '', 7),\
				('" + username + "', 'trustrpid', 'yes', 8),\
				('" + username + "', 'sendrpid', 'pai', 9),\
				('" + username + "', 'type', 'friend', 10),\
				('" + username + "', 'sessiontimers', 'accept', 11),\
				('" + username + "', 'nat', 'no', 12),\
				('" + username + "', 'port', '5060', 13),\
				('" + username + "', 'qualify', 'yes', 14),\
				('" + username + "', 'qualifyfreq', '60', 15),\
				('" + username + "', 'transport', 'udp,tcp,tls', 16),\
				('" + username + "', 'avpf', 'no', 17),\
				('" + username + "', 'force_avp', 'no', 18),\
				('" + username + "', 'icesupport', 'no', 19),\
				('" + username + "', 'rtcp_mux', 'no', 20),\
				('" + username + "', 'encryption', 'no', 21),\
				('" + username + "', 'videosupport', 'inherit', 22),\
				('" + username + "', 'namedcallgroup', '', 23),\
				('" + username + "', 'namedpickupgroup', '', 24),\
				('" + username + "', 'disallow', '', 25),\
				('" + username + "', 'allow', '', 26),\
				('" + username + "', 'dial', 'SIP/" + username + "', 27),\
				('" + username + "', 'accountcode', '', 28),\
				('" + username + "', 'deny', '0.0.0.0/0.0.0.0', 29),\
				('" + username + "', 'permit', '0.0.0.0/0.0.0.0', 30),\
				('" + username + "', 'secretorigional', '', 31),\
				('" + username + "', 'sipdriver', 'chan_sip', 32),\
				('" + username + "', 'account', '"+username+"', 33),\
				('" + username + "', 'callerid', '"+username+" <"+username+">', 34);";
			q = user_query.c_str();
			qstate = mysql_query(conn, q);

			q = device_query.c_str();
			qstate = mysql_query(conn, q);

			q = sip_query.c_str();
			qstate = mysql_query(conn, q);
			
		}
		else {
			MessageBox::Show(gcnew String("Account already taken"));
		}
	}
	else {
		MessageBox::Show(gcnew String("Wrong server address"));

	}

}
};

}

void TIPproj::LoginWindow::PollBuddies(System::Object^ sender, System::EventArgs^ e)
{
	if (acc) {
		for (auto buddy : acc->buddies) {
			auto info = buddy->getInfo();
			std::string server = msclr::interop::marshal_as<std::string>(server_textbox->Text);
			if (info.presStatus.status == PJSUA_BUDDY_STATUS_ONLINE) {
				for each (TreeNode ^ node in buddy_tree->Nodes) {
					std::string temp = msclr::interop::marshal_as<std::string>(node->Text);
					if ("sip:" + temp + "@" + server == info.uri) {
						node->ForeColor = Color::Green;
					}
				}
			}
			else if (info.presStatus.status == PJSUA_BUDDY_STATUS_OFFLINE) {
				for each (TreeNode ^ node in buddy_tree->Nodes) {
					std::string temp = msclr::interop::marshal_as<std::string>(node->Text);
					if ("sip:" + temp + "@" + server == info.uri) {
						node->ForeColor = Color::Black;
					}
				}
			}
		}
		if (acc->active_call) {
			CallInfo info;
			try {
				info = acc->active_call->getInfo();
			}
			catch (...) {

			}
			finally{
			if (info.state == PJSIP_INV_STATE_CALLING || info.state == PJSIP_INV_STATE_EARLY) {
				active_call_box->Visible = true;

				call_time_label->Text = "Calling...";
				active_caller_id_label->Text = gcnew String(info.remoteUri.c_str());


			}
			else if (info.state == PJSIP_INV_STATE_CONFIRMED) {
				active_call_box->Visible = true;
				std::string temp_time = "";
				temp_time += std::to_string(info.totalDuration.sec / 60) + ":" + std::to_string(info.totalDuration.sec % 60);
				call_time_label->Text = gcnew String(temp_time.c_str());
				active_caller_id_label->Text = gcnew String(info.remoteUri.c_str());
			}
			else if (info.state == PJSIP_INV_STATE_DISCONNECTED || info.state == PJSIP_INV_STATE_NULL) {
				active_call_box->Visible = false;
				call_time_label->Text = "0:00";
				active_caller_id_label->Text = "No active call";
			}
			}
		}
		else {
			active_call_box->Visible = false;
			call_time_label->Text = "0:00";
			active_caller_id_label->Text = "No active call";
		}
	}
}
