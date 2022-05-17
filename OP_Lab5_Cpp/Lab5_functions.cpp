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

vector<TIntNumber2> inputBinNums(int k)
{
	vector<TIntNumber2> nums(k);
	for (int i = 0; i < k; ++i) {
		cout << "Введіть двійкове число: ";
		int num;
		cin >> num;
		if (isNumeralBase(num, 2)) {
			nums[i] = TIntNumber2(num);
		}
		else {
			cout << "Ви ввели некоректне число! Спробуйте ще раз!\n";
			i--;
		}
	}
	return nums;
}
vector<TIntNumber8> inputOctNums(int k)
{
	vector<TIntNumber8> nums(k);
	for (int i = 0; i < k; ++i) {
		cout << "Введіть вісімкове число: ";
		int num;
		cin >> num;
		if (isNumeralBase(num, 8)) {
			nums[i] = TIntNumber8(num);
		}
		else {
			cout << "Ви ввели некоректне число! Спробуйте ще раз!\n";
			i--;
		}
	}
	return nums;
}

void outputNums(const vector<TIntNumber2>& nums)
{
	cout << "\nДвійкові числа: "; 
	for (size_t i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
}
void outputNums(const vector<TIntNumber8>& nums)
{
	cout << "\nВісімкові числа: ";
	for (size_t i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
}

TIntNumber2& countSum(vector<TIntNumber2>& nums)
{
	TIntNumber2 sum;
	for (size_t i = 0; i < nums.size(); ++i) {
		sum.add(nums[i]);
	}
	return sum;
}
TIntNumber8& countSum(vector<TIntNumber8>& nums)
{
	TIntNumber8 sum;
	for (size_t i = 0; i < nums.size(); ++i) {
		sum.add(nums[i]);
	}
	return sum;
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