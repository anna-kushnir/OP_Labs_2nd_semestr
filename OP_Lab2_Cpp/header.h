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
void Output_File_In_Console(ifstream&);
void Output_Breaks_In_File(ofstream&, Period*, Period, int);
bool Check_Breaks(Period*, Period&, Period, int);
bool Break_Is_In_Work_Time(Period&, Period);
bool Breaks_Is_Equal(Period, Period);
void Breaks_Is_Overlap(Period, Period&);
int Count_Duration(Period);
bool Check_For_Serving_Customers(ifstream&, Period, int, int);
