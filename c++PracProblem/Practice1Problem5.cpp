#include <iostream>
using namespace std;

int main() 
{
	int num;
	cout << "입력 : ";
	cin >> num;
	for (int curNum = 2; curNum <= num; curNum++) 
	{
		int cntOfDivisor = 0, sumOfDivisor =0; // 약수 개수, 약수의 합
		for (int j = 1; j < curNum; j++) // 완전수인지 확인
		{
			if (!(curNum % j)) 
			{
				sumOfDivisor += j;
				cntOfDivisor++;
			}
		}

		if (curNum == sumOfDivisor) //완전수 출력
		{ 
			cout << curNum << "(";
			for (int j = 1; j < curNum; j++) 
			{
				if (!(curNum % j))//약수일 경우
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