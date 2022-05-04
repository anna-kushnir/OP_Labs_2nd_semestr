#include "Functions.h"
using namespace std;

Numeral_8::Numeral_8()
{
	this->number = 0;
}
Numeral_8::Numeral_8(long long number)
{
	this->number = number;
}
Numeral_8::Numeral_8(Numeral_8& obj)
{
	this->number = obj.number;
}

long long Numeral_8::getNum()
{
	return this->number;
}
long long Numeral_8::convertToBinUsual()
{
	long long dec = convertToDec(this->number, 8);
	long long bin = convertFromDec(dec, 2);
	return bin;
}
long long Numeral_8::convertToBinReduced()
{
	long long oct = this->number, bin = 0;
	int i = 0;
	while (oct) {
		bin += convertFromDec(oct % 10, 2) * (long long)pow(1000, i++);
		oct /= 10;
	}
	return bin;
}


Numeral_8& Numeral_8::operator++()
{
	this->number = convertFromDec(convertToDec(this->number, 8) + 1, 8);
	return *this;
}
Numeral_8& Numeral_8::operator+=(long long n)
{
	this->number = convertFromDec(convertToDec(this->number, 8) + convertToDec(n, 8), 8);
	return *this;
}
Numeral_8 Numeral_8::operator+(Numeral_8 obj)
{
	Numeral_8 sum(convertFromDec(convertToDec(this->number, 8) + convertToDec(obj.number, 8), 8));
	return sum;
}