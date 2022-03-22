//Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця перерви. 
//При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
//Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у черзі, 
//якщо на одного клієнта в середньому витрачається 15 хв.

#include "header.h"
using namespace std;

//Виведення списку перерв із файлу у консоль
void Output_File_In_Console(ifstream& file)
{
	Period breaks;                     // змінна для збереження даних про перерву
	cout << "\nПерелiк технiчних перерв у роботi каси:\n\n";
	while (file.read((char*)&breaks, sizeof(Period))) {
		cout.fill('0');
		cout << setw(2) << breaks.start.hour << ":" << setw(2) << breaks.start.min << " - "
			<< setw(2) << breaks.end.hour << ":" << setw(2) << breaks.end.min << endl;
	}
}

//Введення користувачем часу початку та кінця робочого дня та їх збереження в об'єкті work 
//структури Period
Period Input_Working_Hours()
{
	Period work;                        // робочий час
	char ch;                            // змінна для зчитування знаку ":"
	cout << "Введiть час початку робочого дня (у форматі гг:хх): ";
	cin >> work.start.hour >> ch >> work.start.min;
	cout << "Введiть час кінця робочого дня (у форматі гг:хх): ";
	cin >> work.end.hour >> ch >> work.end.min;
	return work;
}

//Введення користувачем n перерв (без перевірки на повторення і тд) та їх збереження у масиві 
// об'єктів breaks[] структури Period
Period* Input_Breaks(int n)
{
	char ch;                            // змінна для зчитування знаку ":"
	Period* breaks = new Period[n];     // масив перерв
	cout << "Будь ласка, вводьте перерви у порядку зростання їх початку!\n" <<
		"\n--- Початок введення перелiку технiчних перерв--- \n";
	for (int i = 0; i < n; ++i) {
		cout << "\nВведiть час початку перерви (у форматі гг:хх): ";
		cin >> breaks[i].start.hour >> ch >> breaks[i].start.min;
		cout << "Введiть час кінця перерви (у форматі гг:хх): ";
		cin >> breaks[i].end.hour >> ch >> breaks[i].end.min;
	}
	return breaks;
}

//Виведення перерв із масиву у файл з їх повною перевіркою
void Output_Breaks_In_File(ofstream& file, Period* breaks, Period work, int n)
{
	for (int i = 0; i < n; ++i) {
		if (Check_Break(breaks, breaks[i], work, i)) {
			file.write((char*)&breaks[i], sizeof(Period));
		}
	}
	delete[] breaks;
}

//Перевірка перерв на накладання та повторення, також чи не виходять вони за межі часу робочого дня
bool Check_Break(Period* breaks, Period& a_break, Period work, int k)
{
	
	if (!Break_Is_In_Work_Time(a_break, work))
		return false;
	for (int i = 0; i < k; ++i) {
		if (Breaks_Is_Equal(breaks[i], a_break))
			return false;
		if (Breaks_Is_Overlap(breaks[i], a_break))
			return false;
	}
	return true;
}

//Перевірка, чи перерва не виходить за межі робочого дня, та зсунення початку або кінця перерви, якщо 
//її початок або кінець відповідно виходить за його межі
bool Break_Is_In_Work_Time(Period& breaks, Period work)
{
	if (breaks.end.hour < work.start.hour ||
		breaks.end.hour == work.start.hour && breaks.end.min <= work.start.min)
		return false;
	if (breaks.start.hour > work.end.hour ||
		breaks.start.hour == work.end.hour && breaks.start.min >= work.end.min)
		return false;
	if (breaks.start.hour < work.start.hour ||
		breaks.start.hour == work.start.hour && breaks.start.min < work.start.min)
	{	
		breaks.start.hour = work.start.hour;
		breaks.start.min = work.start.min;
	}
	if (breaks.end.hour > work.end.hour ||
		breaks.end.hour == work.end.hour && breaks.end.min > work.end.min)
	{	
		breaks.end.hour = work.end.hour;
		breaks.end.min = work.end.min;
	}
	return true;
}

//Перевірка, чи перерви повністю ідентичні
bool Breaks_Is_Equal(Period A, Period B)
{
	if (A.start.hour == B.start.hour && A.start.min == B.start.min &&
		A.end.hour == B.end.hour && A.end.min == B.end.min) return true;
	else return false;
}

//Перевірка, чи перерви накладаються одна на одну
bool Breaks_Is_Overlap(Period A, Period& B)
{
	if ((B.start.hour > A.start.hour || B.start.hour == A.start.hour && B.start.min >= A.start.min) 
		&& B.end.hour < A.end.hour || B.end.hour == A.end.hour && B.end.min <= A.end.min)
		return true;
	if ((A.start.hour < B.start.hour || A.start.hour == B.start.hour && A.start.min <= B.start.min)
		&& (A.end.hour > B.start.hour || A.end.hour == B.start.hour && A.end.min > B.start.min))
	{
		B.start.hour = A.end.hour;
		B.start.min = A.end.min;
	}
	else if ((A.end.hour > B.end.hour || A.end.hour == B.end.hour && A.end.min >= B.end.min)
		&& (A.start.hour > B.start.hour || A.start.hour == B.start.hour && A.start.min > B.start.min))
	{
		B.end.hour = A.start.hour;
		B.end.min = A.start.min;
	}
	return false;
}

//Обчислення тривалості певного періоду часу
int Count_Duration(Period period)
{
	return (period.end.hour * 60 + period.end.min) - (period.start.hour * 60 + period.start.min);
}

//Перевірка, чи встигне касир обслужити num_of_cust клієнтів за робочий день
bool Check_For_Serving_Customers(ifstream& file, Period work, int num_of_cust, int time_for_one_cust)
{
	int working_day_duration = Count_Duration(work);          // загальна тривалість робочого дня
	Period breaks;                                            // змінна для збереження даних про перерву
	int break_time = 0;                                       // сумарна тривалість перерв
	while (file.read((char*)&breaks, sizeof(Period))) {
		break_time += Count_Duration(breaks);
	}
	int work_time = working_day_duration - break_time;        // робочий час (з урахуванням перерв)
	int time_for_customers = time_for_one_cust * num_of_cust; // загальний час, необхідний на клієнтів
	cout << "\nЗагальна тривалість робочого дня: " << working_day_duration << " хв\n";
	cout << "Сумарна тривалiсть перерв: " << break_time << " хв\n";
	cout << "Робочий час (з урахуванням перерв): " << work_time << " хв\n";
	if (work_time >= time_for_customers) return true;
	else return false;
}