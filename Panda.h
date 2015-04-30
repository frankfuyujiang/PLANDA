#pragma once
#include "Date.h"
#include <string>

using namespace std;

class Panda {
private:
	int mood;
	string name;
	Date lastPointLossTime;


public:
	Panda();
	~Panda();

	void resetPandaMood();

	int getMood();	/* returns the mood of the panda as an int from 0 to 100 */
	string getName();  /* returns name of panda as string*/
	Date getLastPointLossTime();

	void setName(string newname);	// talk to Frank about implementing this in Settings
	void setMood(int newmood);
	void setLastPointLossTime(Date newtime);

	// lose 2 points for every 3 hours (called in complete task)
	void adjustPoints();
	void pandaAddTaskPoints(int points); // 3 points for a task done, 2 if it was overdue, negative too
};

