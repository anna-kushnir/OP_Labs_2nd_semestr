#include "Classes.h"
using namespace std;

TIntNumber2::TIntNumber2() : TIntNumber(2) { }
TIntNumber2::TIntNumber2(long long number) : TIntNumber(number, 2) { }
TIntNumber2::TIntNumber2(TIntNumber2& obj) : TIntNumber(obj) { }


TIntNumber2& TIntNumber2::add(TIntNumber& obj)
{
	this->number = convertFromDec(convertToDec(number, 2) + convertToDec(obj.getNum(), 2), 2);
	return *this;
}
int TIntNumber2::compare(TIntNumber& obj)
{
	return this->number < obj.getNum() ? -1 : this->number == obj.getNum() ? 0 : 1;
}
long long TIntNumber2::convertToBase(int base)
{
	return TIntNumber::convertToBase(base);
}