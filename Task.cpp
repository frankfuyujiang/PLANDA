// Task.cpp : Defines the entry point for the console application.
//
# pragma once
#include "Task.h"


Task::Task(const std::string givenTypeName, const std::string givenName, const std::string givenNote, const Date givenDueDate, ReminderTime givenReminderTime, RepeatTime givenRepeatTime, int givenPrepTime, bool givenSegmentable, bool givenPriorty, bool givenComplete) {
	typeName = givenTypeName;
	name = givenName;
	note = givenNote;
	dueDate = givenDueDate;
	reminderTime = givenReminderTime;
	repeatTime = givenRepeatTime;
	prepTime = givenPrepTime;
	segmentable = givenSegmentable;
	priority = givenPriorty;
	complete = givenComplete;
	updateReminderDateTime();
	ID = NULL;

}

Task::Task(){}

std::string Task::getTypeName() {
	return typeName;
}

std::string Task::getName() {
	return name;
}

std::string Task::getNote() {
	return note;
}

Date Task::getDueDateTime() {
	return dueDate;
}

ReminderTime Task::getReminderTime() {
	return reminderTime;
}

RepeatTime Task::getRepeatTime() {
	return repeatTime;
}

int Task::getPrepTime() const {
	return prepTime;
}

bool Task::getSegmentable() const {
	return segmentable;
}

bool Task::getPriority() const {
	return priority;
}

bool Task::getComplete() const {
	return complete;
}

Date Task::getReminderDateTime() {
	return reminderDateTime;
}

int Task::getID() const {
	return ID;
}



//Mutators
void Task::setTypeName(const std::string& givenTypeName) {
	typeName = givenTypeName;
}
void Task::setName(const std::string& givenName) {
	name = givenName;
}
void Task::setNote(const std::string& givenNote) {
	note = givenNote;
}
void Task::setDueDateTime(const Date& givenDueDate) {
	dueDate = Date(givenDueDate.getYear(), givenDueDate.getMonth(), givenDueDate.getDay(), givenDueDate.getHour(), givenDueDate.getMinute());
	updateReminderDateTime();
}
void Task::setReminderTime(ReminderTime givenReminderTime) {
	reminderTime = givenReminderTime;
	updateReminderDateTime();
}
void Task::setRepeatTime(RepeatTime givenRepeatTime) {
	repeatTime = givenRepeatTime;
}
void Task::setPrepTime(int givenPrepTime) {
	prepTime = givenPrepTime;
}

void Task::setSegmentable(bool givenSegmentable) {
	segmentable = givenSegmentable;
}

void Task::setPriority(bool givenPriority) {
	priority = givenPriority;
}
void Task::setComplete(bool givenComplete) {
	complete = givenComplete;
	reminderTime = ReminderTime::never;
	reminderDateTime = dueDate;
}

void Task::setID(int givenID) {
	ID = givenID;
}
//
Task Task::createTaskRepeat() {
	Task repeat = *this;
	if (repeatTime != RepeatTime::never) {
		std::vector<int> toAdd = { 0, 0, 0, 0, 0 };
		
		switch (repeatTime) {
		case RepeatTime::daily:
			toAdd[3] = 1;
			break;
		case RepeatTime::weekly:
			toAdd[3] = 7;
			break;
		case RepeatTime::monthly:
			toAdd[2] = 1;
			break;
		default:
			break;
		}
		Date repeatDueDate = dueDate + toAdd;
		repeat.setDueDateTime(repeatDueDate);
	}

	return repeat;
}

void Task::operator=(const Task &rhs) {
	typeName =rhs.typeName;
	name = rhs.name;
	note = rhs.note;
	dueDate = rhs.dueDate;
	reminderTime = rhs.reminderTime;
	repeatTime = rhs.repeatTime;
	prepTime = rhs.prepTime;
	segmentable = rhs.segmentable;
	priority = rhs.priority;
	complete = rhs.complete;
	updateReminderDateTime();
	ID = rhs.ID;
}

void Task::updateReminderDateTime() {
			
	std::vector<int> toSubtract = { 0, 0, 0, 0, 0 };
	switch (reminderTime) {
	case ReminderTime::never:
		break;
	case ReminderTime::fifteenMin:
		toSubtract[4] = 15;
		break;
	case ReminderTime::thirtyMin:
		toSubtract[4] = 30;
		break;
	case ReminderTime::oneHour:
		toSubtract[3] = 1;
		break;
	case ReminderTime::oneDay:
		toSubtract[2] = 1;
		break;
	default:
		break;
	}
	reminderDateTime = dueDate - toSubtract;
}
