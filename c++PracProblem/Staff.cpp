#include "Staff.h"
#include <iostream>

using namespace std;

Staff::Staff(string newEmployeeId, string newName, string newDepartment, string newExtensionNumber, string newPhoneNumber, int newTotalMoney) :Person(newName, newPhoneNumber, newTotalMoney)
{
	employeeId= newEmployeeId;
	department = newDepartment;
	extensionNumber = newExtensionNumber;
}

Staff::Staff(const Staff& staff) :Person(staff)
{
	employeeId = staff.employeeId;
	department = staff.department;
	extensionNumber = staff.extensionNumber;
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
	cout <<"[교직원] " << getName() << "(사번:" << employeeId << ", 부서:" << department << "(x" << extensionNumber << ")) " << getPhoneNumber() << " " << getTotalDonationMoney() << endl;

}

string Staff::toString() const
{
	return "교직원 " + employeeId+" " + getName()  + " " + department + " " + " "+extensionNumber + " " + getPhoneNumber() + " " + to_string(getTotalDonationMoney());
}

string Staff::getKey() const
{
	return employeeId;
}
