//Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця
//перерви. При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
//Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у 
//черзі, якщо на одного клієнта в середньому витрачається 15 хв.

#include "header.h"
using namespace std;

void Input_Breaks(ofstream& file)
{
	int n, n_copy, i = 0;
	cout << "Введiть кiлькiсть технiчних перерв у роботi каси: "; cin >> n;
	n_copy = n;
	char ch;
	Break* breaks = new Break[n];
	Break curr_break;
	cout << "--- Початок введення перелiку технiчних перерв ---\n";
	while (i < n) {
		cout << "Введiть час початку перерви (у форматі гг:хх): ";
		cin >> breaks[i].start.hour >> ch >> breaks[i].start.min;
		cout << "Введiть час кінця перерви (у форматі гг:хх): ";
		cin >> breaks[i].end.hour >> ch >> breaks[i].end.min;
		if (!Check_Breaks_For_Repetitions(breaks, breaks[i], i)) {
			file.fill('0');
			file << setw(2) << breaks[i].start.hour << ":" << setw(2) << breaks[i].start.min;
			file << setw(2) << breaks[i].end.hour << ":" << setw(2) << breaks[i].end.min;
		}
		else {
			n_copy--;
		}
		i++;
	}
}

bool Is_Equal(Break A, Break B)
{
	if (A.start.hour == B.start.hour && A.start.min == B.start.min &&
		A.end.hour == B.end.hour && A.end.min == B.end.min) return true;
	else return false;
}

bool Check_Breaks_For_Repetitions(Break* breaks, Break check_break, int k)
{
	for (int i = 0; i < k; ++i) {
		if (Is_Equal(breaks[i], check_break)) return true;
	}
	return false;
}