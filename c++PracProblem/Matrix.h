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
	static const int LENGTH=3; //����� �빮�ڷ�
	int matrixArr[LENGTH][LENGTH];
};