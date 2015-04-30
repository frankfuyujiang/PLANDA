#include "Panda.h"
#include "Date.h"


Panda::Panda()
{
	name = "Your Pet Panda";
	mood = 80;
	Date lastPointLossTime();
}

Panda::~Panda()
{
}

void Panda::adjustPoints(){
	Date now = Date();
	vector<int> timeSince = now - lastPointLossTime;

	int  days, hours, minutes;
	minutes = timeSince[4];
	hours = timeSince[3];
	days = timeSince[2];

	//short circuit when we know the panda will have sunk to 0
	if (timeSince[0] > 0 || timeSince[1] > 0 || days > 6 ) {
		mood = 0;
		lastPointLossTime = Date();
	}
	else {
		hours += days * 24;
		int num3hours = hours / 3;
		int remHrs = hours % 3;
		pandaAddTaskPoints(num3hours * (-2));

		vector<int> remainder = {0, 0, 0, remHrs, minutes};
		lastPointLossTime = now - remainder;
	}
	
}

void Panda::pandaAddTaskPoints(int points){
	int newmood = getMood();
	newmood += points;
	setMood(newmood);
}

void Panda::resetPandaMood(){
	setMood(80);
}

void Panda::setName(string newname){
	name = newname;
}

void Panda::setMood(int newmood){
	if (newmood < 0)
		mood = 0;
	else if (newmood > 100)
		mood = 100;
	else
		mood = newmood;
}

void Panda::setLastPointLossTime(Date newtime){
	lastPointLossTime = newtime;
}

Date Panda::getLastPointLossTime(){
	return lastPointLossTime;
}

int Panda::getMood(){
	return mood;
}

string Panda::getName(){
	return name;
}