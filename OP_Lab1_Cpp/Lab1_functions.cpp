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
		cout << "Не вдалося вiдкрити файл!\n";
		return 0;
	}
	cout << "Введiть текст (ознака кiнця тексту - введення порожнього рядка):\n";
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
