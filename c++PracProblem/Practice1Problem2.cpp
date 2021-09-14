#include <iostream>
using namespace std;

int main()
{
	while (1) 
	{
		int num;
		cout << "정수 값을 입력하세요(0에서 종료):";
		cin >> num;

		if (!num)break;

		while (num/10)
		{
			num /= 10;

		}
		cout <<"제일 큰 자리수:" << num << endl;
		
	}
	cout << "종료";

	return 0;
}