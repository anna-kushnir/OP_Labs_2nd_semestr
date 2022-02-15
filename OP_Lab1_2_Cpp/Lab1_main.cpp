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

    ofstream FirstFileOut(path1);
    create_first_file(FirstFileOut);
    FirstFileOut.close();

    ifstream FirstFileIn1(path1);
    cout << "\nВихідний файл:\n";
    output_text_of_file(FirstFileIn1);
    FirstFileIn1.close();

    ifstream FirstFileIn2(path1);
    ofstream SecondFileOut(path2);
    int num_of_words = delete_2_symb_words(FirstFileIn2, SecondFileOut);
    if (num_of_words == -1) {
        return -1;
    }
    FirstFileIn2.close();
    SecondFileOut.close();

    ofstream SecondFileApp(path2, ios::app);
    if (!add_number_of_del_words(SecondFileApp, num_of_words)) {
        return -1;
    }
    SecondFileApp.close();

    ifstream SecondFileIn(path2);
    cout << "\nСтворений файл\n";
    output_text_of_file(SecondFileIn);
    SecondFileIn.close();

    system("pause");
    return 0;
}