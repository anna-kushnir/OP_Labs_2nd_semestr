// Розробити клас "функція sin(ax + b)". Створити масив об'єктів даного класу.
// Визначити функцію (її номер), яка приймає найбільше значення у введеній
// користувачем точці x.

#include "Functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	vector <Function_Sinus> Array_Of_Objects = Create_Array();
	Output_Array(Array_Of_Objects);
	float x;
	cout << "\nВведiть x: "; cin >> x;
	Output_Sinuses(Array_Of_Objects, x);
	int num_of_max = Find_Max_Value(Array_Of_Objects, x);
	cout << "\nНайбiльше значення синуса у введенiй точцi x має функцiя пiд номером " << num_of_max + 1 << endl;
	system("pause");
	return 0;
}