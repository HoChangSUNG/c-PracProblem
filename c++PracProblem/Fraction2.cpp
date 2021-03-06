#include <iostream>
#include <cmath>
#include "Fraction2.h"
using namespace std;

Fraction2::Fraction2() {
	numerator = 0;
	denominator = 1;// 분모는 0이 될 수 없음.
};

Fraction2::~Fraction2() {}

Fraction2::Fraction2(int NewNumerator, int newDenominator) :numerator(NewNumerator), denominator(newDenominator)
{

	if (denominator < 0) // 분모,분자 모두 음수일 경우 / 분모가 음수,분자가 양수일 경우
	{
		numerator = -numerator;
		denominator = -denominator;
	}

	int divisor = getGcd(getAbs(numerator), getAbs(denominator));
	if (divisor > 1) // 기약 분수의 형태가 아닐 경우 기약 분수의 형태로 분자,분모를 변경
	{
		changeToIrreducibleFraction(divisor);
	}

}

int Fraction2::getGcd(int num1, int num2) const
{
	while (1) {
		int r = num1 % num2;
		if (r == 0) return num2;

		num1 = num2;
		num2 = r;
	}
}

int Fraction2::getLcm(int num1, int num2) const
{
	return num1 * num2 * getGcd(num1, num2);
}

void  Fraction2::changeToIrreducibleFraction(int gcd)//기약 분수 형태로 변경
{
	numerator /= gcd;
	denominator /= gcd;
}

int Fraction2::getAbs(int num) const
{
	if (num < 0)
		num = -num;
	return num;
}

const Fraction2 Fraction2::operator +(const Fraction2& frac) const 
{
	int resultDenominator = getLcm(denominator, frac.denominator);
	return Fraction2(numerator * (resultDenominator / denominator) + frac.numerator * (resultDenominator / frac.denominator), resultDenominator);
}

const Fraction2 Fraction2::operator -(const Fraction2& frac) const 
{
	int resultDenominator = getLcm(denominator, frac.denominator);
	return Fraction2(numerator * (resultDenominator / denominator) - frac.numerator * (resultDenominator / frac.denominator), resultDenominator);
}

const Fraction2 Fraction2::operator *(const Fraction2& frac) const 
{
	return Fraction2(numerator * frac.numerator, denominator * frac.denominator);
}

const Fraction2 Fraction2::operator /(const Fraction2& frac) const 
{
	return Fraction2(numerator * frac.denominator, denominator * frac.numerator);
}

const bool Fraction2::operator >(const Fraction2& frac) const
{
	int resultDenominator = getLcm(denominator, frac.denominator);
	return ((numerator * (resultDenominator / denominator)) > (frac.numerator * (resultDenominator / frac.denominator)));
}

const bool Fraction2::operator <(const Fraction2& frac) const
{
	int resultDenominator = getLcm(denominator, frac.denominator);
	return ((numerator * (resultDenominator / denominator)) < (frac.numerator * (resultDenominator / frac.denominator)));
}

const bool Fraction2::operator ==(const Fraction2& frac) const 
{
	int resultDenominator = getLcm(denominator, frac.denominator);
	return ((numerator * (resultDenominator / denominator)) == (frac.numerator * (resultDenominator / frac.denominator)));
}

ostream& operator <<(ostream& outputStream,const Fraction2& frac)
{
	outputStream << frac.numerator << "/" << frac.denominator;
	return outputStream;
}

istream& operator >>(istream& inputStream, Fraction2& frac)
{
	int tmpNumerator, tmpDenominator;
	inputStream >> tmpNumerator >> tmpDenominator;

	while (tmpNumerator == 0 || tmpDenominator == 0)
	{
		if (tmpNumerator == 0 && tmpDenominator != 0)
			cout << "분자가 0이면 안 됩니다. 재입력받습니다" << endl << "분자와 분모를 정수로 입력하세요 : ";
		else if(tmpNumerator != 0 && tmpDenominator == 0)
			cout << "분모가 0이면 안 됩니다. 재입력받습니다" << endl << "분자와 분모를 정수로 입력하세요 : ";
		else
			cout << "분자와 분모가 0이면 안 됩니다. 재입력받습니다" << endl << "분자와 분모를 정수로 입력하세요 : ";
		inputStream >> tmpNumerator >> tmpDenominator;
	}

	frac = Fraction2(tmpNumerator, tmpDenominator);
	return inputStream;
}