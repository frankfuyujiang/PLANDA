#pragma once
#include <vector>
#include "Database.h"
#include "TaskHandling.h"
#include "AddTask.h"
#include "SmartList.h"
#include "reminder.h"
#include "Date.h"
#include "Task.h"

#include "time.h"
#include <string>


namespace PLANDA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace NotificationWindow;
	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			db = new Database();
			handler = new TaskHandling(db);
			reminderList = new ReminderHandler();
			startFlag = false;
			InitializeComponent();
			if (!startFlag) {
				backgroundWorker->RunWorkerAsync();
				startFlag = true;
			}
			//
			//TODO: Add the constructor code here
			//
		}
		void toastNotify(String^ message) {
			toast.TitleText = "PLANDA";
			message = "Notification: " + message;
			toast.ContentText = message;
			toast.ShowCloseButton = false;
			toast.Delay = 4000;
			toast.AnimationDuration = 1000;
			toast.AnimationInterval = 15;
			toast.Scroll = false;
			toast.Image = System::Drawing::Image::FromFile("panda.jpeg");
			toast.Popup();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:System::Windows::Forms::ListView^  tasklist;
	private: System::Windows::Forms::Button^  add;

	private: System::Windows::Forms::Button^  smartlist;
	private: System::Windows::Forms::Button^  dnd;



	private: System::Windows::Forms::Button^  setting;
	private: System::Windows::Forms::ComboBox^  filter;


	private: System::Windows::Forms::MenuItem^  settingsMenuItem;
	private: System::Windows::Forms::MenuItem^  createTemplateMenuItem;
	private: System::Windows::Forms::MenuItem^  repeatNotificationMenuItem;
	private: System::Windows::Forms::MenuItem^  quitMenuItem;
	private: System::Windows::Forms::Button^  refresh;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ColumnHeader^  task;
	private: System::Windows::Forms::ColumnHeader^  duedate;
	private: System::Windows::Forms::ColumnHeader^  details;
	private: System::Windows::Forms::ContextMenuStrip^  tasklistmenu;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker;
	private: System::ComponentModel::IContainer^  components;
	//public: TaskHandling* handler;
	//public: Database* db;
		ReminderHandler* reminderList;
		bool startFlag;
//	private: System::ComponentModel::IContainer^  components;
		/// <summary>
		/// Required designer variable.
		/// </summary>
	private: 
			 Database* db;
	private: System::Windows::Forms::ToolStripMenuItem^  completedToolStripMenuItem;
	private: System::Windows::Forms::Label^  pandaMood;
			 TaskHandling* handler;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->tasklist = (gcnew System::Windows::Forms::ListView());
			this->task = (gcnew System::Windows::Forms::ColumnHeader());
			this->duedate = (gcnew System::Windows::Forms::ColumnHeader());
			this->details = (gcnew System::Windows::Forms::ColumnHeader());
			this->tasklistmenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->completedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->add = (gcnew System::Windows::Forms::Button());
			this->smartlist = (gcnew System::Windows::Forms::Button());
			this->dnd = (gcnew System::Windows::Forms::Button());
			this->setting = (gcnew System::Windows::Forms::Button());
			this->filter = (gcnew System::Windows::Forms::ComboBox());
			this->refresh = (gcnew System::Windows::Forms::Button());
			this->settingsMenuItem = (gcnew System::Windows::Forms::MenuItem());
			this->quitMenuItem = (gcnew System::Windows::Forms::MenuItem());
			this->createTemplateMenuItem = (gcnew System::Windows::Forms::MenuItem());
			this->repeatNotificationMenuItem = (gcnew System::Windows::Forms::MenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pandaMood = (gcnew System::Windows::Forms::Label());
			this->tasklistmenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// backgroundWorker
			// 
			this->backgroundWorker->WorkerReportsProgress = true;
			this->backgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::backgroundWorker_DoWork);
			this->backgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainWindow::backgroundWorker_ProgressChanged);
			// 
			// tasklist
			// 
			this->tasklist->Alignment = System::Windows::Forms::ListViewAlignment::SnapToGrid;
			this->tasklist->BackColor = System::Drawing::Color::White;
			this->tasklist->BackgroundImageTiled = true;
			this->tasklist->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->task, this->duedate,
					this->details
			});
			this->tasklist->ContextMenuStrip = this->tasklistmenu;
			this->tasklist->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tasklist->Location = System::Drawing::Point(28, 47);
			this->tasklist->Name = L"tasklist";
			this->tasklist->Size = System::Drawing::Size(400, 455);
			this->tasklist->TabIndex = 0;
			this->tasklist->TileSize = System::Drawing::Size(379, 80);
			this->tasklist->UseCompatibleStateImageBehavior = false;
			this->tasklist->View = System::Windows::Forms::View::Tile;
			// 
			// task
			// 
			this->task->Text = L"Tasks";
			// 
			// duedate
			// 
			this->duedate->Text = L"Due Date";
			// 
			// details
			// 
			this->details->Text = L"Description";
			this->details->Width = 130;
			// 
			// tasklistmenu
			// 
			this->tasklistmenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->editToolStripMenuItem,
					this->deleteToolStripMenuItem, this->completedToolStripMenuItem
			});
			this->tasklistmenu->Name = L"tasklistmenu";
			this->tasklistmenu->Size = System::Drawing::Size(153, 76);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->editToolStripMenuItem->Text = L"Edit";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::editToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::deleteToolStripMenuItem_Click);
			// 
			// completedToolStripMenuItem
			// 
			this->completedToolStripMenuItem->Name = L"completedToolStripMenuItem";
			this->completedToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->completedToolStripMenuItem->Text = L"Completed";
			this->completedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::completedToolStripMenuItem_Click);
			// 
			// add
			// 
			this->add->BackColor = System::Drawing::Color::Transparent;
			this->add->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"add.BackgroundImage")));
			this->add->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->add->Cursor = System::Windows::Forms::Cursors::Default;
			this->add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add->ForeColor = System::Drawing::Color::Transparent;
			this->add->Location = System::Drawing::Point(470, 73);
			this->add->Name = L"add";
			this->add->Size = System::Drawing::Size(205, 50);
			this->add->TabIndex = 1;
			this->add->Text = L"+ ADD";
			this->add->UseVisualStyleBackColor = false;
			this->add->Click += gcnew System::EventHandler(this, &MainWindow::addbutton_Click);
			// 
			// smartlist
			// 
			this->smartlist->BackColor = System::Drawing::Color::Transparent;
			this->smartlist->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"smartlist.BackgroundImage")));
			this->smartlist->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->smartlist->Cursor = System::Windows::Forms::Cursors::Default;
			this->smartlist->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->smartlist->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->smartlist->ForeColor = System::Drawing::Color::Transparent;
			this->smartlist->Location = System::Drawing::Point(470, 140);
			this->smartlist->Name = L"smartlist";
			this->smartlist->Size = System::Drawing::Size(205, 50);
			this->smartlist->TabIndex = 5;
			this->smartlist->Text = L"SMART LIST";
			this->smartlist->UseVisualStyleBackColor = false;
			this->smartlist->Click += gcnew System::EventHandler(this, &MainWindow::smartlist_Click);
			// 
			// dnd
			// 
			this->dnd->BackColor = System::Drawing::Color::Transparent;
			this->dnd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dnd.BackgroundImage")));
			this->dnd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->dnd->Cursor = System::Windows::Forms::Cursors::Default;
			this->dnd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dnd->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dnd->ForeColor = System::Drawing::Color::Transparent;
			this->dnd->Location = System::Drawing::Point(470, 207);
			this->dnd->Name = L"dnd";
			this->dnd->Size = System::Drawing::Size(205, 50);
			this->dnd->TabIndex = 6;
			this->dnd->Text = L"DO NOT DISTURB";
			this->dnd->UseVisualStyleBackColor = false;
			this->dnd->Click += gcnew System::EventHandler(this, &MainWindow::dnd_Click);
			// 
			// setting
			// 
			this->setting->BackColor = System::Drawing::Color::Transparent;
			this->setting->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"setting.BackgroundImage")));
			this->setting->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->setting->Cursor = System::Windows::Forms::Cursors::Default;
			this->setting->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->setting->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->setting->ForeColor = System::Drawing::Color::Transparent;
			this->setting->Location = System::Drawing::Point(635, 27);
			this->setting->Name = L"setting";
			this->setting->Size = System::Drawing::Size(40, 40);
			this->setting->TabIndex = 7;
			this->setting->UseVisualStyleBackColor = false;
			this->setting->Click += gcnew System::EventHandler(this, &MainWindow::setting_Click);
			// 
			// filter
			// 
			this->filter->FormattingEnabled = true;
			this->filter->Location = System::Drawing::Point(283, 21);
			this->filter->Name = L"filter";
			this->filter->Size = System::Drawing::Size(109, 21);
			this->filter->TabIndex = 8;
			this->filter->Text = L"Select Filter";
			// 
			// refresh
			// 
			this->refresh->BackColor = System::Drawing::Color::Transparent;
			this->refresh->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"refresh.BackgroundImage")));
			this->refresh->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->refresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->refresh->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold));
			this->refresh->ForeColor = System::Drawing::Color::Transparent;
			this->refresh->Location = System::Drawing::Point(398, 22);
			this->refresh->Name = L"refresh";
			this->refresh->Size = System::Drawing::Size(24, 19);
			this->refresh->TabIndex = 9;
			this->refresh->Text = L"button1";
			this->refresh->UseVisualStyleBackColor = false;
			this->refresh->Click += gcnew System::EventHandler(this, &MainWindow::refresh_Click);
			// 
			// settingsMenuItem
			// 
			this->settingsMenuItem->Index = -1;
			this->settingsMenuItem->Text = L"Settings";
			this->settingsMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::settings_Click);
			// 
			// quitMenuItem
			// 
			this->quitMenuItem->Index = -1;
			this->quitMenuItem->Text = L"Quit";
			this->quitMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::quit_Click);
			// 
			// createTemplateMenuItem
			// 
			this->createTemplateMenuItem->Index = -1;
			this->createTemplateMenuItem->Text = L"";
			// 
			// repeatNotificationMenuItem
			// 
			this->repeatNotificationMenuItem->Index = -1;
			this->repeatNotificationMenuItem->Text = L"Repeat Notification";
			this->repeatNotificationMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::repeatNotification_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(470, 322);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(205, 183);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// pandaMood
			// 
			this->pandaMood->AutoSize = true;
			this->pandaMood->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pandaMood->Location = System::Drawing::Point(465, 290);
			this->pandaMood->Name = L"pandaMood";
			this->pandaMood->Size = System::Drawing::Size(162, 29);
			this->pandaMood->TabIndex = 11;
			this->pandaMood->Text = L"Panda mood: ";
			// 
			// MainWindow
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(709, 517);
			this->Controls->Add(this->pandaMood);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->refresh);
			this->Controls->Add(this->filter);
			this->Controls->Add(this->setting);
			this->Controls->Add(this->dnd);
			this->Controls->Add(this->smartlist);
			this->Controls->Add(this->add);
			this->Controls->Add(this->tasklist);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->Text = L"PLANDA";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->tasklistmenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Reminder section
		private: NotificationWindow::PopupNotifier toast;
		private: System::Void backgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			while (true) {
				if (!reminderList->getList().empty()) {
					Date curr = Date();
					string tmeMsg = reminderList->checkTime();
				// int id = taskList->getDeleteReminderID();
					if (tmeMsg != "null") {
						//CHANGE MESSAGE TO 'note' FROM ADD TASK
						std::string msg = tmeMsg + ", Current: " + std::to_string(curr.getHour()) + ":" + std::to_string(curr.getMinute());
						System::String^ str = gcnew String(msg.c_str());
						backgroundWorker->ReportProgress(0, str);
					}
				}
			/*
			if (id != 0) {
			reminderList->deleteReminder(id);
			taskList->setDeleteReminderID(0);
			}
			*/
				Threading::Thread::Sleep(7000);
			}
		}
		private: System::Void backgroundWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			String^ msg = e->UserState->ToString();
			toastNotify(msg);
		}

//end reminder
/*
	// Make task... called task!!! ...however thats done, minus the setNote, i'm doing that here:
	taskList->addTask(task);
	string note = task->getName() + " at " + task->getDueDateTime().hour() + ":" + task->getDueDateTime().minute();
	task->setNote(note);
	reminderList->addReminder(task->getID(), task->getNote(), task->getReminderTime());
	//You may need to edit this abit, but this is the logic of it all!
*/

	private: System::Void addbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		AddTask ^add = gcnew AddTask();			//*handler
		
		array<String^>^ classtypes = { "test", "assignment", "event", "chore" };
		add->typeselect->Items->AddRange(classtypes);
		add->typeselect->DropDownStyle = ComboBoxStyle::DropDownList;
		add->typeselect->SelectedIndex = 0;
		array<String^>^ remindchoices = { "When Due", "15 minuntes before", "30 minuntes before", "1 hour before", "1 day before" };
		add->reminddropbox->Items->AddRange(remindchoices);
		add->reminddropbox->DropDownStyle = ComboBoxStyle::DropDownList;
		add->reminddropbox->SelectedIndex = 0;
		array<String^>^ repeatchoices = { "Never", "Daily", "Weekly", "Monthly" };
		add->repeatdropbox->Items->AddRange(repeatchoices);
		add->repeatdropbox->DropDownStyle = ComboBoxStyle::DropDownList;
		add->repeatdropbox->SelectedIndex = 0;

		add->ShowDialog();

		if (add->DialogResult == Windows::Forms::DialogResult::OK) {
			/*Task newTask = *add->getTask();
			handler->addTask(newTask);*/
			//Database db = Database::Database();
			//TaskHandling handler(&db);
			int type;
			std::string Name;
			std::string Note;
			std::string typestring;
			int remind; int repeat;
			bool ReqPrep; bool Segmentable=true; bool hPriority; bool allowreminder;
			Name = msclr::interop::marshal_as<std::string>(add->nametb->Text);
			Note = msclr::interop::marshal_as<std::string>(add->notetb->Text);
			Date Duedate = Date(add->datepicker->Value.Year, add->datepicker->Value.Month, add->datepicker->Value.Day, add->datepicker->Value.Hour, add->datepicker->Value.Minute);
			remind = add->reminddropbox->SelectedIndex;
			repeat = add->repeatdropbox->SelectedIndex;
			
			hPriority = add->boolpriority->Checked;
			type = add->typeselect->SelectedIndex;
			switch (type){
			case 0: typestring = "test";
				break;
			case 1:
				typestring = "assignment";
				break;
			case 2:
				typestring = "event";
				break;
			case 3:
				typestring = "chore";
				break;
			default:
				typestring = "test";
			}
			//std::string typestring = "test";
			ReminderTime remindtime;
			switch (remind){
			case 0:
				remindtime = ReminderTime::never;
				break;
			case 1:
				remindtime = ReminderTime::fifteenMin;
				break;
			case 2:
				remindtime = ReminderTime::thirtyMin;;
				break;
			case 3:
				remindtime = ReminderTime::oneHour;
				break;
			case 4:
				remindtime = ReminderTime::oneDay;
				break;
			default:
				remindtime = ReminderTime::never;;
			}
			RepeatTime repeattime;
			switch (repeat){
			case 0:
				repeattime=RepeatTime::never;
				break;
			case 1:
				repeattime=RepeatTime::daily;
				break;
			case 2:
				repeattime=RepeatTime::weekly;
				break;
			case 3:
				repeattime=RepeatTime::monthly;
				break;
			default:
				repeattime=RepeatTime::never;
			}

			Task newTask = Task(typestring, Name, Note, Duedate, remindtime, repeattime, 0, Segmentable, hPriority, false);
			handler->addTask(newTask);
			string note = Name + " at " + to_string(Duedate.getHour()) + ":" + to_string(Duedate.getMinute());
			
			reminderList->addReminder(Reminder(newTask.getID(), note, newTask.getReminderDateTime()));

			this->tasklist->Items->Clear();
			this->tasklist->Items->AddRange(addListView());

		}
	}
	private: System::Void setting_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::ContextMenu^ buttonMenu = gcnew System::Windows::Forms::ContextMenu();
		buttonMenu->MenuItems->Add(settingsMenuItem);
		//buttonMenu->MenuItems->Add(createTemplateMenuItem);
		//buttonMenu->MenuItems->Add(repeatNotificationMenuItem);
		buttonMenu->MenuItems->Add(quitMenuItem);
		buttonMenu->Show(setting, System::Drawing::Point(20, 20));
	}
	private: System::Void settings_Click(System::Object^  sender, System::EventArgs^  e) {
		//			array<String^>^ classtypes = { "test", "quiz", "chore"};
		//			this->filter->Items->AddRange(classtypes);
		//			this->filter->DropDownStyle = ComboBoxStyle::DropDownList;
	}
	private: System::Void repeatNotification_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void quit_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	public:  array< System::Windows::Forms::ListViewItem^>^ addListView(){
		vector<Task> tasks = handler->getDisplayList();
		int size = tasks.size();
		array<System::Windows::Forms::ListViewItem^>^ ListArray = gcnew cli::array< System::Windows::Forms::ListViewItem^>(size);
		int i;
		String^ title;
		String^ duedatetime;
		String^ Description;
		for (i = 0; i < size; i++){
			title = Marshal::PtrToStringAnsi(static_cast<IntPtr>(const_cast<char *>((tasks.at(i).getName()).c_str())));
			duedatetime = Marshal::PtrToStringAnsi(static_cast<IntPtr>(const_cast<char *>((tasks.at(i).getDueDateTime().toString()).c_str()))); 
			Description = Marshal::PtrToStringAnsi(static_cast<IntPtr>(const_cast<char *>((tasks.at(i).getNote()).c_str()))); 
			if (Description->Length < 68){
				Description = Description + gcnew String(' ',(68 - Description->Length));
			}
			if ((tasks.at(i)).getTypeName() == "test"){
				ListArray[i] = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::Windows::Forms::ListViewItem::ListViewSubItem^  >(3) {
					(gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						title, System::Drawing::SystemColors::WindowText, System::Drawing::ColorTranslator::FromHtml("#FFADAD"), (gcnew System::Drawing::Font(L"Arial",
						15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						duedatetime, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White, (gcnew System::Drawing::Font(L"Arial",
						12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						Description, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White,
						(gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)))))
				}, -1));
					
			}else if (tasks.at(i).getTypeName() == "chore"){
				ListArray[i] = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::Windows::Forms::ListViewItem::ListViewSubItem^  >(3) {
					(gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						title, System::Drawing::SystemColors::WindowText, System::Drawing::Color::Silver, (gcnew System::Drawing::Font(L"Arial",
						15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						duedatetime, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White, (gcnew System::Drawing::Font(L"Arial",
						12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						Description, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White,
						(gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)))))
				}, -1));
			}else if (tasks.at(i).getTypeName() == "assignment"){
				ListArray[i] = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::Windows::Forms::ListViewItem::ListViewSubItem^  >(3) {
					(gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						title, System::Drawing::SystemColors::WindowText, System::Drawing::Color::Khaki, (gcnew System::Drawing::Font(L"Arial",
						15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						duedatetime, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White, (gcnew System::Drawing::Font(L"Arial",
						12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						Description, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White,
						(gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)))))
				}, -1));
			}else if (tasks.at(i).getTypeName() == "event"){
				ListArray[i] = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::Windows::Forms::ListViewItem::ListViewSubItem^  >(3) {
					(gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						title, System::Drawing::SystemColors::WindowText, System::Drawing::Color::LightBlue, (gcnew System::Drawing::Font(L"Arial",
						15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						duedatetime, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White, (gcnew System::Drawing::Font(L"Arial",
						12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr,
						Description, System::Drawing::SystemColors::WindowText, System::Drawing::Color::White,
						(gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)))))
				}, -1));
			}else{
					//error
			}
		};
		return ListArray;
	}
	private: System::Void smartlist_Click(System::Object^  sender, System::EventArgs^  e) {
		SmartList ^sl = gcnew SmartList();
		sl->ShowDialog();
		//smartList->FormClosed += gcnew FormClosedEventHandler();
		if (sl->DialogResult == Windows::Forms::DialogResult::OK) {
			handler->loadListsFromDatabase();
			if (sl->smartReminderless->Checked){
				handler->makeSmartList(SmartListType::noReminder);
			}/*
			else if(sl->smartHour->Checked){
				handler->makeSmartList(SmartListType::hour);
			}*/
			else if (sl->smartOverdue->Checked){
				handler->makeSmartList(SmartListType::overdue);
			}
			tasklist->Items->Clear();
			tasklist->Items->AddRange(addListView());
		}

	}
	private: System::Void dnd_Click(System::Object^  sender, System::EventArgs^  e) {
		this->WindowState = FormWindowState::Minimized;
		Date delay = Date();
		vector<int> timeDelay;
		timeDelay.push_back(0); 
		timeDelay.push_back(0); 
		timeDelay.push_back(0); 
		timeDelay.push_back(0);
		timeDelay.push_back(30); //30min delay
		delay = delay + timeDelay;
		reminderList->setDelay(delay);
	}
	private: System::Void refresh_Click(System::Object^ sender, System::EventArgs^ e){
				 handler->loadListsFromDatabase();
		switch (filter->SelectedIndex){
		case 0:
			handler->filterDisplayList(FilterType::event);
			break;
		case 1:
			handler->filterDisplayList(FilterType::chore);
			break;
			
		case 2:
			handler->filterDisplayList(FilterType::test);
			//addListView(*handler);
			break;
		case 3:
			handler->filterDisplayList(FilterType::assignment);
			//addListView(*handler);
			break;
		case 4:
			handler->filterDisplayList(FilterType::priority);
			//addListView(*handler);
			break;
		case 5:
			break;
		default:
			handler->filterDisplayList(FilterType::priority);
		}
		tasklist->Items->Clear();
		tasklist->Items->AddRange(addListView());
	}
private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
			 array<String^>^ classtypes = { "Event", "Chore","Test","Assignment" ,"High Priority","All" };
			 this->filter->Items->AddRange(classtypes);
			 this->filter->DropDownStyle = ComboBoxStyle::DropDownList;
			 this->filter->Text = "Select Filter";
			 tasklist->Items->AddRange(addListView());
	

			 if (handler->petPanda.getMood() > 85){
				 pandaMood->Text = "Panda mood: Very Happy!";
				 // pictureBox1->Image = Image::FromFile("panda.jpeg");
			 }
			 else if (handler->petPanda.getMood() > 65){
				 pandaMood->Text = "Panda mood: Happy!";
				 //pictureBox1->Image = Image::FromFile("panda.jpeg");
			 }
			 else if (handler->petPanda.getMood() > 50){
				 pandaMood->Text = "Panda mood: Satisfied!";
				 //		 pictureBox1->Image = Image::FromFile("panda.jpeg");
			 }
			 else if (handler->petPanda.getMood() > 25){
				 pandaMood->Text = "Panda mood: Concerned!";
				 //		 pictureBox1->Image = Image::FromFile("sleepy_panda.png");
			 }
			 else if (handler->petPanda.getMood() > 10){
				 pandaMood->Text = "Panda mood: Sad!";
				 //		 pictureBox1->Image = Image::FromFile("sleepy_panda.png");
			 }
			 else {
				 pandaMood->Text = "Panda mood: Very Sad!";
				 //		 pictureBox1->Image = Image::FromFile("sleepy_panda.png");
			 }

}

public: TaskHandling& MainWindow::passTaskList(){
			return *handler;
}
private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 vector<Task> tasks = handler->getDisplayList();
			 if (tasklist->SelectedItems->Count == 0){

			 }
			 else{
				 int counter = tasklist->SelectedIndices[0];
				 handler->deleteTask(tasks.at(counter));
				 tasklist->Items->Clear();
				 tasklist->Items->AddRange(addListView());
			 }
			//<tasks.size())
}
private: System::Void editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 vector<Task> tasks = handler->getDisplayList();
			 if (tasklist->SelectedItems->Count == 0){

			 }
			 else{
				 int counter = tasklist->SelectedIndices[0];
				 Task temptask = tasks.at(counter);
				 AddTask ^add = gcnew AddTask();			//*handler

				 array<String^>^ classtypes = { "test", "assignment", "event", "chore" };
				 add->typeselect->Items->AddRange(classtypes);
				 add->typeselect->DropDownStyle = ComboBoxStyle::DropDownList;
				 add->typeselect->SelectedIndex = 0;
				 array<String^>^ remindchoices = { "When Due", "15 minuntes before", "30 minuntes before", "1 hour before", "1 day before" };
				 add->reminddropbox->Items->AddRange(remindchoices);
				 add->reminddropbox->DropDownStyle = ComboBoxStyle::DropDownList;
				 add->reminddropbox->SelectedIndex = 0;
				 array<String^>^ repeatchoices = { "Never", "Daily", "Weekly", "Monthly" };
				 add->repeatdropbox->Items->AddRange(repeatchoices);
				 add->repeatdropbox->DropDownStyle = ComboBoxStyle::DropDownList;
				 add->repeatdropbox->SelectedIndex = 0;

				 add->nametb->Text = Marshal::PtrToStringAnsi(static_cast<IntPtr>(const_cast<char *>((temptask.getName()).c_str())));
				 add->notetb->Text = Marshal::PtrToStringAnsi(static_cast<IntPtr>(const_cast<char *>((temptask.getNote()).c_str())));
				 add->datepicker->Value = DateTime(temptask.getDueDateTime().getYear(), temptask.getDueDateTime().getMonth(), temptask.getDueDateTime().getDay(), temptask.getDueDateTime().getHour(), temptask.getDueDateTime().getMinute(),0);
				 Date Duedate = Date(add->datepicker->Value.Year, add->datepicker->Value.Month, add->datepicker->Value.Day, add->datepicker->Value.Hour, add->datepicker->Value.Minute);
				 int reminderindex;
				 switch (temptask.getReminderTime()){
				 case ReminderTime::never:
					 reminderindex = 0;
					 break;
				 case ReminderTime::fifteenMin:
					 reminderindex = 1;
					 break;
				 case ReminderTime::thirtyMin:
					 reminderindex = 2;
					 break;
				 case ReminderTime::oneHour:
					 reminderindex = 3;
					 break;
				 case ReminderTime::oneDay:
					 reminderindex = 4;
					 break;
				 default:
					 reminderindex = 0;
				 }
				 add->reminddropbox->SelectedIndex = reminderindex;
				 int repeatindex;
				 switch (temptask.getRepeatTime()){
				 case RepeatTime::never:
					 repeatindex = 0;
					 break;
				 case RepeatTime::daily:
					 repeatindex = 1;
					 break;
				 case RepeatTime::weekly:
					 repeatindex = 2;
					 break;
				 case RepeatTime::monthly:
					 repeatindex = 3;
					 break;
				 default:
					 repeatindex = 0;
				 }
				 add->repeatdropbox->SelectedIndex=repeatindex;
				 
		
				 add->boolpriority->Checked=temptask.getPriority();
				 int typeindex;
				 std::string Typename = temptask.getTypeName();
				 if (Typename=="test"){
					 typeindex = 0;
				 }
				 else if (Typename == "assignment"){
					 typeindex = 1;
				 }
				 else if (Typename == "event"){
					 typeindex = 2;
				 }
				 else{
					 typeindex = 3;
				 }
				 add->typeselect->SelectedIndex = typeindex;
				 add->ShowDialog();

				 if (add->DialogResult == Windows::Forms::DialogResult::OK) {
					 /*Task newTask = *add->getTask();
					 handler->addTask(newTask);*/
					 //Database db = Database::Database();
					 //TaskHandling handler(&db);
					 handler->deleteTask(tasks.at(counter));

					 int type;
					 std::string Name;
					 std::string Note;
					 std::string typestring;
					 int remind; int repeat;
					 bool ReqPrep; bool Segmentable = true; bool hPriority; bool allowreminder;
					 Name = msclr::interop::marshal_as<std::string>(add->nametb->Text);
					 Note = msclr::interop::marshal_as<std::string>(add->notetb->Text);
					 Date Duedate = Date(add->datepicker->Value.Year, add->datepicker->Value.Month, add->datepicker->Value.Day, add->datepicker->Value.Hour, add->datepicker->Value.Minute);
					 remind = add->reminddropbox->SelectedIndex;
					 repeat = add->repeatdropbox->SelectedIndex;
					 hPriority = add->boolpriority->Checked;
					 type = add->typeselect->SelectedIndex;
					 switch (type){
					 case 0: typestring = "test";
						 break;
					 case 1:
						 typestring = "assignment";
						 break;
					 case 2:
						 typestring = "event";
						 break;
					 case 3:
						 typestring = "chore";
						 break;
					 default:
						 typestring = "test";
					 }
					 //std::string typestring = "test";
					 ReminderTime remindtime;
					 switch (remind){
					 case 0:
						 remindtime = ReminderTime::never;
						 break;
					 case 1:
						 remindtime = ReminderTime::fifteenMin;
						 break;
					 case 2:
						 remindtime = ReminderTime::thirtyMin;;
						 break;
					 case 3:
						 remindtime = ReminderTime::oneHour;
						 break;
					 case 4:
						 remindtime = ReminderTime::oneDay;
						 break;
					 default:
						 remindtime = ReminderTime::never;;
					 }
					 RepeatTime repeattime;
					 switch (repeat){
					 case 0:
						 repeattime=RepeatTime::never;
						 break;
					 case 1:
						 repeattime=RepeatTime::daily;
						 break;
					 case 2:
						 repeattime=RepeatTime::weekly;
						 break;
					 case 3:
						 repeattime=RepeatTime::monthly;
						 break;
					 default:
						 repeattime=RepeatTime::never;
					 }

					 Task newTask = Task(typestring, Name, Note, Duedate, remindtime, repeattime, 0, Segmentable, hPriority, false);
					 handler->addTask(newTask);
					 string note = Name + " at " + to_string(Duedate.getHour()) + ":" + to_string(Duedate.getMinute());

					 reminderList->addReminder(Reminder(newTask.getID(), note, newTask.getReminderDateTime()));

					 this->tasklist->Items->Clear();
					 this->tasklist->Items->AddRange(addListView());

				 }
			 }

}
private: System::Void completedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 vector<Task> tasks = handler->getDisplayList();
			 if (tasklist->SelectedItems->Count == 0){

			 }
			 else{
				 int counter = tasklist->SelectedIndices[0];
				 Task temptask = tasks.at(counter);
				 Task temptask2 = temptask;
				 temptask2.setID(NULL);
				
				 vector<int> repeatTime = { 0, 0, 0, 0, 0 };
				 switch (temptask2.getRepeatTime()){
				 case RepeatTime::never:
					 break;
				 case RepeatTime::daily:
					 repeatTime = { 0, 0, 1, 0, 0 };
					 temptask2.setDueDateTime(temptask2.getDueDateTime() + repeatTime);
					 handler->addTask(temptask2);
					 break;
				 case RepeatTime::weekly:
					 repeatTime = { 0, 0, 7, 0, 0 };
					 temptask2.setDueDateTime(temptask2.getDueDateTime() + repeatTime);
					 handler->addTask(temptask2);
					 break;
				 case RepeatTime::monthly:
					 repeatTime = { 0, 1, 0, 0, 0 };
					 temptask2.setDueDateTime(temptask2.getDueDateTime() + repeatTime);
					 handler->addTask(temptask2);
					 break;
				 default:
					 break;
				 }

				 handler->completeTask(temptask);
				 handler->deleteTask(temptask);
				 tasklist->Items->Clear();
				 tasklist->Items->AddRange(addListView());


				 if (handler->petPanda.getMood() > 85){
					 pandaMood->Text = "Panda mood: Very Happy!";
					// pictureBox1->Image = Image::FromFile("panda.jpeg");
				 }
				 else if (handler->petPanda.getMood() > 65){
					 pandaMood->Text = "Panda mood: Happy!";
					 //pictureBox1->Image = Image::FromFile("panda.jpeg");
				 }
				 else if (handler->petPanda.getMood() > 50){
					 pandaMood->Text = "Panda mood: Satisfied!";
			//		 pictureBox1->Image = Image::FromFile("panda.jpeg");
				 }
				 else if (handler->petPanda.getMood() > 25){
					 pandaMood->Text = "Panda mood: Concerned!";
			//		 pictureBox1->Image = Image::FromFile("sleepy_panda.png");
				 }
				 else if (handler->petPanda.getMood() > 10){
					 pandaMood->Text = "Panda mood: Sad!";
			//		 pictureBox1->Image = Image::FromFile("sleepy_panda.png");
				 }
				 else {
					 pandaMood->Text = "Panda mood: Very Sad!";
			//		 pictureBox1->Image = Image::FromFile("sleepy_panda.png");
				 }

			 }
}


};
}
