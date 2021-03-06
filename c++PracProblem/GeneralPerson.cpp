#include "GeneralPerson.h"
#include <iostream>

using namespace std;
int GeneralPerson::maxIntNumber = 0;

GeneralPerson::GeneralPerson(string newName, string newPhoneNumber, int newTotalMoney)
	:Person(newName, newPhoneNumber, newTotalMoney)// 일반 기탁자코드를 자동 생성하는 경우
{
	generateDonorNumber();
}

GeneralPerson::GeneralPerson(string newDonorNumber,string newName, string newPhoneNumber, int newTotalMoney) 
	: Person(newName, newPhoneNumber, newTotalMoney), donorNumber(newDonorNumber)// 일반 기탁자코드를 입력 받을 경우
{
	updateMaxIntNumber(donorNumberToInt(newDonorNumber));
}

GeneralPerson::GeneralPerson(const GeneralPerson& generalPerson) :Person(generalPerson)
{
	donorNumber = generalPerson.getDonorNumber();
}

GeneralPerson::~GeneralPerson()
{
	if (maxIntNumber == donorNumberToInt(donorNumber))
		maxIntNumber--;
}
string GeneralPerson::getDonorNumber()const {
	return donorNumber;
}



void GeneralPerson::print() const 
{
	cout << "[ 일반 ] " << getName() << "(기탁자코드:" << donorNumber << ") " << getPhoneNumber() << " " << getTotalDonationMoney()<<endl;

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

int GeneralPerson::donorNumberToInt(string donorNumber)const //기탁자 코드 뒷자리 5개를 int로 변경
{
	int base = 10;
	int result = 0;
	for(int i=1;i< donorNumber.length();i++)
	{
		result = base * result + (donorNumber[i] - '0');
	}

	return result;
}

void GeneralPerson::updateMaxIntNumber(int newNumber)//입력받은 기탁자 코드가 현재 제일 큰 기탁자 코드인 경우
{
	if (maxIntNumber < newNumber)
		maxIntNumber = newNumber;
}

void GeneralPerson::generateDonorNumber()//기탁자 코드 생성
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

string GeneralPerson::getKey() const
{
	return donorNumber;
}