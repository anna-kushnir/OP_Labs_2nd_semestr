#include "header.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string path1, path2;
	path1 = "FirstFile.txt";
	path2 = "SecondFile.txt";
	int flag = create_first_file(path1);
	if (!flag)
	{
		return -1;
	}
	delete_2_symb_words(path1, path2);


	system("pause");
	return 0;
}