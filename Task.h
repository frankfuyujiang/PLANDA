#pragma once
#include <string>
#include <vector>
#include <iostream>


#include "Date.h"
//#include "Reminder.h"


enum class ReminderTime { never, fifteenMin, thirtyMin, oneHour, oneDay };
enum class RepeatTime { never, daily, weekly, monthly };

class Task {
public:
	//Constructors
	Task(const std::string typeName, const std::string name, const std::string note, const Date dueDate, ReminderTime, RepeatTime, int prepTime, bool segmentable,	bool priorty, bool complete);
	Task();
	//Accessors
	std::string getTypeName();
	std::string getName();
	std::string getNote();
	Date getDueDateTime();
	ReminderTime getReminderTime();
	RepeatTime getRepeatTime();
	int getPrepTime() const;
	bool getSegmentable() const;
	bool getPriority() const;
	bool getComplete() const;
	Date getReminderDateTime();
	int getID() const;

	//Mutators
	void setTypeName(const std::string&);
	void setName(const std::string&);
	void setNote(const std::string&);
	void setDueDateTime(const Date&);
	void setReminderTime(ReminderTime);
	void setRepeatTime(RepeatTime);
	void setPrepTime(int);
	void setSegmentable(bool);
	void setPriority(bool);
	void setComplete(bool);
	void setID(int);
	//
	Task createTaskRepeat(); 
	void operator=(const Task &rhs);

private:
	//methods
	void updateReminderDateTime();
	//attributes
	std::string typeName;		//The name of the task type (make enum, maybe?)
	std::string name;			//The name of the task
	std::string note;			//A user written note about the task
	Date dueDate;		//The due date and time for the task
	ReminderTime reminderTime; //enum on how long before the event the reminder occurs;
	RepeatTime repeatTime;		//enum on when the task should be repeated (daily, weekly, or monthly)
	int prepTime;				//Duration of the task in minutes
	bool segmentable;			//True if task can be broken up into segments, false otherwise
	bool priority;				//True if task is a priority task (important task), false otherwise
	bool complete;				//True if task is completed, false otherwise
	Date reminderDateTime; 
	int ID;

};
