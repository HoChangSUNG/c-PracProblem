#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person {
public:
	Person(string newName, string newPhoneNumber, int newTotalMoney);
	~Person();
	virtual void print() const;
	virtual string toString() const;

	string getName()const;
	string getPhoneNumber()const;
	int getTotalDonationMoney()const;

	void setName(string newName);
	void setPhoneNumber(string newPhoneNumber);
	void setTotalDonationMoney(int newTotalMoney);

	bool operator >(const Person &person)const;
private:
	string name;
	string phoneNumber;
	int totalDonationMoney;
};