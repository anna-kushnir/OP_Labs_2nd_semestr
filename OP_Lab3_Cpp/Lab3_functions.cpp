// Розробити клас "функція sin(ax + b)". Створити масив об'єктів даного класу.
// Визначити функцію (її номер), яка приймає найбільше значення у введеній
// користувачем точці x.

#include "Functions.h"
#include "Classes.h"
#include <vector>
using namespace std;

vector <Function_Sinus> Create_Array()
{
	char flag = 'Y';
	float A, B;
	vector <Function_Sinus> Array;
	Function_Sinus Element;
	printf("\n--- Початок введення аргументiв функцiї sin(ax + b) ---\n\n");
	while (flag == 'Y' or flag == 'y')
	{
		cout << "Введiть a: "; cin >> A;
		Element.SetA(A);
		cout << "Введiть b: "; cin >> B;
		Element.SetB(B);
		Array.push_back(Element);
		cout << "Чи бажаєте ви продовжити введення? (Y/N) "; cin >> flag;
	}
	return Array;
}

void Output_Array(vector <Function_Sinus> Array)
{
	printf("\n--- Список функцiй з уведеними аргументами ---\n\n");
	for (unsigned int i = 0; i < Array.size(); ++i)
	{
		cout << i + 1 << ": sin(" << Array[i].GetA() << "x + " << Array[i].GetB() << ")\n";
	}
}

void Output_Sinuses(vector <Function_Sinus> Array, float x)
{
	printf("\n--- Список синусiв ---\n");
	for (unsigned int i = 0; i < Array.size(); ++i)
	{
		if (i % 2 == 0) 
			cout << "\n" << setw(2) << i + 1 << ": sin = " << setw(7) << setprecision(4) << Array[i].GetSin(x);
		else
			cout << setw(20) << i + 1 << ": sin = " << setw(7) << setprecision(4) << Array[i].GetSin(x);
	}
	cout << endl;
}

int Find_Max_Value(vector <Function_Sinus> Array, float X)
{
	int i_max = 0;
	for (unsigned int i = 1; i < Array.size(); ++i)
	{
		if (Array[i].GetSin(X) > Array[i_max].GetSin(X))
		{
			i_max = i;
		}
	}
	return i_max;
}