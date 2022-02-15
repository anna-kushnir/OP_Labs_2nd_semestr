/*Створити текстовий файл. Сформувати новий текстовий файл, що
складається з рядків вихідного файлу, у яких вилучені всі двосимвольні слова.
Визначити і дописати в кінець нового файлу кількість вилучених слів.
Вивести вміст вихідного і створеного файлів.*/

#include "header.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string path1, path2;
	path1 = "FirstFile.txt";
	path2 = "SecondFile.txt";
	create_first_file(path1);
	cout << "\nВихідний файл:\n";
	output_text_of_file(path1);
	int num_of_words = delete_2_symb_words(path1, path2);
	if (num_of_words == -1) {
		return -1;
	}
	if (!add_number_of_del_words(path2, num_of_words)) {
		return -1;
	}
	cout << "\nСтворений файл\n";
	output_text_of_file(path2);
	system("pause");
	return 0;
}