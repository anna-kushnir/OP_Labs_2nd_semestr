#include "Functions.h"
using namespace std;

bool isNumeralBase(long long num, int base)
{
	while (num) {
		if (num % 10 < base) {
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

void findMin(TIntNumber2& bins, TIntNumber2& octs)
{
	int flag = bins.compare(octs);
	if (flag < 0) {
		cout << "\nСума двійкових чисел менша, ніж вісімкових\n";
	}
	else if (flag == 0) {
		cout << "\nСуми двійкових та вісімкових чисел рівні\n";
	}
	else {
		cout << "\nСума вісімкових чисел менша, ніж двійкових\n";
	}
}