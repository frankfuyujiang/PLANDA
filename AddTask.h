#pragma once
#include <iostream>
#include <string>
#include "Task.h"
#include "TaskHandling.h"
#include <msclr\marshal_cppstd.h>

namespace PLANDA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace PLANDA;

	/// <summary>
	/// Summary for AddTask
	/// </summary>
	public ref class AddTask : public System::Windows::Forms::Form
	{
	public: 
		AddTask(){
			//this->h = h;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddTask()
		{
			if (components)
			{
				delete components;
			}
		}
	
	//private: TaskHandling& h;
	private: System::Windows::Forms::Label^  name;
	protected:
	public: System::Windows::Forms::TextBox^  nametb;
	private: System::Windows::Forms::Label^  date;

	private: System::Windows::Forms::Label^  repeat;
	public: System::Windows::Forms::DateTimePicker^  datepicker;
	private: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::ComboBox^  typeselect;




	private: System::Windows::Forms::Label^  detail;
	private: System::Windows::Forms::Button^  donebutton;
	private: System::Windows::Forms::Button^  cancelbutton;

	private: System::Windows::Forms::Label^  remind;




	public: System::Windows::Forms::TextBox^  notetb;
	public: System::Windows::Forms::ComboBox^  reminddropbox;
	public: System::Windows::Forms::ComboBox^  repeatdropbox;

	public: Task* task;
	public: System::Windows::Forms::CheckBox^  boolpriority;





	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->name = (gcnew System::Windows::Forms::Label());
			this->nametb = (gcnew System::Windows::Forms::TextBox());
			this->date = (gcnew System::Windows::Forms::Label());
			this->repeat = (gcnew System::Windows::Forms::Label());
			this->datepicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->typeselect = (gcnew System::Windows::Forms::ComboBox());
			this->detail = (gcnew System::Windows::Forms::Label());
			this->donebutton = (gcnew System::Windows::Forms::Button());
			this->cancelbutton = (gcnew System::Windows::Forms::Button());
			this->remind = (gcnew System::Windows::Forms::Label());
			this->notetb = (gcnew System::Windows::Forms::TextBox());
			this->reminddropbox = (gcnew System::Windows::Forms::ComboBox());
			this->repeatdropbox = (gcnew System::Windows::Forms::ComboBox());
			this->boolpriority = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// name
			// 
			this->name->AutoSize = true;
			this->name->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(40, 54);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(69, 24);
			this->name->TabIndex = 55;
			this->name->Text = L"Name:";
			// 
			// nametb
			// 
			this->nametb->Location = System::Drawing::Point(105, 55);
			this->nametb->Name = L"nametb";
			this->nametb->Size = System::Drawing::Size(216, 20);
			this->nametb->TabIndex = 1;
			// 
			// date
			// 
			this->date->AutoSize = true;
			this->date->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date->Location = System::Drawing::Point(16, 85);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(100, 24);
			this->date->TabIndex = 10;
			this->date->Text = L"Due Date:";
			// 
			// repeat
			// 
			this->repeat->AutoSize = true;
			this->repeat->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->repeat->ForeColor = System::Drawing::Color::Black;
			this->repeat->Location = System::Drawing::Point(34, 196);
			this->repeat->Name = L"repeat";
			this->repeat->Size = System::Drawing::Size(78, 24);
			this->repeat->TabIndex = 6;
			this->repeat->Text = L"Repeat:";
			// 
			// datepicker
			// 
			this->datepicker->CustomFormat = L"yyyy MM-dd\'  \'HH:mm";
			this->datepicker->Location = System::Drawing::Point(105, 85);
			this->datepicker->Name = L"datepicker";
			this->datepicker->Size = System::Drawing::Size(216, 20);
			this->datepicker->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(48, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 24);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Type:";
			// 
			// typeselect
			// 
			this->typeselect->FormattingEnabled = true;
			this->typeselect->Location = System::Drawing::Point(105, 26);
			this->typeselect->Name = L"typeselect";
			this->typeselect->Size = System::Drawing::Size(216, 21);
			this->typeselect->TabIndex = 0;
			// 
			// detail
			// 
			this->detail->AutoSize = true;
			this->detail->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->detail->Location = System::Drawing::Point(42, 114);
			this->detail->Name = L"detail";
			this->detail->Size = System::Drawing::Size(68, 24);
			this->detail->TabIndex = 21;
			this->detail->Text = L"Notes:";
			// 
			// donebutton
			// 
			this->donebutton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->donebutton->Location = System::Drawing::Point(57, 327);
			this->donebutton->Name = L"donebutton";
			this->donebutton->Size = System::Drawing::Size(75, 25);
			this->donebutton->TabIndex = 8;
			this->donebutton->Text = L"Done";
			this->donebutton->UseVisualStyleBackColor = true;
			this->donebutton->Click += gcnew System::EventHandler(this, &AddTask::done_Click);
			// 
			// cancelbutton
			// 
			this->cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelbutton->Location = System::Drawing::Point(194, 327);
			this->cancelbutton->Name = L"cancelbutton";
			this->cancelbutton->Size = System::Drawing::Size(75, 25);
			this->cancelbutton->TabIndex = 9;
			this->cancelbutton->Text = L"Cancel";
			this->cancelbutton->UseVisualStyleBackColor = true;
			// 
			// remind
			// 
			this->remind->AutoSize = true;
			this->remind->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->remind->ForeColor = System::Drawing::Color::Black;
			this->remind->Location = System::Drawing::Point(29, 170);
			this->remind->Name = L"remind";
			this->remind->Size = System::Drawing::Size(84, 24);
			this->remind->TabIndex = 56;
			this->remind->Text = L"Remind:";
			// 
			// notetb
			// 
			this->notetb->Location = System::Drawing::Point(105, 115);
			this->notetb->Multiline = true;
			this->notetb->Name = L"notetb";
			this->notetb->Size = System::Drawing::Size(216, 48);
			this->notetb->TabIndex = 3;
			// 
			// reminddropbox
			// 
			this->reminddropbox->FormattingEnabled = true;
			this->reminddropbox->Location = System::Drawing::Point(105, 171);
			this->reminddropbox->Name = L"reminddropbox";
			this->reminddropbox->Size = System::Drawing::Size(216, 21);
			this->reminddropbox->TabIndex = 4;
			// 
			// repeatdropbox
			// 
			this->repeatdropbox->FormattingEnabled = true;
			this->repeatdropbox->Location = System::Drawing::Point(105, 196);
			this->repeatdropbox->Name = L"repeatdropbox";
			this->repeatdropbox->Size = System::Drawing::Size(216, 21);
			this->repeatdropbox->TabIndex = 5;
			// 
			// boolpriority
			// 
			this->boolpriority->AutoSize = true;
			this->boolpriority->Location = System::Drawing::Point(57, 239);
			this->boolpriority->Name = L"boolpriority";
			this->boolpriority->Size = System::Drawing::Size(95, 19);
			this->boolpriority->TabIndex = 6;
			this->boolpriority->Text = L"High Priority";
			this->boolpriority->UseVisualStyleBackColor = true;
			// 
			// AddTask
			// 
			this->AcceptButton = this->donebutton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelbutton;
			this->ClientSize = System::Drawing::Size(339, 365);
			this->Controls->Add(this->repeatdropbox);
			this->Controls->Add(this->reminddropbox);
			this->Controls->Add(this->notetb);
			this->Controls->Add(this->boolpriority);
			this->Controls->Add(this->remind);
			this->Controls->Add(this->cancelbutton);
			this->Controls->Add(this->donebutton);
			this->Controls->Add(this->detail);
			this->Controls->Add(this->typeselect);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->datepicker);
			this->Controls->Add(this->repeat);
			this->Controls->Add(this->date);
			this->Controls->Add(this->nametb);
			this->Controls->Add(this->name);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddTask";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"AddTask";
			this->Load += gcnew System::EventHandler(this, &AddTask::AddTask_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void done_Click(System::Object^  sender, System::EventArgs^  e) {
		//array<String^>^ classtypes = { "test", "quiz", "chore" };
		//this->typeselect->Items->AddRange(classtypes);
		//this->typeselect->DropDownStyle = ComboBoxStyle::DropDownList;
		//this->durationpicker->Format = DateTimePickerFormat::Custom;
		//this->repeattime->Format = DateTimePickerFormat::Custom;
				 /*
		int type;
		std::string Name; 
		std::string Note;
		int Duration; int remind; int repeat;
		bool ReqPrep; bool Segmentable; bool hPriority; bool allowreminder;
		Name = msclr::interop::marshal_as<std::string>(nametb->Text);
		Note = msclr::interop::marshal_as<std::string>(notetb->Text);
		Date Duedate = Date(datepicker->Value.Year, datepicker->Value.Month, datepicker->Value.Day, datepicker->Value.Hour, datepicker->Value.Minute);
		remind = reminddropbox->SelectedIndex;
		repeat = repeatdropbox->SelectedIndex;
		ReqPrep = boolpreparation->Checked;
		Segmentable = boolsegmentable->Checked;
		hPriority = boolpriority->Checked;
		allowreminder = boolreminderpop->Checked;
		type = typeselect->SelectedIndex;
		/*switch (type){
		case 0:
			//Quiz
			//mainwindow->addListView;
			break;
		case 1:
			//Assignment
			break;
		case 2:
			//Event
			break;
		case 3:
			//Chores
			break;
		default:
			break;
			//haven't selected
		}*/

		//
		//this->DialogResult^->set(1);//
		//task = Task(typestring, Name, Note, Duedate, ReminderTime::oneDay, RepeatTime::daily, 0, Segmentable, hPriority, false);
		//h.addTask(taskResult);
		//PLANDA::MainWindow::form.getTask(taskResult);
		//somehow send to task list from here.
		//Database db = Database::Database();
		//TaskHandling handler(&db);
		//handler.addTask(Task(typestring, Name, Note, Duedate, ReminderTime::oneDay, RepeatTime::daily, 0, Segmentable, hPriority, false));
		this->Close();

	}
	
private: System::Void AddTask_Load(System::Object^  sender, System::EventArgs^  e) {

			 this->datepicker->Format = DateTimePickerFormat::Custom;
			 
}
};
}
