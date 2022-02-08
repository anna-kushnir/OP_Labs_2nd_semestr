﻿#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
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

void delete_2_symb_words(string path1, string path2)
{
	ifstream FstFile(path1);
	ofstream SndFile(path2);
	string Text, word;
	int Count = 0;
	while (true)
	{
		Text = "";
		getline(FstFile, Text);
		if (Text == "") {
			break;
		}
		word = "";
		int k = 0,
			m;
		while (k < Text.length())
		{
			m = Text.find(" ", k);
			if (m == k)
			{
				k++;
				continue;
			}
			if (m == string::npos)
			{
				m = Text.length();
			}
			word = Text.substr(k, m - k);
			if (word.length() == 2)
			{
				Count++;
				if (k == 0 && m == Text.length())
				{
					Text.erase(k, m - k);
				}
				else if (m != Text.length())
				{
					Text.erase(k, m - k + 1);
				}
				else
				{
					Text.erase(k - 1, m - k + 1);
				}
			}
			else
			{
				k = m + 1;
			}
		}
		SndFile << Text << endl;
	}
	SndFile << "Кiлькiсть вилучених слiв: " << Count;
	FstFile.close();
	SndFile.close();
}

