#pragma once

class Function_Sinus
{
	float a, b;
public:
	Function_Sinus();
	Function_Sinus(float, float);
	void SetA(float);
	void SetB(float);
	float GetA();
	float GetB();
	float GetSin(float);
};