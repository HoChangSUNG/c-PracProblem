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

	cout << "오름차순 정수 5개 입력: ";
	readNumbers(arr1, ARR_LENGTH);

	cout << "오름차순 정수 5개 입력: ";
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

	//arr[]은 함수의 매개변수로 받을 때 배열 자체를 매개변수로 전달받는 것이 아닌 해당 배열의
	//시작 위치를 받습니다.
	//함수의 리턴 타입을 배열로 하게 되면 실제 return하는 것은 배열의 첫 위치
	//이지만 리턴 타입은 배열 자체가 되기 때문에 타입이 일치하지 않아 에러가 뜨게 됩니다.

}