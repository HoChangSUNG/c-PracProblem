#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		cout << "�ε��Ҽ��� ���� �Է��ϼ���(0���� ����):";
		double num;
		cin >> num;
		if (!num)break;
		cout << "������ : " << (int)num << " �Ҽ����� : " << num - (int)num << endl;
		
	}
	cout << "����";

	return 0;
}