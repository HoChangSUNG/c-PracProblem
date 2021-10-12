#include <iostream>
using namespace std;
int getday(int year, int month, int day);
bool isValidMonthDay(int year, int month, int day);

int main() 
{
	int arr[3] = { 1,2,3 }, arr2[3];
	for (int i = 0; i < 3; i++)
	{
		arr2[i] = arr[i];
	}
	arr2[0] = 5;
	cout << arr[0] << arr2[0] << endl;


}

