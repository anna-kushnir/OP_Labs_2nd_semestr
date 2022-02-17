#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct Time
{
	int hour;
	int min;
};

struct Break
{
	Time start;
	Time end;
};

void Input_Breaks(ofstream&);
bool Is_Equal(Break, Break);
bool Check_Breaks_For_Repetitions(Break*, Break, int);