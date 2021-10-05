#include <iostream>
#include "Date.h"
#include <cctype>
#include <string>
using namespace std;
bool isRightInputDday(string dDay);
bool isRightInputDate(string date);
int getYear(int date);
int getMonth(int date);
int getDay(int date);

int main()
{
	Date date;
	string input;
	cout << date;

	while (1)
	{

		cout << "날짜 이동은 년월일 또는 +(다음날)또는 -(전날),D-day 계산은 +/-날짜. 종료는 Q : ";
		getline(cin, input);

		if (input[0] =='Q')
			break;
		else if (input[0] == '+' && input.size()==1)
			++date;
		else if (input[0] == '-' && input.size() == 1)
			--date;
		else if (isRightInputDday(input)) 
			date.setDday(stoi(input));
		else if (isRightInputDate(input))
		{
			int curDate = stoi(input);
			date.setDate(getYear(curDate),getMonth(curDate),getDay(curDate));
		}
		else 
			cout<<"지정된 입력 형태를 확인해 주세요"<<endl;
		cout << date;

	}

	return 0;
}

bool isRightInputDday(string dDay)
{
	if (dDay[0] == '+' || dDay[0] == '-')
	{
		for (int i = 1; i < dDay.size(); i++) 
		{
			if (!isdigit(dDay[i])) 
				return false;
		}
		return true;
	}
	return false;
}

bool isRightInputDate(string date) 
{
	for (int i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]))
			return false;
	}

	if (date.size() != 8)
		return false;

	return true;
}

int getYear(int date)
{
	return date / 10000;
}

int getMonth(int date)
{
	return date % 10000 / 100;
}

int getDay(int date)
{
	return date % 100;
}