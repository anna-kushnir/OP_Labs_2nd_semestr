#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// Створення текстового файлу з текстом, введеним користувачем з клавіатури.
void create_first_file(string path)
{
	string Text;
	ofstream FstFile(path);
	cout << "Введіть текст (щоб завершити введення тексту - введіть ctrl + Z + Enter):\n";
	while (getline(cin, Text)) {
		FstFile << Text << endl;
	}
	FstFile.close();
}
// Створення нового текстового файлу, що складається з рядків вихідного файлу, у яких вилучені 
// всі двосимвольні слова, а в кінці дописана кількість вилучених слів.
bool delete_2_symb_words(string path1, string path2)
{
	ifstream FstFile(path1);
	ofstream SndFile(path2);
	if (!FstFile) {
		cout << "Не вдалося відкрити файл!\n";
		return 0;
	}
	string Text, word;
	int Count = 0;
	while (FstFile)
	{
		Text = "";
		getline(FstFile, Text);
		word = "";
		int k = 0,
			m;
		while (k < Text.length()) {
			m = Text.find(" ", k);
			if (m == string::npos) {
				m = Text.length();
			}
			if (m == k) {
				k++;
			}
			else {
				word = Text.substr(k, m - k);
				if (word.length() == 2) {
					Count++;
					if (k == 0 && m == Text.length()) {
						Text.erase(k, m - k);
					}
					else if (m != Text.length()) {
						Text.erase(k, m - k + 1);
					}
					else {
						Text.erase(k - 1, m - k + 1);
					}
				}
				else {
					k = m + 1;
				}
			}
		}
		SndFile << Text << endl;
	}
	SndFile << "Кількість вилучених слів: " << Count;
	FstFile.close();
	SndFile.close();
	return 1;
}
// Виведення змісту файлу в консоль.
void output_text_of_file(string path)
{
	ifstream File(path);
	if (!File) {
		cout << "Не вдалося відкрити файл для виведення в консоль!\n";
	}
	else {
		string Text;
		while (File) {
			Text = "";
			getline(File, Text);
			cout << Text << endl;
		}
		File.close();
	}
}
