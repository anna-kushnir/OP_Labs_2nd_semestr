#pragma once
#include "Node.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

bool isOperation(string symb);
vector<string> readFile(ifstream& file);
void outputVector(const vector<string>& vect, ofstream& out);
Node* makeTree(const vector<string>& vect, int& i);
void outputTree(Node* Tree, int level, ofstream& out);
double count(Node* Tree);
void clearMemory(Node* Tree);
