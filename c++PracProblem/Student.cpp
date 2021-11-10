#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string newStudentId,  string newName,string newMajor, string newPhoneNumber, int newTotalMoney):Person(newName, newPhoneNumber, newTotalMoney)
{
	studentId = newStudentId;
	major = newMajor;
}

string Student::getStudentId() const
{
	return studentId;
}

string Student::getMajor()const 
{
	return major;
}

void Student::setStudentId(string newStudentId) 
{
	studentId = newStudentId;
}

void Student::setMajor(string newMajor) 
{
	major = newMajor;
}

void Student::print() const
{
	cout << "[ �л� ] " << getName() << "(�й�:" << studentId << ", �а�:" << major << ") " << getPhoneNumber() << " " << getTotalDonationMoney();
}

string Student::toString() const
{
	return "�л� "  + studentId+" " + getName() + " " + major + " " + getPhoneNumber() + " " + to_string(getTotalDonationMoney());
}
/*
bool Student::operator >(const Person& person)const
{
	cout << "�л�" << getTotalDonationMoney() << " " << person.getTotalDonationMoney() << endl;
	if (getTotalDonationMoney() > person.getTotalDonationMoney())
		return true;
	else if (getTotalDonationMoney() < person.getTotalDonationMoney())
		return false;
	else {
		if (getName() < person.getName())
			return true;
		else if (getName() > person.getName())
			return false;
		else{
			if (getPhoneNumber() < person.getPhoneNumber())
				return true;
		}
	}
	
	return false;
	
	
	
}
*/