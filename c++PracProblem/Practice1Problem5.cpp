#include <iostream>
using namespace std;

int main() 
{
	int num;
	cout << "�Է� : ";
	cin >> num;
	for (int curNum = 2; curNum <= num; curNum++) 
	{
		int cntOfDivisor = 0, sumOfDivisor =0; // ��� ����, ����� ��
		for (int j = 1; j < curNum; j++) // ���������� Ȯ��
		{
			if (!(curNum % j)) 
			{
				sumOfDivisor += j;
				cntOfDivisor++;
			}
		}

		if (curNum == sumOfDivisor) //������ ���
		{ 
			cout << curNum << "(";
			for (int j = 1; j < curNum; j++) 
			{
				if (!(curNum % j))//����� ���
				{
					cntOfDivisor--;
					cout << j;
					if (cntOfDivisor)cout << "+";
				}
			}
			cout << ")"<<endl;
		}
	}
	return 0;
}