#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	Date();
	Date(int year, int month, int day, int dDay=0);

	void setDday(int newDday);
	void setDate(int newYear, int newMonth, int newDay);

	Date getDdayDate() const;

	bool isLeapYear() const;
	bool isLeapYear(int newYear) const;

	Date operator ++();
	Date operator --();

	friend ostream& operator <<(ostream& outputStream, const Date& date);

private:
	int year, month, day,dDay;
	static const int MAX_MONTH = 12;
	static const int MIN_MONTH = 1;
	static const int MAX_DAY_OF_MONTH[MAX_MONTH];

	bool isvalidDate(int newYear, int newMonth, int newDay) const;

	void modifyToCurrentDate();

	Date getPositiveDdayDate() const;
	Date getNegativeDdayDate() const;
};