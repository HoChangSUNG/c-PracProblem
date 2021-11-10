#include <fstream>
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Staff.h"
#include "GeneralPerson.h"
using namespace std;

void fileInputAndClose();


int main()
{

	
		Person* ptrPerson[4];
		ptrPerson[0] = new Student("3", "성호창", "컴소공", "010-8434-4855", 123);
		ptrPerson[1] = new Staff("2", "성호창", "컴소공", "010-9456-9451", "0473", 123);
		ptrPerson[2] = new GeneralPerson("V01111", "성1", "010-5412-451",12);
		ptrPerson[3] = new GeneralPerson("성호창1", "010-5412-451", 43);

		for (int i = 0; i < 4; i++) {
			ptrPerson[i]->print();
			cout << endl;
			cout << ptrPerson[i]->toString() << endl;
		}

		cout << (*ptrPerson[0] > *ptrPerson[1]) << endl;

}

void fileInputAndClose()//파일 입출력
{

	ifstream inStream;
	ofstream outStream;
	string line;
	inStream.open("FundList.txt");
	outStream.open("outFile.txt");
	for (int i = 0; !inStream.eof(); i++) {
		getline(inStream, line);
		cout << line << endl;
		outStream << line << endl;
	}
}


