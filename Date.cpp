#pragma once
//#include <string>
#include <ctime>
//#include "stdafx.h"
#include "Date.h"

DateException::DateException(const std::string& msg) {
	message = msg;
}
std::string& DateException::what() {
	return message;
}

Date::Date() {
	tm currentDate = getCurrentDate();
	try {
		Init(currentDate.tm_year + 1900, currentDate.tm_mon + 1, currentDate.tm_mday, currentDate.tm_hour, currentDate.tm_min);
	}
	catch (DateException &e) {
		//Should never get here, unless the current date breaks the rules of time and space
		throw e;
	}
}
Date::Date(const int givenDay, const int givenHour, const int givenMinute) {
	tm currentDate = getCurrentDate();
	try {
		Init(currentDate.tm_year + 1900, currentDate.tm_mon + 1, givenDay, givenHour, givenMinute);
	}
	catch (DateException &e) {
		throw e;
	}
}
Date::Date(const int givenMonth, const int givenDay, const int givenHour, const int givenMinute) {
	tm currentDate = getCurrentDate();
	try {
		Init(currentDate.tm_year + 1900, givenMonth, givenDay, givenHour, givenMinute);
	}
	catch (DateException &e) {
		throw e;
	}
}
Date::Date(const int givenYear, const int givenMonth, const int givenDay, const int givenHour, const int givenMinute) {
	try {
		Init(givenYear, givenMonth, givenDay, givenHour, givenMinute);
	}
	catch (DateException &e) {
		throw e;
	}
}

void Date::Init(int givenYear, int givenMonth, int givenDay, int givenHour, int givenMinute) {
	if (givenYear < 0) {
		givenYear = 0;
		//throw DateException("Given year value is invalid");
	}
	if (givenMonth < 1 || givenMonth > 12) {
		throw DateException("Given month value is invalid");
	}
	if (givenDay < 1 || givenDay > getMaxDays(givenMonth, givenYear)) {
		throw DateException("Given day number is invalid for given month");
	}
	if (givenHour < 0 || givenHour > 24) {
		throw DateException("Given hour is not valid");
	}
	if (givenMinute < 0 || givenMinute > 59) {
		throw DateException("Given minute is not valid");
	}
	year = givenYear;
	month = givenMonth;
	day = givenDay;
	hour = givenHour;
	minute = givenMinute;
}

int Date::getYear() const {
	return year;
}
int Date::getMonth() const {
	return month;
}
int Date::getDay() const {
	return day;
}
int Date::getHour() const {
	return hour;
}
int Date::getMinute() const {
	return minute;
}

std::string Date::toString() const {
	std::string stringMonth, stringDay, stringHour, stringMinute;
	if (month < 10)
		stringMonth = "0" + std::to_string(month);
	else
		stringMonth = std::to_string(month);


	if (day < 10)
		stringDay = "0" + std::to_string(day);
	else
		stringDay = std::to_string(day);

	if (hour < 10)
		stringHour = "0" + std::to_string(hour);
	else
		stringHour = std::to_string(hour);

	if (minute < 10)
		stringMinute = "0" + std::to_string(minute);
	else
		stringMinute = std::to_string(minute);


	return stringMonth + "/" + stringDay + " " + stringHour + ":" + stringMinute;
	
}

int getMaxDays(int givenMonth, int givenYear) {
	if (givenMonth == 2) {
		bool leapYear;
		if (givenYear % 4 != 0)
			leapYear = false;
		else if (givenYear % 100 != 0)
			leapYear = true;
		else if (givenYear % 400 != 0)
			leapYear = false;
		else
			leapYear = true;
		return 28 + leapYear; //leapYear == 1 if true, so year has 28 + 1 days. Else 28 + 0
	}
	else {
		int dayArray[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Days in each month
		return dayArray[givenMonth - 1];
	}
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.getYear() < rhs.getYear()) {
		return true;
	}
	else if (lhs.getYear() > rhs.getYear()) {
		return false;
	}

	if (lhs.getMonth() < rhs.getMonth()) {
		return true;
	}
	else if (lhs.getMonth() > rhs.getMonth()) {
		return false;
	}

	if (lhs.getDay() < rhs.getDay()) {
		return true;
	}
	else if (lhs.getDay() > rhs.getDay()) {
		return false;
	}

	if (lhs.getHour() < rhs.getHour()) {
		return true;
	}
	else if (lhs.getHour() > rhs.getHour()) {
		return false;
	}

	if (lhs.getMinute() < rhs.getMinute()) {
		return true;
	}

	return false;
}
bool operator<=(const Date& lhs, const Date& rhs) {
	return !(lhs > rhs);
}
bool operator==(const Date& lhs, const Date& rhs) {
	return (lhs.getYear() == rhs.getYear() && lhs.getMonth() == rhs.getMonth() && lhs.getDay() == rhs.getDay() && lhs.getHour() == rhs.getHour() && lhs.getMinute() == rhs.getMinute());
}
bool operator!=(const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
}
bool operator>=(const Date& lhs, const Date& rhs) {
	return !(lhs < rhs);
}
bool operator>(const Date& lhs, const Date& rhs) {
	if (lhs.getYear() > rhs.getYear()) {
		return true;
	}
	else if (lhs.getYear() < rhs.getYear()) {
		return false;
	}

	if (lhs.getMonth() > rhs.getMonth()) {
		return true;
	}
	else if (lhs.getMonth() < rhs.getMonth()) {
		return false;
	}

	if (lhs.getDay() > rhs.getDay()) {
		return true;
	}
	else if (lhs.getDay() < rhs.getDay()) {
		return false;
	}

	if (lhs.getHour() > rhs.getHour()) {
		return true;
	}
	else if (lhs.getHour() < rhs.getHour()) {
		return false;
	}

	if (lhs.getMinute() > rhs.getMinute()) {
		return true;
	}

	return false;
}

Date operator+(const Date& lhs, const std::vector<int> rhs) {
	int carry = 0;
	int year, month, day, hour, minute, maxDays;
	minute = lhs.getMinute() + rhs[4];
	hour = lhs.getHour() + rhs[3];
	day = lhs.getDay() + rhs[2];
	month = lhs.getMonth() + rhs[1];
	year = lhs.getYear() + rhs[0];
	if (minute >= 60) {
		hour++;
		minute -= 60;
	}
	if (hour > 24) {
		day++;
		hour -= 24;
	}
	if (month > 12) {
		year++;
		month -= 12;
	}
	maxDays = getMaxDays(month, year);
	while (day > maxDays) {
		month++;
		day -= maxDays;
		if (month > 12) {
			year++;
			month -= 12;
		}
		maxDays = getMaxDays(month, year);
	}
	Date solution = Date(year, month, day, hour, minute);
	return solution;
	
}

Date operator-(const Date& lhs, const std::vector<int> rhs) {
	int carry = 0;
	int year, month, day, hour, minute, maxDays;
	minute = lhs.getMinute() - rhs[4];
	hour = lhs.getHour() - rhs[3];
	day = lhs.getDay() - rhs[2];
	month = lhs.getMonth() - rhs[1];
	year = lhs.getYear() - rhs[0];
	if (minute < 0) {
		hour--;
		minute += 60;
	}
	if (hour < 0) {
		day--;
		hour += 24;
	}
	if (month < 1) {
		year--;
		month += 12;
	}
	while (day < 0) {
		month--;
		if (month < 1) {
			year--;
			month += 12;
		}
		maxDays = getMaxDays(month, year);
		day += maxDays;
	}
	Date solution = Date(year, month, day, hour, minute);
	return solution;
}

// overloaded minus so subtract Dates from Dates - untested
std::vector<int> operator-(const Date& lhs, const Date& rhs) {
	int carry = 0;
	int year, month, day, hour, minute, maxDays;
	minute = lhs.getMinute() - rhs.getMinute();
	hour = lhs.getHour() - rhs.getHour();
	day = lhs.getDay() - rhs.getDay();
	month = lhs.getMonth() - rhs.getMonth();
	year = lhs.getYear() - rhs.getYear();
	if (minute < 0) {
		hour--;
		minute += 60;
	}
	if (hour < 0) {
		day--;
		hour += 24;
	}
	if (month < 0) {
		year--;
		month += 12;
	}
	while (day < 0) {
		month--;
		if (month < 1) {
			year--;
			month += 12;
		}
		maxDays = getMaxDays(month, year);
		day += maxDays;
	}
	std::vector<int> solution = { year, month, day, hour, minute };
	return solution;
}



tm getCurrentDate() {
	time_t rawtime;
	time(&rawtime);
	struct tm timeInfo;
	localtime_s(&timeInfo, &rawtime);
	return timeInfo;
}