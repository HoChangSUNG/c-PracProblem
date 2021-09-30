#pragma once

class Matrix 
{
public:
	Matrix();
	~Matrix();

	void print() const;
	Matrix add(const Matrix& matrix) const;
	Matrix multi(const Matrix& matrix)const;

private:
	static const int LENGTH=3; //상수는 대문자로
	int matrixArr[LENGTH][LENGTH];
};