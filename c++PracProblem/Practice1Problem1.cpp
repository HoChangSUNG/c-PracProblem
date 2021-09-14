#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		cout << "부동소수점 값을 입력하세요(0에서 종료):";
		double num;
		cin >> num;
		if (!num)break;
		cout << "정수부 : " << (int)num << " 소숫점부 : " << num - (int)num << endl;
		
	}
	cout << "종료";

	return 0;
}