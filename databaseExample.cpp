#include <iostream>
#include <string>
#include <vector>

#include "Database.h"
#include "Task.h"
#include "Date.h"

using namespace std;

int main(){

	Date date;
	string a = "Test";
	string b = "Carl";
	string c = "Fix me";
	Task task(a, b, c, date, ReminderTime::never, RepeatTime::never, 12, true, true, false);
	vector<Task> taskArray;
	vector<Task> taskArray2;

	try {

		cout << "Initializing Database" << endl;
		Database db;

		cout << "Adding Task to Database" << endl;
		db.addTask(task);

		cout << "Getting Task from Database" << endl;
		db.readTasks(taskArray);
		cout << taskArray.size() << endl;


		cout << "Removing a task" << endl;
		db.removeTask(task);
		db.readTasks(taskArray2);
		cout << taskArray2.size() << endl;

		db.setPandaMood(15);
		db.setPandaDate(date);
		cout << db.getPandaMood() << endl;
		Date date2 = db.getPandaDate();
		cout << date2.getMinute() << ", " << date2.getHour() << ", " << date2.getDay() << endl;

		cout << "Done" << endl;
		db.close();

	}
	catch (DatabaseException& e) {
		cerr << e.what() << endl;
	}

	cin.get();
	return 0;


}