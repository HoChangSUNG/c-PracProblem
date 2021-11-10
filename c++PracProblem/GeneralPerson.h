#pragma once
#include "Person.h"
class GeneralPerson : public Person {

public:
	GeneralPerson(string newName,string newPhoneNumber,int newTotalMoney);
	GeneralPerson(string newDonorNumber,string newName, string newPhoneNumber, int newTotalMoney);

	string getDonorNumber()const;
	virtual void print() const;
	virtual string toString() const;

	bool operator >(const Person& person)const;
private:
	string donorNumber;

	void generateDonorNumber();
	int getDigit(int number)const;
	int donorNumberToInt(string donorNumber)const;
	string intToStr(int number)const ;
	void updateMaxIntNumber(int newNumber);
	static int maxIntNumber;

};