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
	cout << "Введiть m (кількість двійкових чисел): "; cin >> m;
	cout << "Введiть n (кількість вісімкових чисел): "; cin >> n;

	cout << "\n---Початок введення двiйкових чисел---\n\n";
	vector<TIntNumber2> binNums = inputBinNums(m);
	cout << "\n---Початок введення вісімкових чисел---\n\n";
	vector<TIntNumber8> octNums = inputOctNums(n);

	cout << "\n---Введені вами дані---\n";
	outputNums(binNums);
	outputNums(octNums);

	TIntNumber2 sumBin = countSum(binNums);
	TIntNumber8 sumOct = countSum(octNums);
	cout << "\n\nСума двійкових чисел: " << sumBin;
	cout << "\nСума вісімкових чисел: " << sumOct;
	TIntNumber2 sumOctInBin = sumOct.convertToBase();
	cout << "\nОтримане значення суми вісімкових чисел у двійковому форматі: " << sumOctInBin << "\n";

	findMin(sumBin, sumOctInBin);

	system("pause");
	return 0;
}