class Numeral_8
{
	long long number;
public:
	Numeral_8();
	Numeral_8(long long number);
	Numeral_8(Numeral_8& obj);

	long long getNum();
	long long convertToBinUsual();
	long long convertToBinReduced();
	Numeral_8& operator++();
	Numeral_8& operator+=(long long);
	Numeral_8 operator+(Numeral_8);	
};