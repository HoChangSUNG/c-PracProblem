#include "Fraction2.h" 

int main()
{

	
	Fraction2 f1, f2;
	cout << "분자와 분모를 정수로 입력하세요 : ";
	cin >> f1;

	cout << "분자와 분모를 정수로 입력하세요 : ";
	cin >> f2;

	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;

	if (f1 < f2)
		cout << f1 << " < " << f2 << endl;
	else if(f1>f2)
		cout << f1 << " > " << f2 << endl;
	else if(f1 == f2)
		cout << f1 << " == " << f2 << endl;
	return 0;
}