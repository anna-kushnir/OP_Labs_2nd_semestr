#pragma once
#include "Functions.h"
using namespace std;

class TIntNumber
{
protected:
	long long number;
	int base;

	TIntNumber(int base = 10);
	TIntNumber(long long number, int base);
	TIntNumber(TIntNumber& obj);

public:	
	long long getNum();
	int getBase();
	void setNum(long long);
	virtual TIntNumber& add(TIntNumber& obj) = 0;
	virtual int compare(TIntNumber& obj) = 0;
	virtual long long convertToBase(int base) = 0;

	friend ostream& operator<<(ostream& out, const TIntNumber& obj);
	friend istream& operator>>(istream& in, TIntNumber& obj);
};

class TIntNumber2 : public TIntNumber
{
public:
	TIntNumber2();
	TIntNumber2(long long number);
	TIntNumber2(TIntNumber2& obj);

	TIntNumber2& add(TIntNumber& obj) override;
	int compare(TIntNumber& obj) override;
	long long convertToBase(int base = 8) override;
};

class TIntNumber8 : public TIntNumber
{
public:
	TIntNumber8();
	TIntNumber8(long long number);
	TIntNumber8(TIntNumber8& obj);

	TIntNumber8& add(TIntNumber& obj) override;
	int compare(TIntNumber& obj) override;
	long long convertToBase(int base = 2) override;
};