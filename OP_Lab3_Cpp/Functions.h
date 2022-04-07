#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Classes.h"
using namespace std;

Function_Sinus Input_Object();
vector <Function_Sinus> Create_Array();
void Output_Array(vector <Function_Sinus>);
void Output_Sinuses(vector <Function_Sinus>, float);
int Find_Max_Value(vector <Function_Sinus>, float);