#include "Fraction.h" 

int main()
{
	Fraction f1(4, 6), f2(2, 5), f3;

	f3 = f1.add(f2);
	f3.print();

	f3 = f1.substract(f2);
	f3.print();

	f3 = f1.multiply(f2);
	f3.print();
	
	f3 = f1.divide(f2);
	f3.print();

	return 0;
}