#pragma once
#include <string>
#include <vector>
#include "Task.h"
#include "Date.h"



class Reminder {
private:
	Date reminderTime;
	std::string message;
	int taskID;

public:
	Reminder(int id, std::string msg, Date time);
	Date getTime();
	std::string getMessage();
	int getID();
	void setTime(Date _reminderTime);
	void setMessage(std::string _message);
	void setID(int _taskID);

};

class ReminderHandler {
public:
	ReminderHandler();
	std::string checkTime();
	std::vector<Reminder> getList();
	void addReminder(Reminder reminder);
	void deleteReminder(int taskID);
	void setDelay(Date delayTime);
	Date getDelay();
	//void toastNotification(std::string message);

private:
	
	std::vector<Reminder> reminderList;
	Date delayTime;
	//bool waitFlag;

	void sortList();
	//void removeReminder(Reminder reminder);
	
};
