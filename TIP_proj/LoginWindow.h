#pragma once
#include <pjsua2.hpp>
#include <msclr\marshal_cppstd.h>
#include "MainWindow.h"
namespace TIPproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace pj;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class LoginWindow : public System::Windows::Forms::Form
	{
	public:
		LoginWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Label^ top_label;
	private: System::Windows::Forms::Button^ connect_buton;


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
			this->top_label = (gcnew System::Windows::Forms::Label());
			this->connect_buton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// server_textbox
			// 
			this->server_textbox->Location = System::Drawing::Point(117, 109);
			this->server_textbox->MaxLength = 15;
			this->server_textbox->Name = L"server_textbox";
			this->server_textbox->Size = System::Drawing::Size(100, 20);
			this->server_textbox->TabIndex = 0;
			this->server_textbox->Text = L"192.168.0.19";
			this->server_textbox->TextChanged += gcnew System::EventHandler(this, &LoginWindow::Server_textbox_TextChanged);
			// 
			// server_label
			// 
			this->server_label->AutoSize = true;
			this->server_label->Location = System::Drawing::Point(33, 112);
			this->server_label->Name = L"server_label";
			this->server_label->Size = System::Drawing::Size(78, 13);
			this->server_label->TabIndex = 1;
			this->server_label->Text = L"Server address";
			this->server_label->Click += gcnew System::EventHandler(this, &LoginWindow::Server_label_Click);
			// 
			// number_label
			// 
			this->number_label->AutoSize = true;
			this->number_label->Location = System::Drawing::Point(67, 138);
			this->number_label->Name = L"number_label";
			this->number_label->Size = System::Drawing::Size(44, 13);
			this->number_label->TabIndex = 2;
			this->number_label->Text = L"Number";
			this->number_label->Click += gcnew System::EventHandler(this, &LoginWindow::Label1_Click);
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Location = System::Drawing::Point(58, 164);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(53, 13);
			this->password_label->TabIndex = 3;
			this->password_label->Text = L"Password";
			// 
			// number_textbox
			// 
			this->number_textbox->Location = System::Drawing::Point(117, 135);
			this->number_textbox->MaxLength = 32;
			this->number_textbox->Name = L"number_textbox";
			this->number_textbox->Size = System::Drawing::Size(100, 20);
			this->number_textbox->TabIndex = 4;
			this->number_textbox->Text = L"9222";
			// 
			// password_textbox
			// 
			this->password_textbox->Location = System::Drawing::Point(117, 161);
			this->password_textbox->MaxLength = 32;
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->PasswordChar = '•';
			this->password_textbox->Size = System::Drawing::Size(100, 20);
			this->password_textbox->TabIndex = 5;
			this->password_textbox->Text = L"12345";
			this->password_textbox->UseSystemPasswordChar = true;
			// 
			// top_label
			// 
			this->top_label->AutoSize = true;
			this->top_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->top_label->Location = System::Drawing::Point(73, 39);
			this->top_label->Name = L"top_label";
			this->top_label->Size = System::Drawing::Size(194, 29);
			this->top_label->TabIndex = 6;
			this->top_label->Text = L"Enter credentials";
			// 
			// connect_buton
			// 
			this->connect_buton->Location = System::Drawing::Point(131, 221);
			this->connect_buton->Name = L"connect_buton";
			this->connect_buton->Size = System::Drawing::Size(75, 23);
			this->connect_buton->TabIndex = 7;
			this->connect_buton->Text = L"Connect";
			this->connect_buton->UseVisualStyleBackColor = true;
			this->connect_buton->Click += gcnew System::EventHandler(this, &LoginWindow::Connect_buton_Click);
			// 
			// LoginWindow
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(333, 289);
			this->Controls->Add(this->connect_buton);
			this->Controls->Add(this->top_label);
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

		if (password_textbox->Text == "") {
			MessageBox::Show("Enter correct credentials");
			return;
		}
		else {

		OpenMainWindow(server_textbox->Text, number_textbox->Text, password_textbox->Text);
		password_textbox->Text = "";
	}
	}
	private: void OpenMainWindow(String^ serverAddress, String^ number, String^ password) {
		TIPproj::MainWindow form;
		form.Location = this->Location;
		form.Region = this->Region;
		this->Hide();
		form.ShowDialog();

		this->Show();
	};
	};

}