#include "header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string path1, path2;
	path1 = "FirstFile.txt";
	path2 = "SecondFile.txt";
	int flag = create_first_file(path1);
	if (!flag)
	{
		return -1;
	}


	system("pause");
	return 0;
}