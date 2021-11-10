#include "Staff.h"
#include <iostream>

using namespace std;

Staff::Staff(string newEmployeeId, string newName, string newDepartment, string newPhoneNumber, string newExtensionNumber, int newTotalMoney) :Person(newName, newPhoneNumber, newTotalMoney)
{
	employeeId= newEmployeeId;
	department = newDepartment;
	extensionNumber = newExtensionNumber;
}

string Staff::getEmployeeId() const { 
	return employeeId; 
}

string Staff::getDepartment()const
{
	return department; 
}

string Staff::getExtensionNumber()const
{ 
	return extensionNumber;
}

void Staff::setEmployeeId(string newEmployeeId) 
{
	employeeId = newEmployeeId;
}

void Staff::setDepartment(string newDepartment)
{ 
	department = newDepartment;
}

void Staff::setExtensionNumber(string newExtensionNumber) 
{
	extensionNumber = newExtensionNumber;
}

void Staff::print() const
{
	cout <<"[교직원] " << getName() << "(사번:" << employeeId << ", 부서:" << department << "(x" << extensionNumber << ")) " << getPhoneNumber() << " " << getTotalDonationMoney();

}

string Staff::toString() const
{
	return "교직원 " + employeeId+" " + getName()  + " " + department + " " + getPhoneNumber() +" "+ extensionNumber + " " + to_string(getTotalDonationMoney());
}
/*
bool Staff::operator >(const Person& person)const 
{
	cout << "교직원" << getTotalDonationMoney() << " " << person.getTotalDonationMoney() << endl;
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

}
*/