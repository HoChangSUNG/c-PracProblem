#include "Fraction2.h" 

int main()
{

	
	Fraction2 f1, f2;
	cout << "���ڿ� �и� ������ �Է��ϼ��� : ";
	cin >> f1;

	cout << "���ڿ� �и� ������ �Է��ϼ��� : ";
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