#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int inputNum, randNum;
	int count = 0;
	srand((unsigned int)time(NULL));
	randNum = rand()%100+1;
	
	cout << "나는 100이하의 자연수 하나를 생각하고 있습니다." << endl;
	while (1) 
	{
		count++;
		cout << "숫자를 짐작해서 입력하세요: ";
		cin >> inputNum;
		if (inputNum == randNum) 
		{
			cout << "맞췄습니다!!! " << count << "번 만에 성공하셨네요!";
			break;
		}
		else if (inputNum > randNum) 
		{
			cout << "내가 생각하고 있는 숫자는 " << inputNum << "보다는 작은 수입니다." << endl<<endl;
		}
		else 
		{
			cout << "내가 생각하고 있는 숫자는 " << inputNum << "보다는 큰 수입니다." << endl << endl;
		}

	}
		
		
	return 0;
}
