#include <iostream>
using namespace std;

void readNumbers(int arr[], int arrLength);
void printNumbers(int arr[], int arrLength);
void merge(int arr1[], int arr2[], int mergeArr[], int arrLength, int mergeArrLength);

int main()
{
	const int ARR_LENGTH = 5;
	const int MERGE_ARR_LENGTH = 10;
	int arr1[ARR_LENGTH] = {};
	int arr2[ARR_LENGTH] = {};
	int mergeArr[MERGE_ARR_LENGTH] = {};

	cout << "�������� ���� 5�� �Է�: ";
	readNumbers(arr1, ARR_LENGTH);

	cout << "�������� ���� 5�� �Է�: ";
	readNumbers(arr2, ARR_LENGTH);
	
	merge(arr1, arr2, mergeArr, ARR_LENGTH, MERGE_ARR_LENGTH);
	
	printNumbers(mergeArr, MERGE_ARR_LENGTH);
}

void readNumbers(int arr[], int arrLength) 
{
	for (int i = 0; i < arrLength; i++)
	{
		cin >> arr[i];
	}
}

void printNumbers(int arr[], int arrLength) 
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
}

void merge(int arr1[], int arr2[], int mergeArr[], int arrLength, int mergeArrLength) 
{
	int arr1Idx = 0, arr2Idx = 0,mergeArrIdx =0;
	
	while (arr1Idx< arrLength && arr2Idx < arrLength)
	{
		if (arr1[arr1Idx] <= arr2[arr2Idx]) 
		{
			mergeArr[mergeArrIdx] = arr1[arr1Idx++];
		}
		else
		{
			mergeArr[mergeArrIdx] = arr2[arr2Idx++];
		}
		mergeArrIdx++;
	}

	for (int i = arr1Idx; i < arrLength; i++) 
	{
		mergeArr[mergeArrIdx++] = arr1[i];
	}
	for (int i = arr2Idx; i < arrLength; i++) 
	{
		mergeArr[mergeArrIdx++] = arr2[i];
	}

	//arr[]�� �Լ��� �Ű������� ���� �� �迭 ��ü�� �Ű������� ���޹޴� ���� �ƴ� �ش� �迭��
	//���� ��ġ�� �޽��ϴ�.
	//�Լ��� ���� Ÿ���� �迭�� �ϰ� �Ǹ� ���� return�ϴ� ���� �迭�� ù ��ġ
	//������ ���� Ÿ���� �迭 ��ü�� �Ǳ� ������ Ÿ���� ��ġ���� �ʾ� ������ �߰� �˴ϴ�.

}