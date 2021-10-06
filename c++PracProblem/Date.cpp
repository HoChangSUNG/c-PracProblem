#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
#include <time.h>
using namespace std;

const int Date::MAX_DAY_OF_MONTH[MAX_MONTH] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date() 
{
	modifyToCurrentDate();
}

Date::Date(int newYear, int newMonth, int newDay, int newDday)
{
	if (isvalidDate(newYear, newMonth, newDay))
	{
		year = newYear;
		month = newMonth;
		day = newDay;
		dDay = newDday;
	}
	else 
	{
		cout << "불가능한 날짜입니다";
		modifyToCurrentDate();
	}
}

void Date::modifyToCurrentDate()
{
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	year = t->tm_year + 1900;
	month = t->tm_mon + 1;
	day = t->tm_mday;
	dDay = 0;
}

bool Date::isLeapYear(int newYear) const
{
	return (newYear%4==0&&newYear%100!=0||newYear%400==0);
}

bool Date::isLeapYear() const
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

bool Date::isvalidDate(int newYear, int newMonth, int newDay) const
{
	if (newYear > 0 && 0 < newMonth && newMonth < 13 && newDay>0)
	{
		if (MAX_DAY_OF_MONTH[newMonth - 1] >= newDay)
		{
			return true;
		}
		else
		{
			if (newMonth == 2 && isLeapYear(newYear) && newDay == 29)
				return true;
		}
	}
	return false;
}

Date Date::operator ++() 
{
	if ((++day) > MAX_DAY_OF_MONTH[month - 1])
	{
		if (!(month == 2 && isLeapYear() && day == 29))
		{
			day = 1;
			month++;
		}
	}
	if (month > MAX_MONTH) 
	{
		year++;
		month = MIN_MONTH;
	}
	return Date(year,month,day,dDay);
}

Date Date::operator --()
{
	if (--day < 1)
	{
		month--;
		if (month == 2 && isLeapYear()) 
		{
			day = 29;
		}
		else 
		{
			if (month>0)
				day = MAX_DAY_OF_MONTH[month - 1];
		}
	}

	if (month < 1)
	{
		year--;
		month = MAX_MONTH;
		day = MAX_DAY_OF_MONTH[month - 1];
	}

	return Date(year, month, day, dDay);
}

void Date::setDate(int newYear, int newMonth,int newDay)
{
	if (isvalidDate(newYear, newMonth, newDay))
	{
		year = newYear;
		month = newMonth;
		day = newDay;
	}
	else
		cout << "불가능한 날짜입니다" << endl;
}

ostream& operator <<(ostream& outputStream, const Date& date)
{
	outputStream << "[현재날짜] " << date.year << "년 " << date.month << "월 " << date.day << "일 ";
	if (date.dDay == 0)
		outputStream << "[D-day 없음]" << endl;
	
	else{
		
		if (date.dDay > 0)
			outputStream << "[D+"<<date.dDay << "] ";
		else
			outputStream << "[D"<< date.dDay << "] ";

		Date dDayDate = date.getDdayDate();

		if (date.dDay < 0 && date.year == dDayDate.year && date.month == dDayDate.month && date.day == dDayDate.day)
			cout << "기원전은 계산이 불가능합니다."<<endl;
		else
			cout<<" "<< dDayDate.year << "년 " << dDayDate.month << "월 " << dDayDate.day << "일 " << endl;
	}

	return outputStream;
}

void Date::setDday(int newDday) 
{
	dDay = newDday;
}

Date Date::getDdayDate() const 
{
	if (dDay > 0)
		return getPositiveDdayDate();
	else
		return getNegativeDdayDate();
}

Date Date::getPositiveDdayDate() const
{
	int newYear = year, newMonth = month, newDay = day + dDay - 1;
	while (newDay > MAX_DAY_OF_MONTH[newMonth - 1])
	{
		if (isLeapYear(newYear) && newMonth == 2)
		{
			if (newDay > 29)
				newDay -= 29;
			else
				break;
		}
		else
		{
			newDay -= MAX_DAY_OF_MONTH[newMonth - 1];
		}

		newMonth++;
		if (newMonth > MAX_MONTH)
		{
			newMonth = MIN_MONTH;
			newYear++;
		 }
	}
	return Date(newYear, newMonth, newDay);
}


Date Date::getNegativeDdayDate() const
{
	int newYear = year, newMonth = month, newDay = day + dDay ;
	while (newDay < 1) 
	{
		newMonth--;
		if (newMonth < 1) 
		{
			newYear--;
			newMonth = MAX_MONTH;
		}

		if (!(isLeapYear(newYear) && newMonth == 2))
			newDay = MAX_DAY_OF_MONTH[newMonth - 1] + newDay;
		else
			newDay = 29 + newDay;
	}

	if (!isvalidDate(newYear, newMonth, newDay)) //D-DAY가 기원전일 경우
	{
		newYear = year;
		newMonth = month;
		newDay = day;
	}
		
	return Date(newYear, newMonth, newDay);
}