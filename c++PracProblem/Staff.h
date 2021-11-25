#pragma once
#include "Person.h"
class Staff : public Person 
{

public:
	Staff(string newEmployeeId, string newName, string newDepartment, string newPhoneNumber,string newExtensionNumber, int newTotalMoney);
	Staff(const Staff& staff);

	string getEmployeeId() const;
	string getDepartment()const;
	string getExtensionNumber()const;

	void setEmployeeId(string newEmployeeId);
	void setDepartment(string newDepartment);
	void setExtensionNumber(string newExtensionNumber);


	string getKey() const;

	virtual void print() const;
	virtual string toString() const;
private:
	string employeeId;
	string department;
	string extensionNumber;
};