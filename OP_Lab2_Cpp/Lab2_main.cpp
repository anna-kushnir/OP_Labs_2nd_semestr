//Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця
//перерви. При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
//Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у 
//черзі, якщо на одного клієнта в середньому витрачається 15 хв.

#include "header.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string path = "File.dat";
	ofstream File(path, ios::binary);
	Input_Breaks(File);




	system("pause");
	return 0;
}