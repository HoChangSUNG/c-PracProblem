#include <iostream>
#include <ctime>
#include "Matrix.h"
using namespace std;

Matrix::Matrix() 
{

	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < length; j++) 
		{
			matrixArr[i][j] = rand() % 21 -10;
		}
	}
}

void  Matrix::print() const
{
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "|";
		for (int j = 0; j < length; j++)
		{
			printf("%5d", matrixArr[i][j]);
		}
		cout << " |" << endl;
	}
	cout << endl;

}

Matrix Matrix::add(const Matrix& matrix) const
{
	Matrix addMatrix;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			addMatrix.matrixArr[i][j] = matrixArr[i][j] + matrix.matrixArr[i][j];
		}
	}
	return addMatrix;
}

Matrix Matrix::multi(const Matrix& matrix) const
{
	Matrix multiMatrix;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			for (int k = 0; k < length; k++)
			{
				multiMatrix.matrixArr[i][k] += matrixArr[i][j] * matrix.matrixArr[j][k];
			}
		}
	}
	return multiMatrix;
}