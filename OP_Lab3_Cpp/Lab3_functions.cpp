// Розробити клас "функція sin(ax + b)". Створити масив об'єктів даного класу.
// Визначити функцію (її номер), яка приймає найбільше значення у введеній
// користувачем точці x.

#include "Functions.h"
using namespace std;

// Функція для введення полів об'єкту класу Function_Sinus.
Function_Sinus Input_Object()
{
	float A, B;
	Function_Sinus Object;
	cout << "Введiть a: "; cin >> A;
	Object.SetA(A);
	cout << "Введiть b: "; cin >> B;
	Object.SetB(B);
	return Object;
}

// Функція для створення масиву (вектору) об'єктів класу Function_Sinus.
vector <Function_Sinus> Create_Array()
{
	char flag = 'Y';
	vector <Function_Sinus> Array;
	cout << "\n--- Початок введення аргументiв функцiї sin(ax + b) ---\n\n";
	while (flag == 'Y' || flag == 'y')
	{
		Function_Sinus Element = Input_Object();
		Array.push_back(Element);
		cout << "Чи бажаєте ви продовжити введення? (Y/N) "; cin >> flag;
	}
	return Array;
}

// Функція для виведення списку синусів за прикладом "sin(ax + b)" 
// (замість a та b - відповідні поля об'єкту масиву Array).
void Output_Array(vector <Function_Sinus> Array)
{
	printf("\n--- Список функцiй з уведеними аргументами ---\n\n");
	for (unsigned int i = 0; i < Array.size(); ++i)
	{
		cout << setw(2) << i + 1 << ": sin(" << Array[i].GetA() << "x + " << Array[i].GetB() << ")\n";
	}
}

// Функція для виведення значень синусів у заданій точці x.
void Output_Sinuses(vector <Function_Sinus> Array, float x)
{
	printf("\n--- Список значень синусiв у заданій точці ---\n");
	for (unsigned int i = 0; i < Array.size(); ++i)
	{
		if (i % 2 == 0) 
			cout << "\n" << setw(2) << i + 1 << ": sin = " << setw(7) << setprecision(4) << Array[i].GetSin(x);
		else
			cout << setw(20) << i + 1 << ": sin = " << setw(7) << setprecision(4) << Array[i].GetSin(x);
	}
	cout << endl;
}

// Функція для пошуку найбільшого значення синусу у заданій точці x.
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