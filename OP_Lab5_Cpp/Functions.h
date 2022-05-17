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

vector<TIntNumber2> inputBinNums(int k);
vector<TIntNumber8> inputOctNums(int k);
void outputNums(const vector<TIntNumber2>& nums); 
void outputNums(const vector<TIntNumber8>& nums);
TIntNumber2& countSum(vector<TIntNumber2>& nums);
TIntNumber8& countSum(vector<TIntNumber8>& nums);

void findMin(TIntNumber2& bins, TIntNumber2& octs);