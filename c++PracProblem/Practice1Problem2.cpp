#include <iostream>
using namespace std;

int main()
{
	while (1) 
	{
		int num;
		cout << "���� ���� �Է��ϼ���(0���� ����):";
		cin >> num;

		if (!num)break;

		while (num/10)
		{
			num /= 10;

		}
		cout <<"���� ū �ڸ���:" << num << endl;
		
	}
	cout << "����";

	return 0;
}