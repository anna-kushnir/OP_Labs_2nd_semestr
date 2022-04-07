#include "Classes.h"
#include <math.h>

void Function_Sinus::SetA(float a)
{
	this->a = a;
}
void Function_Sinus::SetB(float b)
{
	this->b = b;
}
float Function_Sinus::GetA()
{
	return this->a;
}
float Function_Sinus::GetB()
{
	return this->b;
}
float Function_Sinus::GetSin(float x)
{
	return sin(this->a * x + this->b);
}