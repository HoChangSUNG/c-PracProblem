#include "GeneralPerson.h"
#include <iostream>

using namespace std;
int GeneralPerson::maxIntNumber = 0;
GeneralPerson::GeneralPerson(string newName, string newPhoneNumber, int newTotalMoney) :Person(newName, newPhoneNumber, newTotalMoney)
{
	generateDonorNumber();
}

GeneralPerson::GeneralPerson(string newDonorNumber,string newName, string newPhoneNumber, int newTotalMoney) : Person(newName, newPhoneNumber, newTotalMoney), donorNumber(newDonorNumber)
{
	updateMaxIntNumber(donorNumberToInt(newDonorNumber));
	
}

string GeneralPerson::getDonorNumber()const {
	return donorNumber;
}



void GeneralPerson::print() const 
{
	cout << "[ 이름 ] " << getName() << "(기탁자코드:" << donorNumber << ") " << getPhoneNumber() << " " << getTotalDonationMoney();

}

string GeneralPerson::toString() const 
{
	return  "일반 " + donorNumber + " " + getName() + " " + getPhoneNumber() + " " + to_string(getTotalDonationMoney());

}

int GeneralPerson::getDigit(int number)const 
{
	int digit;
	for (digit = 0; number != 0; digit++)
		number /= 10;
	return digit;
}

int GeneralPerson::donorNumberToInt(string donorNumber)const 
{
	int base = 10;
	int result = 0;
	for(int i=1;i< donorNumber.length();i++)
	{
		result = base * result + (donorNumber[i] - '0');
	}

	return result;
}

void GeneralPerson::updateMaxIntNumber(int newNumber)
{
	if (maxIntNumber < newNumber)
		maxIntNumber = newNumber;
}

void GeneralPerson::generateDonorNumber()
{
	const int intDonorNumberDigit = 5;
	donorNumber = "V";
	int curIntNumber = ++maxIntNumber;

	for (int i = 0; i < intDonorNumberDigit - getDigit(curIntNumber); i++)
		donorNumber += '0';
	donorNumber += intToStr(curIntNumber);

}

string GeneralPerson::intToStr(int number)const
{
	string result = "";
	for (int i = 0; number != 0; i++) 
	{
		result =(char)((number % 10)+'0') + result;
		number=number / 10;
	}
	return result;
}
/*
bool GeneralPerson::operator >(const Person& person)const
{
	cout <<"일반인" << getTotalDonationMoney() << " " << person.getTotalDonationMoney() << endl;
	if (getTotalDonationMoney() > person.getTotalDonationMoney())
		return true;
	else if (getTotalDonationMoney() < person.getTotalDonationMoney())
		return false;
	else {
		if (getName() < person.getName())
			return true;
		else if (getName() > person.getName())
			return false;
		else {
			if (getPhoneNumber() < person.getPhoneNumber())
				return true;
		}
	}
	return false;
}*/
