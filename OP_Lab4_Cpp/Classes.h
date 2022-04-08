class Numeral_8
{
	int number;
public:
	Numeral_8();
	Numeral_8(int number);
	Numeral_8(Numeral_8& obj);

	int GetNum();
	Numeral_8& operator++();
	Numeral_8& operator+=(int);
	Numeral_8 operator+(Numeral_8);
};