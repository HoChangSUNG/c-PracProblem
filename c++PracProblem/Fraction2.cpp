#include <iostream>
#include <cmath>
#include "Fraction2.h"
using namespace std;

Fraction2::Fraction2() {
	numerator = 0;
	denominator = 0;
};

Fraction2::~Fraction2() {}

Fraction2::Fraction2(int NewNumerator, int newDenominator) :numerator(NewNumerator), denominator(newDenominator)
{

	if (denominator < 0) // �и�,���� ��� ������ ��� / �и� ����,���ڰ� ����� ���
	{
		numerator = -numerator;
		denominator = -denominator;
	}

	int divisor = getGcd(abs(numerator), abs(denominator));
	if (divisor > 1) // ��� �м��� ���°� �ƴ� ��� ��� �м��� ���·� ����,�и� ����
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

void  Fraction2::changeToIrreducibleFraction(int gcd)//��� �м� ���·� ����
{
	numerator /= gcd;
	denominator /= gcd;
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
	cout << frac.numerator << "/" << frac.denominator;
	return outputStream;
}

istream& operator >>(istream& inputStream, Fraction2& frac)
{
	int tmpNumerator, tmpDenominator;
	cin >> tmpNumerator >> tmpDenominator;

	while (tmpNumerator == 0 || tmpDenominator == 0)
	{
		if (tmpNumerator == 0 && tmpDenominator != 0)
			cout << "���ڰ� 0�̸� �� �˴ϴ�. ���Է¹޽��ϴ�" << endl << "���ڿ� �и� ������ �Է��ϼ��� : ";
		else if(tmpNumerator != 0 && tmpDenominator == 0)
			cout << "�и� 0�̸� �� �˴ϴ�. ���Է¹޽��ϴ�" << endl << "���ڿ� �и� ������ �Է��ϼ��� : ";
		else
			cout << "���ڿ� �и� 0�̸� �� �˴ϴ�. ���Է¹޽��ϴ�" << endl << "���ڿ� �и� ������ �Է��ϼ��� : ";
	}

	frac = Fraction2(tmpNumerator, tmpDenominator);
	return inputStream;
}