#pragma once
#include <iostream>

class Fraction
{

public:
	Fraction();
	Fraction(int numerator, int denominator);
	~Fraction();

	const Fraction add(const Fraction& frac)const;
	const Fraction substract(const Fraction& frac)const;
	const Fraction multiply(const Fraction& frac)const;
	const Fraction divide(const Fraction& frac)const;

	void print()const;
	void changeToIrreducibleFraction(int gcd);

private:
	int numerator, denominator;
	// 약분,통분,절대값 함수는 private로 선언하는 것이 올바름.
	int getGcd(int num1, int num2) const;
	int getLcm(int num1, int num2) const;
	int getAbs(int num) const;

};