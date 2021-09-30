#include <iostream>
#include <cmath>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;// �и�� 0�� �� �� ����.
};

Fraction::~Fraction() {}

Fraction::Fraction(int NewNumerator, int newDenominator) :numerator(NewNumerator), denominator(newDenominator)
{
	if (denominator < 0) // �и�,���� ��� ������ ��� / �и� ����,���ڰ� ����� ���
	{
		numerator = -numerator;
		denominator = -denominator;
	}

	int divisor = getGcd(getAbs(numerator), getAbs(denominator));
	if (divisor > 1) // ��� �м��� ���°� �ƴ� ��� ��� �м��� ���·� ����,�и� ����
	{
		changeToIrreducibleFraction(divisor);
	}
		
}

int Fraction::getGcd(int num1, int num2) const
{
	while (1) {
		int r = num1 % num2;
		if (r == 0) return num2;

		num1 = num2;
		num2 = r;
	}
}

int Fraction::getLcm(int num1, int num2) const
{
	return num1 * num2 * getGcd(num1, num2);
}

const Fraction Fraction::add(const Fraction& frac) const
{
	int resultDenominator = getLcm(denominator, frac.denominator);
	return Fraction(numerator * (resultDenominator / denominator) + frac.numerator * (resultDenominator / frac.denominator), resultDenominator);
}

const Fraction Fraction::substract(const Fraction& frac) const
{
	int resultDenominator = getLcm(denominator, frac.denominator);
	return Fraction(numerator * (resultDenominator / denominator) - frac.numerator * (resultDenominator / frac.denominator), resultDenominator);
}

const Fraction Fraction::multiply(const Fraction& frac) const
{
	return Fraction(numerator * frac.numerator, denominator * frac.denominator);
}

const Fraction Fraction::divide(const Fraction& frac) const
{
	return Fraction(numerator * frac.denominator, denominator * frac.numerator);
}

void Fraction::print()const 
{
	cout << numerator << "/" << denominator << endl;;
}

void  Fraction::changeToIrreducibleFraction(int gcd)//��� �м� ���·� ����
{
	numerator /= gcd;
	denominator /= gcd;
}

int Fraction::getAbs(int num) const
{
	if (num < 0)
		num = -num;
	return num;
}
