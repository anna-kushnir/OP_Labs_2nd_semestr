/*Створити клас TIntNumber, який представляє ціле число у будь-якій системі числення і містить методи
для додавання іншого числа, порівняння чисел та переведення числа у вказану систему числення (із заданого
переліку). На основі цього класу створити класи-нащадки TIntNumber2 та TIntNumber8, що представляють
двійкові та вісімкові числа. Створити m двійкових та n вісімкових чисел. Знайти суму двійкових та вісімкових
чисел. Перевести отримане значення суми вісімкових чисел у двійковий формат. Визначити, сума яких чисел менша
(двійкових чи вісімкових).*/

#include "Functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int m, n;
	cout << "Введіть m (кількість двійкових чисел): "; cin >> m;
	cout << "Введіть n (кількість вісімкових чисел): "; cin >> n;

	cout << "\n---Початок введення двійкових чисел---\n\n";
	vector<TIntNumber2> binNums = inputNums<TIntNumber2>(m, 2);
	cout << "\n---Початок введення вісімкових чисел---\n\n";
	vector<TIntNumber8> octNums = inputNums<TIntNumber8>(n, 8);

	cout << "\n---Введені вами дані---\n";
	cout << "\nДвійкові числа: ";
	outputNums<TIntNumber2>(binNums);
	cout << "\nВісімкові числа: ";
	outputNums<TIntNumber8>(octNums);

	TIntNumber2 sumBin = countSum<TIntNumber2>(binNums);
	TIntNumber8 sumOct = countSum<TIntNumber8>(octNums);
	cout << "\n\nСума двійкових чисел: " << sumBin;
	cout << "\nСума вісімкових чисел: " << sumOct;
	TIntNumber2 sumOctInBin = sumOct.convertToBase();
	cout << "\nОтримане значення суми вісімкових чисел у двійковому форматі: " << sumOctInBin << "\n";

	findMin(sumBin, sumOctInBin);

	system("pause");
	return 0;
}