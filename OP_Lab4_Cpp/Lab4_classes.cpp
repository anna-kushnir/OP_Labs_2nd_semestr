#include "Classes.h"

Numeral_8::Numeral_8()
{
	this->number = 0;
}
Numeral_8::Numeral_8(int number)
{
	this->number = number;
}
Numeral_8::Numeral_8(Numeral_8& obj)
{
	this->number = obj.number;
}
int Numeral_8::GetNum()
{
	return this->number;
}
Numeral_8& Numeral_8::operator++()
{
	this->number = this->number + 1;
	return *this;
}
Numeral_8& Numeral_8::operator+=(int n)
{
	this->number = this->number + n;
	return *this;
}
Numeral_8 Numeral_8::operator+(Numeral_8 obj)
{
	Numeral_8 sum(this->number + obj.number);
	return sum;
}