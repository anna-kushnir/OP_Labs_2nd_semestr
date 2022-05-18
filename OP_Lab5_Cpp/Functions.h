#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <Windows.h>
#include "Classes.h"
using namespace std;

class TIntNumber2;
class TIntNumber8;

bool isNumeralBase(long long num, int base);
long long convertToDec(long long num, int base);
long long convertFromDec(long long dec, int base);
void findMin(TIntNumber2& bins, TIntNumber2& octs);

template <class T1>
vector<T1> inputNums(int k, int base)
{
	vector<T1> nums(k);
	for (int i = 0; i < k; ++i) {
		cout << "Введіть число: ";
		int num;
		cin >> num;
		if (isNumeralBase(num, base)) {
			nums[i] = T1(num);
		}
		else {
			cout << "Ви ввели некоректне число! Спробуйте ще раз!\n";
			--i;
		}
	}
	return nums;
}

template <class T2>
void outputNums(const vector<T2>& nums)
{
	for (size_t i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
}

template <class T3>
T3& countSum(vector<T3>& nums)
{
	T3 sum = 0;
	for (size_t i = 0; i < nums.size(); ++i) {
		sum.add(nums[i]);
	}
	return sum;
}