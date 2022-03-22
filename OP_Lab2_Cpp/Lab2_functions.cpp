//Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця
//перерви. При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
//Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у 
//черзі, якщо на одного клієнта в середньому витрачається 15 хв.

#include "header.h"
using namespace std;

//Введення користувачем часу початку та кінця робочого дня та їх збереження 
//в об'єкті work структури Period
Period Input_Working_Hours()
{
	Period work;                        // робочий час
	char ch;                            // змінна для зчитування знаку ":"
	cout << "Введiть час початку робочого дня (у форматі гг:хх): ";
	cin >> work.start.hour >> ch >> work.start.min;
	cout << "Введiть час кінця робочого дня (у форматі гг:хх): ";
	cin >> work.end.hour >> ch >> work.end.min;
	cout << endl;
	return work;
}

//Введення користувачем n перерв (без перевірки на повторення і тд) та їх збереження
//у масиві об'єктів breaks[] структури Period
Period* Input_Breaks(int n)
{
	int i = 0;                          // лічильник
	char ch;                            // змінна для зчитування знаку ":"
	Period* breaks = new Period[n];     // масив перерв
	while (i < n) {
		cout << "\nВведiть час початку перерви (у форматі гг:хх): ";
		cin >> breaks[i].start.hour >> ch >> breaks[i].start.min;
		cout << "Введiть час кінця перерви (у форматі гг:хх): ";
		cin >> breaks[i].end.hour >> ch >> breaks[i].end.min;
		i++;
	}
	return breaks;
}

//Виведення списку перерв із файлу у консоль
void Output_File_In_Console(ifstream& file)
{
	Period breaks;                     // змінна для збереження даних про перерву
	cout << "Перелiк технiчних перерв у роботi каси:\n";
	while (file.read((char*)&breaks, sizeof(Period))) {
		cout.fill('0');
		cout << setw(2) << breaks.start.hour << ":" << setw(2) << breaks.start.min << " - "
			<< setw(2) << breaks.end.hour << ":" << setw(2) << breaks.end.min << endl;
	}
}

//Виведення перерв із масиву у файл з їх перевіркою на повторення та 
//чи не виходять вони за межі робочого дня
void Output_Breaks_In_File(ofstream& file, Period* breaks, Period work, int n)
{
	for (int i = 0; i < n; ++i) {
		if (Check_Breaks(breaks, breaks[i], work, i)) {
			file.write((char*)&breaks[i], sizeof(Period));
		}
	}
	delete[] breaks;
}

//Перевірка перерв на повторення та чи не виходять вони за межі часу робочого дня
bool Check_Breaks(Period* breaks, Period& check_break, Period work, int k)
{
	
	if (!Break_Is_In_Work_Time(check_break, work)) 
		return false;
	for (int i = 0; i < k; ++i) {
		if (Breaks_Is_Equal(breaks[i], check_break)) 
			return false;
	}
	return true;
}

//Перевірка, чи перерва не виходить за межі робочого дня, та зсунення перерви, якщо лише її початок 
//або кінець виходить за його межі
bool Break_Is_In_Work_Time(Period& check_break, Period work)
{
	if (check_break.end.hour < work.start.hour ||
		check_break.end.hour == work.start.hour && check_break.end.min <= work.start.min)
		return false;
	if (check_break.start.hour > work.end.hour ||
		check_break.start.hour == work.end.hour && check_break.start.min >= work.end.min)
		return false;
	if (check_break.start.hour < work.start.hour ||
		check_break.start.hour == work.start.hour && check_break.start.min < work.start.min)
	{	check_break.start.hour = work.start.hour;
		check_break.start.min = work.start.min;
	}
	if (check_break.end.hour > work.end.hour ||
		check_break.end.hour == work.end.hour && check_break.end.min > work.end.min)
	{
		check_break.end.hour = work.end.hour;
		check_break.end.min = work.end.min;
	}
	return true;
}

//Перевірка, чи перерви накладаються одна на одну
bool Breaks_Is_Equal(Period A, Period B)
{
	if (A.start.hour == B.start.hour && A.start.min == B.start.min &&
		A.end.hour == B.end.hour && A.end.min == B.end.min) return true;
	else return false;
}

//Обчислення тривалості певного періоду часу
int Count_Duration(Period period)
{
	return (period.end.hour * 60 + period.end.min) - (period.start.hour * 60 + period.start.min);
}

//Перевірка, чи встигне касир обслужити num_of_cust клієнтів за робочий день
bool Check_For_Serving_Customers(ifstream& file, Period work, int num_of_cust, int time_for_one_cust)
{
	int working_day_duration = Count_Duration(work);        // загальна тривалість робочого дня
	Period breaks;                                          // змінна для збереження даних про перерву
	int break_time = 0;                                     // сумарна тривалість перерв
	while (file.read((char*)&breaks, sizeof(Period))) {
		break_time += Count_Duration(breaks);
	}
	cout << "\nСумарна тривалiсть перерв:\n"; 
	cout << break_time << endl;
	int work_time = working_day_duration - break_time;        // робочий час (з урахуванням перерв)
	int time_for_customers = time_for_one_cust * num_of_cust; //загальний час, необхідний на клієнтів
	if (work_time >= time_for_customers) return true;
	else return false;
}