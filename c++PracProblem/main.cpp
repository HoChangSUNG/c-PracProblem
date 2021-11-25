#include "MyList.hpp"
#include "Person.h"
#include "Student.h"
#include "GeneralPerson.h"
#include "Staff.h"
#include <sstream>

using namespace std;

MyList<Person> linkedList;
void menu();
void loadDonor(string path);
//vector<string> split(string inputLine, char delimiter);
void  insertDonor(string info);
bool isExistDonorPhoneNumber(string info);

int main(int argc, char* argv[])
{
	string path = argv[1];

	cout << " **************발전기금 관리 프로그램**************" << endl << "-----기탁현황-----" << endl;
	loadDonor(path);
	linkedList.print();
	cout << endl;

	while (1)
	{
		int choose;
		menu();
		cin >> choose;
		if (choose == 1)
			linkedList.print();
		else if (choose == 2)
		{
			cin.ignore();
			cout << "신규 기탁자 정보를 입력하세요:";
			string info;
			getline(cin, info);

			if (isExistDonorPhoneNumber(info))
				cout << "!!! 동일한 전화번호가 존재하여 신규 등록 불가 !!!" << endl;
			else
				insertDonor(info);
		}
		else if (choose == 3)
		{
			cout << "변경을 원하는 사번이나 학번 또는 전화번호(XXX-XXXX-XXXX)를 입력하세요 : ";
			string findKey;
			cin >> findKey;
			if (linkedList.isExist(findKey))
			{
				int money = 0;
				cout << "추가 기탁액을 입력하세요 : ";
				cin >> money;
				linkedList.updateElement(findKey, money);
			}
			else
				cout << "해당되는 기탁자가 없습니다" << endl;
		}
		else if (choose == 4)
		{
			cout << "삭제를 원하는 사번이나 학번 또는 전화번호(XXX-XXXX-XXXX)를 입력하세요 : ";
			string findKey;
			cin >> findKey;
			linkedList.deleteElement(findKey);
		}
		else
		{
			cout << "변경 사항을 " << path << "에 저장하려면 W/w, " << path << "을 이전 상태로 유지하려면 C/c :";
			char check;
			cin >> check;
			if (toupper(check) == 'W')
			{
				cout << ">>> 변경 사항 저장 후 종료 <<<" << endl;
				linkedList.fileSave(path);

			}
			else
				cout << ">>> 변경 사항 저장 하지 않고 종료 <<<" << endl;

			break;
		}

		cout << endl;
	}
	
	
}

void menu()
{
	cout << "[1] 전체 조회 / [2] 신규 기탁자 등록 / [3] 기탁정보 변경 / [4] 기탁자 삭제 / [5] 종료 : ";
}

void loadDonor(string path)
{
	const int MAX_LEN = 7;
	string str;
	ifstream inStream;
	string input;
	string inputData[MAX_LEN];

	inStream.open(path);

	for (int i = 0; getline(inStream, str); i++)
	{
		stringstream stream;
		stream.str(str);

		for (int i = 0; stream >> input; i++)
		{
			inputData[i] = input;
		}
		stream.str("");
		Person* donor;

		if (inputData[0] == "학생")
		{
			donor = new Student(inputData[1], inputData[2], inputData[3], inputData[4], stoi(inputData[5]));

		}
		else if (inputData[0] == "교직원")
		{
			donor = new Staff(inputData[1], inputData[2], inputData[3], inputData[4], inputData[5], stoi(inputData[6]));

		}
		else
		{
			donor = new GeneralPerson(inputData[1], inputData[2], inputData[3], stoi(inputData[4]));
		}
		linkedList.add(donor);
	}
}

void  insertDonor(string info)
{
	const int MAX_LEN = 7;
	string input;
	string inputData[MAX_LEN];

	stringstream stream;
	stream.str(info);

	for (int i = 0; stream >> input; i++)
	{
		inputData[i] = input;
	}
	stream.str("");
	Person* donor;

	if (inputData[0] == "학생")
	{

		donor = new Student(inputData[1], inputData[2], inputData[3], inputData[4], stoi(inputData[5]));

	}
	else if (inputData[0] == "교직원")
	{
		donor = new Staff(inputData[1], inputData[2], inputData[3], inputData[4], inputData[5], stoi(inputData[6]));

	}
	else
	{
		donor = new GeneralPerson(inputData[1], inputData[2], stoi(inputData[3]));

	}
	linkedList.add(donor);

	cout << "<신규>";
	donor->print();
}
/*
bool isExistDonorPhoneNumber(string info)
{
	vector<string> inputData = split(info, ' ');

	if (inputData[0] == "학생" || inputData[0] == "교직원")
	{
		return linkedList.isExist(inputData[4]);
	}
	else
	{
		return linkedList.isExist(inputData[2]);
	}
	return false;
}*/

bool isExistDonorPhoneNumber(string info) 
{
	const int MAX_LEN = 7;
	string input;
	string inputData[MAX_LEN];

	stringstream stream;
	stream.str(info);

	for (int i = 0; stream >> input; i++)
	{
		inputData[i] = input;
	}
	stream.str("");

	if (inputData[0] == "학생" || inputData[0] == "교직원")
	{
		return linkedList.isExist(inputData[4]);
	}
	else
	{
		return linkedList.isExist(inputData[2]);
	}
	return false;

}