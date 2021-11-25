#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string newName, string newPhoneNumber, int newTotalMoney) {
	name = newName;
	phoneNumber = newPhoneNumber;
	totalDonationMoney = newTotalMoney;
}

Person::Person(const Person& p)
{
	name = p.getName();
	phoneNumber = p.getPhoneNumber();
	totalDonationMoney = p.getTotalDonationMoney();
}

Person::Person() {}

Person::~Person() {}

Person& Person::operator =(const Person& s)
{
	name = s.getName();
	phoneNumber = s.getPhoneNumber();
	totalDonationMoney = s.getTotalDonationMoney();
	return *this;
}

void Person::print()const
{
	cout << "�̸� : " << name << " ��ȭ��ȣ : " << phoneNumber << " �� ��Ź��: " << totalDonationMoney << endl;
}

string Person::toString() const 
{
	return name + " " + phoneNumber + " " + to_string(totalDonationMoney);
}

string Person::getName()const 
{
	return name;
}

string Person::getPhoneNumber()const
{
	return phoneNumber;
}

int Person::getTotalDonationMoney()const 
{
	return totalDonationMoney;
}

void Person::setName(string newName)
{
	name = newName;
}

void Person::setPhoneNumber(string newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

void Person::setTotalDonationMoney(int newTotalMoney)
{
	totalDonationMoney = newTotalMoney;
}

bool Person::operator >(const Person& person)const 
{
	if (getTotalDonationMoney() > person.getTotalDonationMoney())
		return true;
	else if (getTotalDonationMoney() < person.getTotalDonationMoney())
		return false;
	else 
	{
		if (getName() < person.getName()) 
			return true;
		else if (getName() > person.getName()) 
			return false;
		
		else
		{
			if (getPhoneNumber() < person.getPhoneNumber())
				return true;
		}
	}
	return false;
}

void Person::plusDonationMoney(int newMoney)
{
	totalDonationMoney += newMoney;
}
