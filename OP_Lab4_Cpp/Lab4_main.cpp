/* ��������� ���� "Numeral_8", ������ ����� � ������� �����. ���������� ��� ������ ����� ������� 
������������, �������, ������ ������������ ����� � �������, � ���� ���� � ���������� ��������. 
������������� ���������: ���������� "++" - ��� ������������� ��������� �����, "+=" - ��� ��������� 
���� �� ������� ��������, "+" - ��� ��������� ���� �������� �����. �������� ��� �������� ����� 
(N1, N2, N3), �������������� ���� ������������. �������������� ����� N1, � ����� N2 �������� ��
������� ��������. ������ ���� ������� ����� N1 �� N2 � �������� �� � N3. ��������� �������� �������� 
N3 � �������� ������ ����� ��������� (��������� � ����������). */

#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	int n1, n2;
	cout << "����i�� �i�i����� ����� N1: "; cin >> oct >> n1;
	cout << "����i�� �i�i����� ����� N2: "; cin >> oct >> n2;
	Numeral_8 N1(n1);
	Numeral_8 N2(n2);
	Numeral_8 N3;
	cout << "\nN1 �� N2 � �i�i����i� ��:\n" << oct << N1.GetNum() << endl << oct << N2.GetNum() << endl;
	cout << "\nN1 �� N2 � ��������i� ��:\n" << dec << N1.GetNum() << endl << dec << N2.GetNum() << endl;
	int n;
	cout << "����i�� n: "; 
	cin >> oct >> n;
	++N1;
	N2 += n;
	cout << "\n++N1: " << oct << N1.GetNum();
	cout << "\nN2 += n: " << oct << N2.GetNum();
	N3 = N1 + N2;
	cout << "\nN1 + N2 = " << oct << N3.GetNum() << endl;
	N1.ConvertToBin();
	N2.ConvertToBin();
	N3.ConvertToBin();

	system("pause");
	return 0;
}