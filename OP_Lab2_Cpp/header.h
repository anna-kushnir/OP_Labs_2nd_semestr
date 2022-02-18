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

struct Period
{
	Time start;
	Time end;
};

Period Input_Working_Hours(); 
Period* Input_Breaks(int);
void Output_Breaks_In_File(ofstream&, Period*, int);
void Output_File_In_Console(ifstream&);
bool Is_Equal(Period, Period);
bool Check_Breaks_For_Repetitions(Period*, Period, int);
int Count_Duration(Period);
bool Check_For_Serving_Customers(ifstream&, Period, int, int);
