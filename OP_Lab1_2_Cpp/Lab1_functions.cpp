#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// Створення текстового файлу з текстом, введеним користувачем з клавіатури.
void create_first_file(ofstream& FstFile)
{
    string Text;
    cout << "Введіть текст (щоб завершити введення тексту - введіть ctrl + Z + Enter):\n";
    while (getline(cin, Text)) {
        FstFile << Text << endl;
    }
}
// Створення нового файлу з рядків вихідного файлу, у якому видалені
// всі двосимвольні слова.
int delete_2_symb_words(ifstream& FstFile, ofstream& SndFile)
{
    if (!FstFile.is_open()) {
        cout << "Не вдалося відкрити вихiдний файл!\n";
        return -1;
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
    return Count;
}
// Додавання в кінець нового файлу кількості вилучених слів.
int add_number_of_del_words(ofstream& SndFile, int Count)
{
    if (!SndFile.is_open()) {
        cout << "Не вдалося відкрити створений файл!\n";
        return 0;
    }
    SndFile << "Кількість вилучених слів: " << Count;
    return 1;
}
// Виведення змісту файлу в консоль.
void output_text_of_file(ifstream& File)
{
    if (!File.is_open()) {
        cout << "Не вдалося відкрити файл для виведення в консоль!\n";
    }
    else {
        string Text;
        while (File) {
            Text = "";
            getline(File, Text);
            cout << Text << endl;
        }
    }
}