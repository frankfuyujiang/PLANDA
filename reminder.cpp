#pragma once
#include "reminder.h"
#include "Task.h"
#include "time.h"
#include "Date.h"
#include <algorithm>

using namespace std;

struct sortKey {
	inline bool operator() (Reminder& struct1, Reminder& struct2) {
		return (struct1.getTime() > struct2.getTime());
	}
};


ReminderHandler::ReminderHandler() { 
	delayTime = Date(); 
	
}

Reminder::Reminder(int id, string msg, Date time) : taskID(id), message(msg), reminderTime(time) { }

void Reminder::setTime(Date _reminderTime) { reminderTime = _reminderTime; }
void Reminder::setMessage(string _message) { message = _message; }
void Reminder::setID(int _taskID) { taskID = _taskID; }
Date Reminder::getTime() { return reminderTime; }
string Reminder::getMessage() { return message; }
int Reminder::getID() { return taskID; }


string ReminderHandler::checkTime() {
	if (reminderList.empty())
		return "null";
	Date currTime = Date();
	Reminder nextReminder = reminderList.front();
	if (delayTime <= currTime) {
		if (currTime >= nextReminder.getTime()) {
			string tmp = nextReminder.getMessage();
			//reminderList.pop_back();
			reminderList.erase(reminderList.begin());
			//sortList();
			return tmp;
		}
		else
			return "null";
	}
	else
		return "null";
}

vector<Reminder> ReminderHandler::getList() { return reminderList; }
Date ReminderHandler::getDelay() { return delayTime; }
void ReminderHandler::setDelay(Date _delayTime) { delayTime = _delayTime; }
	
void ReminderHandler::addReminder(Reminder reminder) {
	reminderList.push_back(reminder);
	//sortList();
	sort(reminderList.begin(), reminderList.end(), sortKey());
	reverse(reminderList.begin(), reminderList.end());
}

void ReminderHandler::deleteReminder(int taskID) {
	//Go through reminderList and check for taskID, if the ID equals then delete that ID and resort
	for (int i = 0; i < reminderList.size(); i++) {
		if (reminderList[i].getID() == taskID) {
			reminderList.erase(reminderList.begin()+i);
			sortList();
		}
	}
}
	
void ReminderHandler::sortList() { //Basic insertion sort
	unsigned int i, j;
	for (i = 1; i < reminderList.size(); i++) {
		j = i-1;
		while (j > 0 && reminderList[j+1].getTime() > reminderList[i].getTime()) {
			Reminder temp = reminderList[j];
			reminderList[j] = reminderList[j+1];
			reminderList[j+1] = temp;
			j=j-1;
		}
	}
}
	
//void ReminderHandler::toastNotification(string message) {
	/*if (waitFlag) {
		delay(7);
		waitFlag = false;
	}
	
	NotificationWindow::PopupNotifier toast;
	toast.TitleText = "PLANDA";
	toast.ContentText = "This is a notification!";
	//toast.ContentText = message; //BUG!
	toast.ShowCloseButton = false;
	toast.Delay = 5000;
	toast.AnimationDuration = 1000;
	toast.AnimationInterval = 15;
	toast.Scroll = false;
	toast.Image = System::Drawing::Image::FromFile("panda.jpeg");
	toast.Popup();
	*/
	//waitFlag = true;
//}