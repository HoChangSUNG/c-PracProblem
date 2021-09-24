#include <iostream>
using namespace std;

void matrixAdd(int arr1[][3], int arr2[][3], int addArr[][3]);
void matrixMuli(int arr1[][3], int arr2[][3], int multiArr[][3]);
void matrixPrint(int arr[][3]);
const int matrixLength = 3;

int main() 
{ 
	
	int arr1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int arr2[3][3] = { {1,-1,0},{0,-1,1},{-1,1,0} };
	int addArr[3][3] = {};
	int multiArr[3][3] = {};

	matrixAdd(arr1, arr2, addArr);
	matrixMuli(arr1, arr2, multiArr);

	cout << "두 행렬의 합은 " << endl;
	matrixPrint(addArr);
	cout << "두 행렬의 곱은 " << endl;
	matrixPrint(multiArr);


}
void matrixAdd(int arr1[][3], int arr2[][matrixLength], int addArr[][matrixLength])
{
	for (int i = 0; i < matrixLength; i++)
	{
		for (int j = 0; j < matrixLength; j++)
		{
			addArr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
}

void matrixMuli(int arr1[][matrixLength], int arr2[][matrixLength], int multiArr[][matrixLength])
{
	for (int i = 0; i < matrixLength; i++)
	{
		for (int j = 0; j < matrixLength; j++)
		{
			for (int k = 0; k < matrixLength; k++)
			{
				multiArr[i][k] += arr1[i][j] * arr2[j][k];
			}
		}
	}
}

void matrixPrint(int arr[][matrixLength])
{
	for (int i = 0; i < matrixLength; i++)
	{
		cout << "|";
		for (int j = 0; j < matrixLength; j++)
		{
			printf("%3d", arr[i][j]);
		}
		cout << " |" << endl;
	}
}