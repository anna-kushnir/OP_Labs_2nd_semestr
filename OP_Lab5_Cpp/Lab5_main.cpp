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
	cout << "����i�� m (������� �������� �����): "; cin >> m;
	cout << "����i�� n (������� �������� �����): "; cin >> n;

	cout << "\n---������� �������� ��i������ �����---\n\n";
	vector<TIntNumber2> binNums = inputBinNums(m);
	cout << "\n---������� �������� �������� �����---\n\n";
	vector<TIntNumber8> octNums = inputOctNums(n);

	cout << "\n---������ ���� ���---\n";
	outputNums(binNums);
	outputNums(octNums);

	TIntNumber2 sumBin = countSum(binNums);
	TIntNumber8 sumOct = countSum(octNums);
	cout << "\n\n���� �������� �����: " << sumBin;
	cout << "\n���� �������� �����: " << sumOct;
	TIntNumber2 sumOctInBin = sumOct.convertToBase();
	cout << "\n�������� �������� ���� �������� ����� � ��������� ������: " << sumOctInBin << "\n";

	findMin(sumBin, sumOctInBin);

	system("pause");
	return 0;
}