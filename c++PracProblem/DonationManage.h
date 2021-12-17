#pragma once
#include "MyList.hpp"
#include "Person.h"
#include "Student.h"
#include "GeneralPerson.h"
#include "Staff.h"
#include <sstream>

using namespace std;

class DonationManage 
{
public:
	DonationManage();
	void run(string path);
private:
	MyList<Person> linkedList;
	void menu();
	void loadDonor(string path);
	void  insertDonor(string info);
	bool isExistDonorPhoneNumber(string info);
	bool isExistDonorKey(string info);
};