#include <iostream>
#include <ctime>
#include "Matrix.h"
using namespace std;

Matrix::Matrix() 
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			matrixArr[i][j] = rand() % 21 -10;
		}
	}
}

Matrix::~Matrix() {}

void  Matrix::print() const
{
	cout << endl;
	for (int i = 0; i < LENGTH; i++)
	{
		cout << "|";
		for (int j = 0; j < LENGTH; j++)
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
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			addMatrix.matrixArr[i][j] = matrixArr[i][j] + matrix.matrixArr[i][j];
		}
	}
	return addMatrix;
}

Matrix Matrix::multi(const Matrix& matrix) const
{
	Matrix multiMatrix;

	for (int i = 0; i < LENGTH; i++) // multiMatrix�� ���� ���� 0���� �ʱ�ȭ�ؾ� ��
	{
		for (int j = 0; j < LENGTH; j++)
		{
			multiMatrix.matrixArr[i][j] = 0;
		}
	}

	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			for (int k = 0; k < LENGTH; k++)
			{
				multiMatrix.matrixArr[i][k] += matrixArr[i][j] * matrix.matrixArr[j][k];
			}
		}
	}
	return multiMatrix;
}