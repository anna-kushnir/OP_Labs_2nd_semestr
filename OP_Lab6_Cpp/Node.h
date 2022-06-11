#pragma once
#include <string>
using namespace std;

class Node
{
	string key;

public:
	Node();

	void setKey(string key);
	string getKey();

	Node* left;
	Node* right;
};
