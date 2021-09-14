#include <iostream>
using namespace std;

int main() {
	int maxStep, multiple, p;

	cout << "몇단까지 출력할까요? :";
	cin >> maxStep;
	cout << "몇까지 곱할까요? : ";
	cin >> multiple;
	cout << "한줄에 몇단씩 출력할까요? : ";
	cin >> p;

	int line = maxStep / p; //줄 개수
	if (!maxStep % p) {
		line +=1;
	}

	for (int i =0; i <= line; i++) 
	{
		for (int j = 1; j <= multiple; j++) 
		{
			for (int k = p*i+1; k <= p*i+p; k++) //몇단인지 확인 
			{
				if (k > maxStep) break;
				printf("%2d x %2d = %5d   ", k, j, k * j);
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}