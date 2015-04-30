#pragma once
#include "Task.h"
#include "TaskHandling.h"
#include "Database.h"
#include "Date.h"
#include "Panda.h"
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct sortKey {
	inline bool operator() (Task& task1, Task& task2) {
		return (task1.getDueDateTime() > task2.getDueDateTime());
	}
};

TaskHandling::TaskHandling(Database *db) : fullTaskList({}), displayList({}), deleteReminderID(0) {
	database = *db;
	petPanda = Panda::Panda();
	petPanda.setLastPointLossTime(database.getPandaDate());
	petPanda.setMood(database.getPandaMood());
	loadListsFromDatabase();
}

void TaskHandling::loadListsFromDatabase() {
	fullTaskList.clear();
	recentCompletedTasks.clear();
	displayList.clear();
	
	database.readTasks(fullTaskList);
	
	for (Task task : fullTaskList) {
		if (task.getComplete() != true) {
			displayList.push_back(task);
		}
		
	}
}

vector<Task> TaskHandling::getDisplayList() {
	return displayList;
}

int TaskHandling::getDeleteReminderID() {
	return deleteReminderID;
}

void TaskHandling::addTask(Task& newTask) {
	database.addTask(newTask);
	loadListsFromDatabase();
}

void TaskHandling::completeTask(Task& oldTask) {
	oldTask.setComplete(true);
	
	int points = 5;	//regular task
	Date now;
	if(oldTask.getDueDateTime() > now){
		points = 4;	//overdue task
	}
	petPanda.pandaAddTaskPoints(points);
	petPanda.adjustPoints();
	database.setPandaDate(petPanda.getLastPointLossTime());
	database.setPandaMood(petPanda.getMood());
	//database.setPandaName(petPanda.getName);

	database.updateTask(oldTask);
	loadListsFromDatabase();
}

void TaskHandling::deleteTask(Task& task) {
	deleteReminderID = task.getID();
	database.removeTask(task);
	loadListsFromDatabase();
}

void TaskHandling::filterDisplayList(FilterType filterType) {
	vector<Task> tempList({});
	switch (filterType) {
	case FilterType::complete:
		for (Task task : displayList) {
			if (task.getComplete() == true) {
				tempList.push_back(task);
			}
		}
		break;
	case FilterType::prepTime:
		for (Task task : displayList) {
			if (task.getPrepTime() != 0) {
				tempList.push_back(task);
			}
		}
		break;
	case FilterType::priority:
		for (Task task : displayList) {
			if (task.getPriority() == true) {
				tempList.push_back(task);
			}
		}
		break;
	case FilterType::test:
		for (Task task : displayList) {
			if (task.getTypeName() == "test") {
				tempList.push_back(task);
			}
		}
		break;
	case FilterType::assignment:
		for (Task task : displayList) {
			if (task.getTypeName() == "assignment") {
				tempList.push_back(task);
			}
		}
		break;
	case FilterType::chore:
		for (Task task : displayList) {
			if (task.getTypeName() == "chore") {
				tempList.push_back(task);
			}
		}
		break;
	case FilterType::event:
		for (Task task : displayList) {
			if (task.getTypeName() == "event") {
				tempList.push_back(task);
			}
		}
		break;
	default:
		break;
	}
	displayList.clear();
	displayList = tempList;
}

void TaskHandling::makeSmartList(SmartListType smartList) {
	vector<Task> tempList({});
	Date date = Date();

	switch (smartList) {
	case SmartListType::overdue:
		
		for (Task task : fullTaskList) {
			if (task.getDueDateTime() < date && task.getComplete() == false) {
				tempList.push_back(task);
			}
		}
		break;
	case SmartListType::hour:
		for (Task task : fullTaskList) {
			if (task.getSegmentable() == true || task.getPrepTime() <= 60) {
				tempList.push_back(task);
			}
		}
		break;
	case SmartListType::noReminder:
		for (Task task : fullTaskList) {
			if (task.getReminderTime() == ReminderTime::never) {
				tempList.push_back(task);
			}
		}
		break;
	default:
		break;
	}
	displayList.clear();
	displayList = tempList;
}

void TaskHandling::sortDisplayList(bool ascending) {
	if (ascending == true) {
		sort(displayList.begin(), displayList.end(), sortKey());
	}
	else {
		sort(displayList.begin(), displayList.end(), sortKey());
		reverse(displayList.begin(), displayList.end());
	}
}


