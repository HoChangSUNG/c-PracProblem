#include <iostream>
using namespace std;

void showDigit(int n);
void showReverseDigit(int n);

int main()
{
	int val;
	cout << "정수 입력: ";
	cin >> val;

	cout << "바로 출력 : ";
	showDigit(val);
	cout << endl;

	cout << "거꾸로 출력: ";
	showReverseDigit(val);

	return 0;
}

void showDigit(int n) 
{
	if (n == 0)
		return;
	showDigit(n / 10);
	cout << n % 10 << " ";
	return;
}

void showReverseDigit(int n)
{
	if (n == 0)
		return;
	cout << n % 10 << " ";
	showReverseDigit(n / 10);
	return;
}
