#include "Classes.h"
#include <math.h>

Function_Sinus::Function_Sinus()
{
	this->a = this->b = 0;
}
Function_Sinus::Function_Sinus(float a, float b)
{
	this->a = a;
	this->b = b;
}
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
	return (float)sin(this->a * x + this->b);
}