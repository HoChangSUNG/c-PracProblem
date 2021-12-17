#include "DonationManage.h"

int main(int argc, char* argv[])
{
	string path = argv[1];
	DonationManage manage;
	manage.run(path);
	return 0;
}

