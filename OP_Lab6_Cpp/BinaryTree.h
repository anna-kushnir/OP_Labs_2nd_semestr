#pragma once
#include "Node.h"
#include <vector>
#include <fstream>
using namespace std;

class BinaryTree
{
	// Будує дерево-формулу із заданого масиву символів.
	static Node* createTree(const vector<string>& symbs, int& index);
	// Допоміжна функція для printTree().
	static void printTree(Node* node, int level, ofstream& out);
	// Допоміжна функція для clearMemory().
	static void clearMemory(Node* node);
	// Допоміжна функція для countValueOfExpression().
	static double count(Node* node);

public:
	Node* Root;

	BinaryTree(const vector<string>& symbs);

	// Обчислює значення дерева-формули.
	double countValueOfExpression();
	// Здійснює виведення дерева у файл out, використовуючи зворотній симетричний обхід (справа наліво).
	void printTree(ofstream& out);
	// Очищує пам'ять, використану деревом.
	void clearMemory();
};
