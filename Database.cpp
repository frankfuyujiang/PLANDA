#pragma once
#include "Database.h"
#include "Date.h"

//compile with: /link sqlite3.lib

using namespace std;

const string DBDIR = "PlandaDatabase.db";

DatabaseException::DatabaseException(const string& m) : message(m) {}
string& DatabaseException::what() { return message; }

Database::Database(){	//initializes database
	char *errorMsg = 0;
	int errorCode = 0;
	string sql;

	errorCode = sqlite3_open_v2(DBDIR.c_str(), &DBase, SQLITE_OPEN_READWRITE, NULL);	//Opens Database to specified pointer

	if (errorCode == SQLITE_CANTOPEN) {														//If no database file exists
		//No Database. Creating for first time use.

		errorCode = sqlite3_open_v2(DBDIR.c_str(), &DBase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);	//creates the file
		if (errorCode){ throw DatabaseException("Can't create Database."); }

		//sql for creating the table
		sql = "CREATE TABLE TASKS( \
			TASKID	INTEGER	PRIMARY KEY	,\
			TYPENAME			TEXT	NOT NULL, \
			NAME				TEXT	NOT NULL, \
			NOTE	            TEXT	NOT NULL, \
			DUEMIN				INT		NOT NULL, \
			DUEHOUR				INT		NOT NULL, \
			DUEDAY				INT		NOT NULL, \
			DUEMONTH			INT		NOT NULL, \
			DUEYEAR				INT		NOT	NULL, \
			REMINDTIME			INT		NOT NULL, \
			REPEATTIME			INT		NOT NULL, \
			PREPTIME			INT		NOT NULL, \
			SEGMENT				INT		NOT NULL, \
			PRIORITY			INT		NOT NULL, \
			COMPLETE			INT		NOT NULL);";

		errorCode = sqlite3_exec(DBase, sql.c_str(), NULL, 0, &errorMsg);				//Adds the task table

		if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

		sql = "CREATE TABLE PANDA( \
				FIND				INT DEFAULT 1, \
				MOOD				INT , \
				MIN					INT	, \
				HOUR				INT	, \
				DAY					INT	, \
				MONTH				INT	, \
				YEAR				INT , \
				NAME				TEXT DEFAULT 'Your Pet Panda');";

		errorCode = sqlite3_exec(DBase, sql.c_str(), NULL, 0, &errorMsg);				//Adds the panda mood table

		if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

		sql = "INSERT INTO PANDA (MOOD, MIN,HOUR,DAY,MONTH,YEAR)	VALUES(80,0,24,1,1,2015);";

		errorCode = sqlite3_exec(DBase, sql.c_str(), NULL, 0, &errorMsg);

		if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }
	}
}



void Database::addTask(Task &task) const{  //Adds task to the database
	char *errorMsg = 0;
	int errorCode = 0;
	bool setTaskID = false;
	string sql;
	stringstream ss;

	if (task.getID() == NULL) {
		setTaskID = true;
		ss << "INSERT INTO TASKS (TYPENAME, NAME, NOTE, DUEMIN, DUEHOUR, DUEDAY, DUEMONTH, DUEYEAR, REMINDTIME, REPEATTIME, PREPTIME, SEGMENT, PRIORITY, COMPLETE)	VALUES(";
	}
	else{
		ss << "INSERT INTO TASKS	VALUES(";
		ss << task.getID() << ", ";
	}

	ss << "'" << task.getTypeName() << "'";
	ss << ",'" << task.getName() << "'";
	ss << ",'" << task.getNote() << "'";
	ss << "," << task.getDueDateTime().getMinute();
	ss << "," << task.getDueDateTime().getHour();
	ss << "," << task.getDueDateTime().getDay();
	ss << "," << task.getDueDateTime().getMonth();
	ss << "," << task.getDueDateTime().getYear();
	ss << "," << static_cast<int>(task.getReminderTime());
	ss << "," << static_cast<int>(task.getRepeatTime());
	ss << "," << task.getPrepTime();
	ss << "," << task.getSegmentable();
	ss << "," << task.getPriority();
	ss << "," << task.getComplete() << ");";

	sql = ss.str();

	errorCode = sqlite3_exec(DBase, sql.c_str(), NULL, 0, &errorMsg);
	
	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

	if (setTaskID) { task.setID(sqlite3_last_insert_rowid(DBase)); }

}

void Database::readTasks(vector<Task>& taskArray) const{
	char *errorMsg = 0;
	int errorCode = 0;

	string sql = "SELECT * FROM TASKS;";

	errorCode = sqlite3_exec(DBase, sql.c_str(), getCallback, static_cast<void*>(&taskArray), &errorMsg);

	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }
}

void Database::updateTask(Task& task) const{
	removeTask(task);
	addTask(task);
}

void Database::removeTask(const Task& task) const{
	char *errorMsg = 0;
	int errorCode = 0;
	stringstream ss;

	ss << "DELETE FROM TASKS WHERE TASKID = " << task.getID() << ";";

	string sql = ss.str();

	errorCode = sqlite3_exec(DBase, sql.c_str(), NULL, 0, &errorMsg);

	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }


}

int Database::getPandaMood() const{
	vector<int> pandaArray;
	char *errorMsg = 0;
	int errorCode = 0;

	string sql = "SELECT * FROM PANDA;";

	errorCode = sqlite3_exec(DBase, sql.c_str(), getCallbackPanda, static_cast<void*>(&pandaArray), &errorMsg);

	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

	return pandaArray[0];
}
/*
string Database::getPandaName() const{
	vector<string> pandaArray;
	char *errorMsg = 0;
	int errorCode = 0;

	string sql = "SELECT * FROM PANDA;";

	errorCode = sqlite3_exec(DBase, sql.c_str(), getCallbackPanda, static_cast<void*>(&pandaArray), &errorMsg);

	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

	return pandaArray[6];
}*/

Date Database::getPandaDate() const{
	vector<int> pandaArray;
	char *errorMsg = 0;
	int errorCode = 0;

	string sql = "SELECT * FROM PANDA;";

	errorCode = sqlite3_exec(DBase, sql.c_str(), getCallbackPanda, static_cast<void*>(&pandaArray), &errorMsg);

	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

	Date pandaTime(pandaArray[5], pandaArray[4], pandaArray[3], pandaArray[2], pandaArray[1]);

	return pandaTime;
}

void Database::setPandaMood(int mood) const{  //Updates Panda Mood
	char *errorMsg = 0;
	int errorCode = 0;

	string sql;
	stringstream ss;

	ss << "UPDATE PANDA ";
	ss << "SET MOOD = ";
	ss << mood;
	ss << " WHERE FIND = 1";

	sql = ss.str();

	errorCode = sqlite3_exec(DBase, sql.c_str(), NULL, 0, &errorMsg);

	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

}

void Database::setPandaDate(Date& date) const{  //Updates Panda Date
	char *errorMsg = 0;
	int errorCode = 0;

	string sql;
	stringstream ss;

	ss << "UPDATE PANDA ";
	ss << "SET MIN = ";
	ss << date.getMinute();
	ss << ",HOUR = ";
	ss << date.getHour();
	ss << ",DAY = ";
	ss << date.getDay();
	ss << ",MONTH = ";
	ss << date.getMonth();
	ss << ",YEAR = ";
	ss << date.getYear();
	ss << " WHERE FIND = 1";

	sql = ss.str();

	errorCode = sqlite3_exec(DBase, sql.c_str(), NULL, 0, &errorMsg);

	if (errorCode != SQLITE_OK){ throw DatabaseException(errorMsg); }

}

int Database::close(){
	sqlite3_close(DBase);
	return 0;
}


int getCallback(void *arrayPtr, int numCols, char **dataArray, char **colNames){

	vector<Task>* taskArray = static_cast<vector<Task>*>(arrayPtr);		//Convert the void pointer back to a vector pointer

	//Creates a datatime object for the task.
	Date Date(atoi(dataArray[8]), atoi(dataArray[7]), atoi(dataArray[6]), atoi(dataArray[5]), atoi(dataArray[4]));

	//Creates the task
	Task task(	dataArray[1], 
				dataArray[2], 
				dataArray[3], 
				Date, //check this
				static_cast<ReminderTime>(atoi(dataArray[9])), 
				static_cast<RepeatTime>(atoi(dataArray[10])), 
				atoi(dataArray[11]), 
				atoi(dataArray[12]), 
				atoi(dataArray[13]), 
				atoi(dataArray[14]));

	task.setID(atoi(dataArray[0]));

	taskArray->push_back(task);		//Adds the task to the vector

	return 0;
}

int getCallbackPanda(void *arrayPtr, int numCols, char **dataArray, char **colNames){

	vector<int>* pandaArray = static_cast<vector<int>*>(arrayPtr);		//Convert the void pointer back to a vector pointer

	pandaArray->push_back(atoi(dataArray[1])); //Mood
	pandaArray->push_back(atoi(dataArray[2])); //Minute
	pandaArray->push_back(atoi(dataArray[3])); //Hour
	pandaArray->push_back(atoi(dataArray[4])); //Day
	pandaArray->push_back(atoi(dataArray[5])); //Month
	pandaArray->push_back(atoi(dataArray[6])); //Year

	return 0;
}

