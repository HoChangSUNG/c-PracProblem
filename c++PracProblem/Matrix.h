#pragma once

class Matrix 
{
public:
	Matrix();
	void print() const;
	Matrix add(const Matrix& matrix) const;
	Matrix multi(const Matrix& matrix)const;

private:
	static const int length=3;
	int matrixArr[length][length];
};