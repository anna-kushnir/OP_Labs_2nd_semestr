// ��������� ���� "������� sin(ax + b)". �������� ����� ��'���� ������ �����.
// ��������� ������� (�� �����), ��� ������ �������� �������� � �������
// ������������ ����� x.

#include "Functions.h"
#include "Classes.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	vector <Function_Sinus> Array_Of_Objects = Create_Array();
	Output_Array(Array_Of_Objects);
	float x;
	cout << "\n����i�� x: "; cin >> x;
	Output_Sinuses(Array_Of_Objects, x);
	int num_of_max = Find_Max_Value(Array_Of_Objects, x);
	cout << "\n����i���� �������� ������ � ������i� ����i x �� �����i� �i� ������� " << num_of_max + 1 << endl;
	system("pause");
	return 0;
}