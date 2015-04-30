#pragma once
#include <string>
#include <vector>



class DateException {
public:
	DateException(const std::string&);
	std::string& what();

private:
	std::string message;
};

class Date {
public:
	//Constructors
	Date();														//Default constructor - Sets date/time to current local date and time
	Date(int day, int hour, int minute);						//Sets year and month to current local year/month, rest is set by params
	Date(int month, int day, int hour, int minute);				//Sets year to current local year, rest is set by params
	Date(int year, int month, int day, int hour, int minute);	//Entire date/time is given in params

	//Accessors
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;

	std::string toString() const;

private:
	//methods
	void Init(int year, int month, int day, int hour, int minute);	//Used by all constructors to initialize the values of the date.
	//Gets days in given month		
	//attributes
	int year;	//Year (eg. 2015. Cannot be negative)
	int month;	//Month (1-12)
	int day;	//Day (1-31)
	int hour;	//Hour in 24 hour clock (0-23)
	int minute; //Minute (0-59);

};

//Operator overrides for sorting and comparing dates easily
bool operator<(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
bool operator>(const Date&, const Date&);
Date operator+(const Date&, const std::vector<int>);
Date operator-(const Date&, const std::vector<int>);
std::vector<int> operator-(const Date&, const Date&);
int getMaxDays(int month, int year);
tm getCurrentDate();		//Returns a tm struct with the current date and time.