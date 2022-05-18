/*�������� ���� TIntNumber, ���� ����������� ���� ����� � ����-��� ������ �������� � ������ ������
��� ��������� ������ �����, ��������� ����� �� ����������� ����� � ������� ������� �������� (�� ��������
�������). �� ����� ����� ����� �������� �����-������� TIntNumber2 �� TIntNumber8, �� �������������
������ �� ������ �����. �������� m �������� �� n �������� �����. ������ ���� �������� �� ��������
�����. ��������� �������� �������� ���� �������� ����� � �������� ������. ���������, ���� ���� ����� �����
(�������� �� ��������).*/

#include "Functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int m, n;
	cout << "������ m (������� �������� �����): "; cin >> m;
	cout << "������ n (������� �������� �����): "; cin >> n;

	cout << "\n---������� �������� �������� �����---\n\n";
	vector<TIntNumber2> binNums = inputNums<TIntNumber2>(m, 2);
	cout << "\n---������� �������� �������� �����---\n\n";
	vector<TIntNumber8> octNums = inputNums<TIntNumber8>(n, 8);

	cout << "\n---������ ���� ���---\n";
	cout << "\n������ �����: ";
	outputNums<TIntNumber2>(binNums);
	cout << "\n³����� �����: ";
	outputNums<TIntNumber8>(octNums);

	TIntNumber2 sumBin = countSum<TIntNumber2>(binNums);
	TIntNumber8 sumOct = countSum<TIntNumber8>(octNums);
	cout << "\n\n���� �������� �����: " << sumBin;
	cout << "\n���� �������� �����: " << sumOct;
	TIntNumber2 sumOctInBin = sumOct.convertToBase();
	cout << "\n�������� �������� ���� �������� ����� � ��������� ������: " << sumOctInBin << "\n";

	findMin(sumBin, sumOctInBin);

	system("pause");
	return 0;
}