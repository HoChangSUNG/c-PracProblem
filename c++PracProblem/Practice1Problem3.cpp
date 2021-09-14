#include <iostream>
using namespace std;
int main() 
{
	while (1)
	{
		int num;
		cout << "크기(3보다 큰 홀수) : ";
		cin >> num;

		if (num == 0)break;
		if (!(num % 2) || num < 4)continue;

		for (int i = 0; i < num / 2 + 1; i++)
		{
			for (int j = 0; j < num / 2 - i; j++) {
				cout << " ";
			}
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}

			cout << endl;
		}
		for (int i = num / 2 - 1; i >= 0; i--) {
			for (int j = 0; j < num / 2 - i; j++) {
				cout << " ";
			}
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	return 0;

}