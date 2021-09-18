# include <iostream>
using namespace std;

int getFactorial(int n);

int main()
{
	int num;
	cout << "숫자를 입력해주세요 : ";
	cin >> num;
	cout << getFactorial(num);

	return 0;
}

int getFactorial(int n)
{
	if (n <= 1)
		return 1;
	return getFactorial(n - 1) * n;
	//int로 표현할수 있는 값의 범위를 넘기 때문에 50 이상의 정수 입력에 대해 틀린 값이 나옵니다.
	//수를 입력 받을 경우  int로 저장하는 것이 아닌 string형으로 저장하면 무한대의 입력도 처리가 가능합니다
	//그 이유는 문자열은 동적으로 메모리 공간을 동적 할당받고 할당받은 공간이 부족하면 더 큰 공간을 동적 할당받기
	//때문에 계속해서 문자열의 길이를 늘릴 수 있습니다.
	//하지만 이 경우 충분한 공간의 메모리가 남아 있어야 계속해서 메모리 공간을 할당받을 수 있습니다.
}