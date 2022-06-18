#pragma once
#include "Node.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

// Перевіряє, чи є символ арифметичною операцією.
bool isOperation(string symb);
// Зчитує символи формули з файлу.
vector<string> readFile(ifstream& file);
// Виводить утворений масив символів, зчитаних з файлу.
void outputVector(const vector<string>& vect, ofstream& out);
// Будує дерево-формулу із зчитаного масиву символів.
Node* makeTree(const vector<string>& vect, int& i);
// Здійснює виведення дерева, використовуючи зворотній симетричний обхід (справа наліво).
void outputTree(Node* Tree, int level, ofstream& out);
// Обчислює значення виразу (формули).
double count(Node* Tree);
// Очищує пам'ять, використану деревом.
void clearMemory(Node* Tree);
