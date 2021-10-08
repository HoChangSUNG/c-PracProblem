#include <iostream>
using namespace std;
void printArr(int* arr, int size);

int main()
{
	const int MAX = 5;
	int arr1[MAX] = { 1,2,3,4,5 }, arr2[MAX], *p=new int[MAX];
	for (int i = 0; i < MAX; i++)
		arr2[i] = arr1[i];
	for (int i = 0; i < MAX; i++)
		p[i] = arr1[i];
	p[0] = 99;
	printArr(arr1, 5); printArr(arr2, 5); printArr(p, 5);
	delete[] p;

	return 0;
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i]<<" ";
	cout << endl;
}