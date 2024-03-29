/* ��������� ���� "Numeral_8", ������ ����� � ������� �����. ���������� ��� ������ ����� ������� 
������������, �������, ������ ������������ ����� � �������, � ���� ���� � ���������� ��������. 
������������� ���������: ���������� "++" - ��� ������������� ��������� �����, "+=" - ��� ��������� 
���� �� ������� ��������, "+" - ��� ��������� ���� �������� �����. �������� ��� �������� ����� 
(N1, N2, N3), �������������� ���� ������������. �������������� ����� N1, � ����� N2 �������� ��
������� ��������. ������ ���� ������� ����� N1 �� N2 � �������� �� � N3. ��������� �������� �������� 
N3 � �������� ������ ����� ��������� (��������� � ����������). */

#include "Functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	long long n1;
	cout << "����i�� �i�i����� ����� N1: "; cin >> n1;
	while (!isNumeral8(n1)) {
		cout << "�� ����� �����, �� �� �i����i�� �i�i����i� ��! ����i�� N1 �� ���: "; cin >> n1;
	}
	Numeral_8 N1(n1), N2(N1), N3;
	cout << "\n������i ���i:";
	outputNums(N1, N2, N3);

	long long n;
	cout << "\n����i�� ��������, �� ��� �� ������ ��i������ N2 (�i�i����� ��): "; cin >> n;
	while (!isNumeral8(n)) {
		cout << "�� ����� ����� � ���i��i� ������i ��������! ��������� �� ���: "; cin >> n;
	}
	++N1;
	N2 += n;
	N3 = N1 + N2;
	cout << "\n��i���i ���i:";
	outputNums(N1, N2, N3);
	cout << "\nN3, ������������ � ��i����� �� ��������� ��������:  " << N3.convertToBinUsual();
	cout << "\nN3, ������������ � ��i����� �� ���������� ��������: " << N3.convertToBinReduced() << "\n\n";
	system("pause");
	return 0;
}