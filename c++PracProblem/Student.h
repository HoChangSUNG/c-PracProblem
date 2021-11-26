#pragma once
#include "Person.h"
class Student : public Person 
{

public:
	Student(string newStudentId, string newName, string major, string newPhoneNumber, int newTotalMoney);
	Student(const Student& student);
	string getStudentId() const;
	string getMajor()const;
	void setStudentId(string newStudentId);
	void setMajor(string newMajor);

	string getKey() const;

	virtual void print() const;
	virtual string toString() const;
private:
	string studentId;
	string major;
};