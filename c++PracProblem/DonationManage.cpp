#include "DonationManage.h"

DonationManage::DonationManage() {}

void DonationManage::run(string path)
{
	cout << " **************������� ���� ���α׷�**************" << endl << "-----��Ź��Ȳ-----" << endl;
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
			cout << "�ű� ��Ź�� ������ �Է��ϼ���:";
			string info;
			getline(cin, info);

			if (isExistDonorPhoneNumber(info))
				cout << "!!! ������ ��ȭ��ȣ�� �����Ͽ� �ű� ��� �Ұ� !!!" << endl;
			else if (isExistDonorKey(info))
				cout << "!!! ������ key�� �����Ͽ� �ű� ��� �Ұ� !!!" << endl;
			else
				insertDonor(info);
		}
		else if (choose == 3)
		{
			cout << "������ ���ϴ� ����̳� �й� �Ǵ� ��ȭ��ȣ(XXX-XXXX-XXXX)�� �Է��ϼ��� : ";
			string findKey;
			cin >> findKey;
			if (linkedList.isExist(findKey))
			{
				int money = 0;
				cout << "�߰� ��Ź���� �Է��ϼ��� : ";
				cin >> money;
				linkedList.updateElement(findKey, money);
			}
			else
				cout << "�ش�Ǵ� ��Ź�ڰ� �����ϴ�" << endl;
		}
		else if (choose == 4)
		{
			cout << "������ ���ϴ� ����̳� �й� �Ǵ� ��ȭ��ȣ(XXX-XXXX-XXXX)�� �Է��ϼ��� : ";
			string findKey;
			cin >> findKey;
			linkedList.deleteElement(findKey);
		}
		else
		{
			cout << "���� ������ " << path << "�� �����Ϸ��� W/w, " << path << "�� ���� ���·� �����Ϸ��� C/c :";
			char check;
			cin >> check;
			if (toupper(check) == 'W')
			{
				cout << ">>> ���� ���� ���� �� ���� <<<" << endl;
				linkedList.fileSave(path);

			}
			else
				cout << ">>> ���� ���� ���� ���� �ʰ� ���� <<<" << endl;

			break;
		}

		cout << endl;
	}

}

void DonationManage::menu()
{
	cout << "[1] ��ü ��ȸ / [2] �ű� ��Ź�� ��� / [3] ��Ź���� ���� / [4] ��Ź�� ���� / [5] ���� : ";
}

void DonationManage::loadDonor(string path) 
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

		if (inputData[0] == "�л�")
		{
			donor = new Student(inputData[1], inputData[2], inputData[3], inputData[4], stoi(inputData[5]));

		}
		else if (inputData[0] == "������")
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

void  DonationManage::insertDonor(string info) 
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

	if (inputData[0] == "�л�")
	{

		donor = new Student(inputData[1], inputData[2], inputData[3], inputData[4], stoi(inputData[5]));

	}
	else if (inputData[0] == "������")
	{
		donor = new Staff(inputData[1], inputData[2], inputData[3], inputData[4], inputData[5], stoi(inputData[6]));

	}
	else
	{
		donor = new GeneralPerson(inputData[1], inputData[2], stoi(inputData[3]));

	}
	linkedList.add(donor);

	cout << "<�ű�>";
	donor->print();
}

bool DonationManage::isExistDonorPhoneNumber(string info) 
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

	if (inputData[0] == "�л�" || inputData[0] == "������")
	{
		return linkedList.isExist(inputData[4]);
	}
	else
	{
		return linkedList.isExist(inputData[2]);
	}
	return false;
}

bool DonationManage::isExistDonorKey(string info)
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

	if (inputData[0] == "�л�" || inputData[0] == "������")
	{
		return linkedList.isExist(inputData[1]);
	}

	return false;
}