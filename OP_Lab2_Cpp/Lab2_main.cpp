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
	ofstream FileOut(path, ios::binary);
	Period working_hours = Input_Working_Hours();
	cout << endl;
	int num;
	cout << "Введiть кiлькiсть технiчних перерв у роботi каси: "; cin >> num;
	cout << "\n--- Початок введення перелiку технiчних перерв ---\n";
	Output_Breaks_In_File(FileOut, Input_Breaks(num), working_hours, num);
	FileOut.close();

	cout << endl;
	int N;                    // кількість клієнтів, що стоять у черзі
	int time_for_one_customer = 15;
	cout << "\nВведiть кiлькiсть клiєнтiв, що стоять у черзi: "; cin >> N;

	ifstream FileIn(path, ios::binary);
	if (Check_For_Serving_Customers(FileIn, working_hours, N, time_for_one_customer)) {
		cout << "\nКасир встигне обслужити " << N << " клiєнтiв за робочий день\n";
	}
	else {
		cout << "\nКасир НЕ встигне обслужити " << N << " клiєнтiв за робочий день\n";
	}
	FileIn.clear();
	FileIn.seekg(0, ios::beg);

	Output_File_In_Console(FileIn);
	FileIn.close();

	system("pause");
	return 0;
}