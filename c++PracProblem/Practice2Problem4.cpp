#include <iostream>
#include <string>
using namespace std;

string getBinary(int num);

int main() 
{
	int number;
	while (1)
	{
		cout << "10���� �Է�(����� 0) : ";
		cin >> number;
		if (!number)
			break;
		cout << getBinary(number)<< endl;
	}
	cout << "����";
	return 0;
}

string getBinary(int num)
{
	int cnt = 0;
	string result = "";

	while (true)
	{
		if (num == 0)
			break;

		if (!(cnt % 4)) 
		{
			result = " "+result;
		}

		result = to_string(num%2)+result;
		num /= 2;
		cnt++;
	}
	return result;
}