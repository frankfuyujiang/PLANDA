#pragma once
#include "Date.h"

namespace PLANDA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SmartList
	/// </summary>
	public ref class SmartList : public System::Windows::Forms::Form
	{
	public:
		SmartList(void)
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
		~SmartList()
		{
			if (components)
			{
				delete components;
			}
		}
	public: PLANDA::DateTime^ datetime;
	public: int selectedIndex;
	private: System::Windows::Forms::Label^  Label;
	private: System::Windows::Forms::Button^  Confirm;
	protected:

	protected:






	private: System::Windows::Forms::Button^  cancelbtn;
	private: System::Windows::Forms::Panel^  panel1;

	public: System::Windows::Forms::RadioButton^  smartReminderless;
	public: System::Windows::Forms::RadioButton^  smartOverdue;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Label = (gcnew System::Windows::Forms::Label());
			this->Confirm = (gcnew System::Windows::Forms::Button());
			this->cancelbtn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->smartReminderless = (gcnew System::Windows::Forms::RadioButton());
			this->smartOverdue = (gcnew System::Windows::Forms::RadioButton());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Label
			// 
			this->Label->AutoSize = true;
			this->Label->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label->Location = System::Drawing::Point(68, 37);
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(251, 24);
			this->Label->TabIndex = 2;
			this->Label->Text = L"Select a smart list to display";
			this->Label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Confirm
			// 
			this->Confirm->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->Confirm->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Confirm->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Confirm->ForeColor = System::Drawing::Color::White;
			this->Confirm->Location = System::Drawing::Point(40, 181);
			this->Confirm->Name = L"Confirm";
			this->Confirm->Size = System::Drawing::Size(133, 38);
			this->Confirm->TabIndex = 3;
			this->Confirm->Text = L"Load List";
			this->Confirm->UseVisualStyleBackColor = false;
			this->Confirm->Click += gcnew System::EventHandler(this, &SmartList::Confirm_Click);
			// 
			// cancelbtn
			// 
			this->cancelbtn->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->cancelbtn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelbtn->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->cancelbtn->ForeColor = System::Drawing::Color::White;
			this->cancelbtn->Location = System::Drawing::Point(215, 181);
			this->cancelbtn->Name = L"cancelbtn";
			this->cancelbtn->Size = System::Drawing::Size(133, 38);
			this->cancelbtn->TabIndex = 5;
			this->cancelbtn->Text = L"Cancel";
			this->cancelbtn->UseVisualStyleBackColor = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->smartReminderless);
			this->panel1->Controls->Add(this->smartOverdue);
			this->panel1->Location = System::Drawing::Point(40, 76);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(308, 81);
			this->panel1->TabIndex = 6;
			// 
			// smartReminderless
			// 
			this->smartReminderless->AutoSize = true;
			this->smartReminderless->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->smartReminderless->Location = System::Drawing::Point(15, 40);
			this->smartReminderless->Name = L"smartReminderless";
			this->smartReminderless->Size = System::Drawing::Size(291, 29);
			this->smartReminderless->TabIndex = 1;
			this->smartReminderless->TabStop = true;
			this->smartReminderless->Text = L"Tasks without early reminders";
			this->smartReminderless->UseVisualStyleBackColor = true;
			// 
			// smartOverdue
			// 
			this->smartOverdue->AutoSize = true;
			this->smartOverdue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->smartOverdue->Location = System::Drawing::Point(15, 14);
			this->smartOverdue->Name = L"smartOverdue";
			this->smartOverdue->Size = System::Drawing::Size(160, 29);
			this->smartOverdue->TabIndex = 0;
			this->smartOverdue->TabStop = true;
			this->smartOverdue->Text = L"Overdue tasks";
			this->smartOverdue->UseVisualStyleBackColor = true;
			// 
			// SmartList
			// 
			this->AcceptButton = this->Confirm;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->CancelButton = this->cancelbtn;
			this->ClientSize = System::Drawing::Size(386, 260);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->cancelbtn);
			this->Controls->Add(this->Confirm);
			this->Controls->Add(this->Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"SmartList";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"SmartList";
			this->Load += gcnew System::EventHandler(this, &SmartList::SmartList_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Confirm_Click(System::Object^  sender, System::EventArgs^  e) {
			//TODO: things!
		this->Close();
		}
	
	private: System::Void SmartList_Load(System::Object^  sender, System::EventArgs^  e) {
		/*array<String^>^ durationlist = { "15min", "30min", "45min", "1h", "1h 15min", "1h 30min", "1h 45min", "2h", "2h 15min", "2h 30min", "2h 45min", "3h" };
		this->durationdropbox->Items->AddRange(durationlist);
		this->durationdropbox->FormattingEnabled = true;
		durationdropbox->SelectedIndex = 0;
		selectedIndex = durationdropbox->SelectedIndex;*/
	}
};
}
