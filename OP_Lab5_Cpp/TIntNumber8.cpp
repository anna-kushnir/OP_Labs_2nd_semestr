#include "Classes.h"
using namespace std;

TIntNumber8::TIntNumber8() : TIntNumber(8) { }
TIntNumber8::TIntNumber8(long long number) : TIntNumber(number, 8) { }
TIntNumber8::TIntNumber8(TIntNumber8& obj) : TIntNumber(obj) { }


TIntNumber8& TIntNumber8::add(TIntNumber& obj)
{
	this->number = convertFromDec(convertToDec(number, 8) + convertToDec(obj.getNum(), 8), 8);
	return *this;
}
int TIntNumber8::compare(TIntNumber& obj)
{
	return this->number < obj.getNum() ? -1 : this->number == obj.getNum() ? 0 : 1;
}
long long TIntNumber8::convertToBase(int base)
{
	return TIntNumber::convertToBase(base);
}