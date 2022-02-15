#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// ��������� ���������� ����� � �������, �������� ������������ � ���������.
void create_first_file(ofstream& FstFile)
{
    string Text;
    cout << "������ ����� (��� ��������� �������� ������ - ������ ctrl + Z + Enter):\n";
    while (getline(cin, Text)) {
        FstFile << Text << endl;
    }
}
// ��������� ������ ����� � ����� ��������� �����, � ����� �������
// �� ����������� �����.
int delete_2_symb_words(ifstream& FstFile, ofstream& SndFile)
{
    if (!FstFile.is_open()) {
        cout << "�� ������� ������� ���i���� ����!\n";
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
// ��������� � ����� ������ ����� ������� ��������� ���.
int add_number_of_del_words(ofstream& SndFile, int Count)
{
    if (!SndFile.is_open()) {
        cout << "�� ������� ������� ��������� ����!\n";
        return 0;
    }
    SndFile << "ʳ������ ��������� ���: " << Count;
    return 1;
}
// ��������� ����� ����� � �������.
void output_text_of_file(ifstream& File)
{
    if (!File.is_open()) {
        cout << "�� ������� ������� ���� ��� ��������� � �������!\n";
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