#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string newStudentId,  string newName,string newMajor, string newPhoneNumber, int newTotalMoney)
	:Person(newName, newPhoneNumber, newTotalMoney)
{
	studentId = newStudentId;
	major = newMajor;
}

Student::Student(const Student& student):Person(student)
{
	studentId = student.studentId;
	major = student.major;
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
	cout << "[ 학생 ] " << getName() << "(학번:" << studentId << ", 학과:" << major << ") " 
		<< getPhoneNumber() << " " << getTotalDonationMoney() << endl;
}

string Student::toString() const
{
	return "학생 "  + studentId+" " + getName() + " " + major + " " + getPhoneNumber() + " " + to_string(getTotalDonationMoney());
}

string Student::getKey() const
{
	return studentId;
}
