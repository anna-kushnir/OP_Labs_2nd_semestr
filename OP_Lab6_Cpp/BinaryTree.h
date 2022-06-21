#pragma once
#include "Node.h"
#include <vector>
#include <fstream>
using namespace std;

class BinaryTree
{
	// ���� ������-������� �� �������� ������ �������.
	static Node* createTree(const vector<string>& symbs, int& index);
	// �������� ������� ��� printTree().
	static void printTree(Node* node, int level, ofstream& out);
	// �������� ������� ��� clearMemory().
	static void clearMemory(Node* node);
	// �������� ������� ��� countValueOfExpression().
	static double count(Node* node);

public:
	Node* Root;

	BinaryTree(const vector<string>& symbs);

	// �������� �������� ������-�������.
	double countValueOfExpression();
	// ������� ��������� ������ � ���� out, �������������� �������� ����������� ����� (������ �����).
	void printTree(ofstream& out);
	// ����� ���'���, ����������� �������.
	void clearMemory();
};
