#pragma once
#include <iostream>
using namespace std;
class Fraction2
{

public:
	Fraction2();
	Fraction2(int numerator, int denominator);

	int getGcd(int num1, int num2) const;
	int getLcm(int num1, int num2) const;

	const Fraction2 operator +(const Fraction2& frac) const;
	const Fraction2 operator -(const Fraction2& frac) const;
	const Fraction2 operator *(const Fraction2& frac) const;
	const Fraction2 operator /(const Fraction2& frac) const;

	const bool operator >(const Fraction2& frac) const;
	const bool operator <(const Fraction2& frac) const;
	const bool operator ==(const Fraction2& frac) const;

	void changeToIrreducibleFraction(int gcd);// ��� �м��� ���·� ����,�и� ����

	friend ostream& operator <<(ostream& outputStream,const Fraction2& frac);
	friend istream& operator >>(istream& inStream, Fraction2& frac);

private:
	int numerator, denominator;
};