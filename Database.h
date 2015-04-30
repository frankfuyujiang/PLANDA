#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


#include "sqlite3.h"
#include "Task.h"
#include "Date.h"


//Check databaseExample.cpp to get an idea of how to use.
using namespace std;

class DatabaseException {				//Exception handler for database class
public:
	DatabaseException(const string&);
	string& what();
private:
	string message;
};


class Database{

public:
	Database();							//Initializes the database pointer as well as creates a database file if none exists.
	void addTask(Task&) const;			//Adds a task to the database. If ID does not exist it assigns one.
	void updateTask(Task&) const;		//Removes and reads a tasks. Essentially updates it.
	void removeTask(const Task&) const;		//Removes a task from the database.
	void readTasks(vector<Task>&) const;	//Reads all the tasks in the database and adds them to the supplied vector
	int getPandaMood() const;
	//string getPandaName() const;
	Date getPandaDate() const;
	void setPandaMood(int) const;
	//void setPandaName(string) const;
	void setPandaDate(Date&) const;
	int close();						//Closes the database connection. Should be done before the program terminates.
			
private:

	sqlite3	*DBase;						//Stores the sqlite database pointer

};
int getCallback(void *arrayPtr, int numCols, char **dataArray, char **colNames);	//Callback function used by readTasks.
																					//Creates tasks and adds them tothe vector.

int getCallbackPanda(void *arrayPtr, int numCols, char **dataArray, char **colNames);