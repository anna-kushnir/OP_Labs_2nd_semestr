#pragma once
#include "Node.h"
#include "BinaryTree.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

// Перевіряє, чи є символ арифметичною операцією.
bool isOperation(string symb);
// Посимвольно зчитує формулу з файлу.
vector<string> readFile(ifstream& file);
// Виводить утворений масив символів, зчитаних з файлу.
void outputVector(const vector<string>& vect, ofstream& out);
