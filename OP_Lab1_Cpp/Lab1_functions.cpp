#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int create_first_file(string path)
{
	string Text;
	ofstream FstFile(path);
	if (!FstFile) {
		cout << "�� ������� �i������ ����!\n";
		return 0;
	}
	cout << "����i�� ����� (������ �i��� ������ - �������� ���������� �����):\n";
	while (true)
	{
		Text = "";
		getline(cin, Text);
		if (Text != "") {
			FstFile << Text << endl;
		}
		else {
			break;
		}
	}
	FstFile.close();
	return 1;
}
