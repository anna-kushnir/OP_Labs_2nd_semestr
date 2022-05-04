/* Визначити клас "Numeral_8", членом якого є вісімкове число. Реалізувати для даного класу декілька
конструкторів, геттери, методи перетворення числа у двійкове, у тому числі і скороченим способом.
Перевантажити оператори: префіксний "++" - для інкрементації вісімкового числа, "+=" - для збільшення
його на вказану величину, "+" - для додавання двох вісімкових чисел. Створити три вісімкових числа
(N1, N2, N3), використовуючи різні конструктори. Інкрементувати число N1, а число N2 збільшити на
вказану величину. Знайти суму змінених чисел N1 та N2 і зберегти її в N3. Перевести отримане значення
N3 у двійковий формат двома способами (звичайним і скороченим). */

#include "Functions.h"
using namespace std;

void outputNums(Numeral_8 N1, Numeral_8 N2, Numeral_8 N3)
{
	cout << "\n       N1 = " << N1.getNum()
		 << "\n       N2 = " << N2.getNum()
		 << "\n       N3 = " << N3.getNum() << "\n";
}

bool isNumeral8(long long num)
{
	while (num) {
		if (num % 10 < 8) {
			num /= 10;
		}
		else {
			return false;
		}
	}
	return true;
}

long long convertToDec(long long num, int base)
{
	long long dec = 0;
	int i = 0;
	while (num) {
		dec += (num % 10) * (long long)pow(base, i++);
		num /= 10;
	}
	return dec;
}

long long convertFromDec(long long dec, int base)
{
	long long num = 0;
	int i = 0;
	while (dec > base - 1) {
		num += (dec % base) * (long long)pow(10, i++);
		dec /= base;
	}
	return num + dec * (long long)pow(10, i);
}