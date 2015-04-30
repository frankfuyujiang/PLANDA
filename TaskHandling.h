#pragma once

#include "Task.h"
#include "Database.h"
#include "Date.h"
#include "Panda.h"
#include <vector>
#include <string>

using namespace std;

/*
* FilterType is a generated class that serves as an identifier for each
* of the possible options for filtering the displayed list.
*/
enum class FilterType { test, assignment, chore, event, prepTime, priority, complete };

/*
* SmartListType is a generated class that serves as an identifier for
* each of the possible options for creating a smart list.
*/
enum class SmartListType { overdue, hour, noReminder };

class TaskHandling {
public:
	/* 
	 * Constructor for TaskHandling. Initializes all vector lists to empty
	 * and calls loadListsFromDatabase to load tasks into each list.
	 */

	TaskHandling(Database *db);

	/*
	* Accessors for important class attributes.
	*
	* getDisplayList() returns the displayList attribute in the class.
	*
	* getReminderID() returns the value of the deleteReminderID attribute
	* in the class.
	*/
	vector<Task> getDisplayList();
	int getDeleteReminderID();

	/*
	* Methods:
	* loadListsFromDatabase() calls readTasks() from the Database class
	* which is loaded into the fullTaskList vector. From there, the
	* fullTaskList vector puts all completed tasks into the
	* recentCompletedTasks vector, and all other tasks (current tasks)
	* into the displayList to be shown in the GUI.
	*
	* addTask is responsible for sending a new task object to the database
	* class, to which it will be added. Once the task has been added,
	* loadListsFromDatabase is called to re-initialize the task lists
	* updated to the added task entry in the database.
	*
	* completeTask is responsible for setting a tasks's complete attribute
	* to true. Once the task has been marked as complete, the task is
	* passed to the Database class to update the task entry in the database.
	* Following the update, loadListsFromDatabase will be called to update
	* the task lists.
	*
	* deleteTask is responsible for passing a deleted task to the Database
	* class to remove the entry of that task from the database. Before the
	* task has been removed from the database, deleteTaskReminder will be
	* set to the ID number of the task to be deleted. Once the task has
	* been deleted from the database, loadListsFromDatabase will be called
	* to update all task lists for what is currently in the database.
	*
	* filterDisplayList is responsible for searching through displayList
	* to find tasks that meet the criteria of the input FilterType. Each
	* possible FilterType is has it's own case, and each case loops through
	* displayList, checks if the current task meets the FilterType criteria,
	* and if it does the task will be added to displayList.
	*
	* makeSmartList is responsible for creating a smart list based on
	* the input SmartListType. The possible smart list types are overdue
	* tasks (a task that is not completed and has a due date that is past
	* the current date), tasks that can be completed or worked on within
	* 60 minutes, and tasks that do not have reminders set for them. Each
	* possibility has it's own case, and each case loops through fullTaskList
	* and checks each task criteria matching the SmartListType given. If
	* the task matches the criteria, it will be added to displayList.
	*
	* sortDisplaylist sorts the displayList based on the value of the ascending
	* variable given to the function. If ascending is true, it will sort
	* displayList based on increasing due date. If displayList is false
	* it will sort displayList based on decreasing due date.
	*/
	void loadListsFromDatabase();
	void addTask(Task& newTask);
	void completeTask(Task& oldTask);
	void deleteTask(Task& task);
	void filterDisplayList(FilterType filterType);
	void makeSmartList(SmartListType smartList);
	void sortDisplayList(bool ascending);
	Panda petPanda = Panda();
private:
	//placeholder, take out once database has been implemented in main
	Database database;
	/*
	* Class attributes:
	* fullTaskList holds all tasks stored in the database. Once a task has been manipulated
	* (addTask, deleteTask, completeTask), this will be updated from what the database holds and
	* the other task vectors will be sorted from there.
	*
	* recentCompletedTasks holds all tasks in fullTaskList where the completed status for each
	* task is set to true.
	*
	* displayList holds all tasks that are currently being displayed (or are about to be displayed)
	* in the GUI.
	*
	* deleteReminderID holds a 0 value, except for when a task is being deleted. When a task
	* is deleted, the value is changed to that of the taskID for the deleted task. By changing
	* this value, the reminder class will delete the reminder for the task with the matching
	* taskID as the deleted task.
	*
	*/
	vector<Task> fullTaskList;
	vector<Task> recentCompletedTasks;
	vector<Task> displayList;
	int deleteReminderID;
	
};