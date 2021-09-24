#pragma once
#include <iostream>

class Fraction
{

public:
	Fraction();
	Fraction(int numerator, int denominator);


	int getGcd(int num1, int num2) const;
	int getLcm(int num1, int num2) const;

	const Fraction add(const Fraction& frac)const;
	const Fraction substract(const Fraction& frac)const;
	const Fraction multiply(const Fraction& frac)const;
	const Fraction divide(const Fraction& frac)const;

	void print()const;
	void changeToIrreducibleFraction(int gcd);

private:
	int numerator, denominator;
};