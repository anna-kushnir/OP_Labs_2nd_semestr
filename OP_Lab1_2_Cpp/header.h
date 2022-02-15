#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void create_first_file(ofstream&);
int delete_2_symb_words(ifstream&, ofstream&);
int add_number_of_del_words(ofstream&, int);
void output_text_of_file(ifstream&);