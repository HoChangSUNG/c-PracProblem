#include <iostream>
using namespace std;

int main() {
	int maxStep, multiple, p;

	cout << "��ܱ��� ����ұ��? :";
	cin >> maxStep;
	cout << "����� ���ұ��? : ";
	cin >> multiple;
	cout << "���ٿ� ��ܾ� ����ұ��? : ";
	cin >> p;

	int line = maxStep / p; //�� ����
	if (!maxStep % p) {
		line +=1;
	}

	for (int i =0; i <= line; i++) 
	{
		for (int j = 1; j <= multiple; j++) 
		{
			for (int k = p*i+1; k <= p*i+p; k++) //������� Ȯ�� 
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