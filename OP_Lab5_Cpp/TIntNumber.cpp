#include "Classes.h"
using namespace std;

TIntNumber::TIntNumber(int base) 
{
	this->number = 0;
	this->base = base;
}
TIntNumber::TIntNumber(long long number, int base)
{
	this->number = number;
	this->base = base;
}
TIntNumber::TIntNumber(TIntNumber& obj)
{
	this->number = obj.number;
	this->base = obj.base;
}

long long TIntNumber::getNum()
{
	return this->number;
}
int TIntNumber::getBase()
{
	return this->base;
}

void TIntNumber::setNum(long long number)
{
	this->number = number;
}

long long TIntNumber::convertToBase(int base)
{
	if (this->base == 10) {
		return convertFromDec(this->number, base);
	}
	else if (base == 10) {
		return convertToDec(this->number, this->base);
	}
	else {
		return convertFromDec(convertToDec(this->number, this->base), base);
	}
}

ostream& operator<<(ostream& out, const TIntNumber& obj)
{
	out << obj.number;
	return out;
}
istream& operator>>(istream& in, TIntNumber& obj)
{
	in >> obj.number;
	return in;
}