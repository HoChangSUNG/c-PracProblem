#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int inputNum, randNum;
	int count = 0;
	srand((unsigned int)time(NULL));
	randNum = rand()%100+1;
	
	cout << "���� 100������ �ڿ��� �ϳ��� �����ϰ� �ֽ��ϴ�." << endl;
	while (1) 
	{
		count++;
		cout << "���ڸ� �����ؼ� �Է��ϼ���: ";
		cin >> inputNum;
		if (inputNum == randNum) 
		{
			cout << "������ϴ�!!! " << count << "�� ���� �����ϼ̳׿�!";
			break;
		}
		else if (inputNum > randNum) 
		{
			cout << "���� �����ϰ� �ִ� ���ڴ� " << inputNum << "���ٴ� ���� ���Դϴ�." << endl<<endl;
		}
		else 
		{
			cout << "���� �����ϰ� �ִ� ���ڴ� " << inputNum << "���ٴ� ū ���Դϴ�." << endl << endl;
		}

	}
		
		
	return 0;
}
