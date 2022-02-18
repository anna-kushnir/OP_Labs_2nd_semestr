//Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця
//перерви. При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
//Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у 
//черзі, якщо на одного клієнта в середньому витрачається 15 хв.

#include "header.h"
using namespace std;

Period Input_Working_Hours()
{
	Period work;
	char ch;
	cout << "Введiть час початку робочого дня (у форматі гг:хх): ";
	cin >> work.start.hour >> ch >> work.start.min;
	cout << "Введiть час кінця робочого дня (у форматі гг:хх): ";
	cin >> work.end.hour >> ch >> work.end.min;
	cout << endl;
	return work;
}

Period* Input_Breaks(int n)
{
	int i = 0;
	char ch;
	Period* breaks = new Period[n];
	while (i < n) {
		cout << "\nВведiть час початку перерви (у форматі гг:хх): ";
		cin >> breaks[i].start.hour >> ch >> breaks[i].start.min;
		cout << "Введiть час кінця перерви (у форматі гг:хх): ";
		cin >> breaks[i].end.hour >> ch >> breaks[i].end.min;
		i++;
	}
	return breaks;
}

void Output_Breaks_In_File(ofstream& file, Period* breaks, int n)
{
	for (int i = 0; i < n; ++i) {
		if (!Check_Breaks_For_Repetitions(breaks, breaks[i], i)) {
			file.write((char*)&breaks[i], sizeof(Period));
		}
	}
	delete[] breaks;
}

void Output_File_In_Console(ifstream& file)
{
	Period breaks;
	cout << "Перелiк технiчних перерв у роботi каси:\n";
	while (file.read((char*)&breaks, sizeof(Period))) {
		cout.fill('0');
		cout << setw(2) << breaks.start.hour << ":" << setw(2) << breaks.start.min << " - "
			<< setw(2) << breaks.end.hour << ":" << setw(2) << breaks.end.min << endl;
	}
}

bool Is_Equal(Period A, Period B)
{
	if (A.start.hour == B.start.hour && A.start.min == B.start.min &&
		A.end.hour == B.end.hour && A.end.min == B.end.min) return true;
	else return false;
}

bool Check_Breaks_For_Repetitions(Period* breaks, Period check_break, int k)
{
	for (int i = 0; i < k; ++i) {
		if (Is_Equal(breaks[i], check_break)) return true;
	}
	return false;
}

int Count_Duration(Period period)
{
	return (period.end.hour * 60 + period.end.min) - (period.start.hour * 60 + period.start.min);
}

bool Check_For_Serving_Customers(ifstream& file, Period work, int num_of_cust, int time_for_one_cust)
{
	int working_day_duration = Count_Duration(work);
	Period breaks;
	int break_time = 0;
	cout << "\nТривалiсть перерв:\n";
	while (file.read((char*)&breaks, sizeof(Period))) {
		break_time += Count_Duration(breaks);
		cout << break_time << endl;
	}
	int work_time = working_day_duration - break_time;
	int time_for_customers = time_for_one_cust * num_of_cust;
	if (work_time >= time_for_customers) return true;
	else return false;
}