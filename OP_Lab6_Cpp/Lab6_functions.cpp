#include "Functions.h"

using namespace std;

bool isOperation(string symb)
{
	if (symb == "+" || symb == "-" || symb == "*" || symb == "/")
		return true;
	return false;
}

vector<string> readFile(ifstream& file)
{
	vector<string> mass;
	string expr;
	getline(file, expr);
	int k = 0, m;
	while (k < expr.length()) {
		string st = expr.substr(k, 1);
		if (st == " ") {
			k++;
		}
		else if (st == "(" || st == ")" || isOperation(st)) {
			mass.push_back(st);
			k++;
		}
		else if (isdigit(expr[k])) {
			m = k + 1;
			while (m < expr.length()) {
				if (isdigit(expr[m]) || expr[m] == '.') {
					m++;
				}
				else break;
			}
			string num = expr.substr(k, m - k);
			mass.push_back(num);
			k = m;
		}
		else return {""};
	}
	return mass;
}

void outputVector(const vector<string>& vect, ofstream& out)
{
	for (int i = 0; i < vect.size() - 1; ++i) {
		out << vect[i] << " ";
	}
	out << vect[vect.size() - 1];
}

Node* makeTree(const vector<string>& vect, int& i)
{
	Node* Tree = new Node;
	while (i < vect.size()) {
		if (vect[i] == ")") {
			return Tree;
		}
		if (vect[i] == "(") {
			Tree->left = makeTree(vect, ++i);
			i++;
		}
		if (isdigit(vect[i][0])) {
			Tree->setKey(vect[i]);
			return Tree;
		}
		if (isOperation(vect[i])) {
			Tree->setKey(vect[i]);
			Tree->right = makeTree(vect, ++i);
			i++;
		}
	}
	return Tree;
}

void outputTree(Node* Tree, int level, ofstream& out)
{
	if (Tree != NULL) {
		outputTree(Tree->right, level + 1, out);
		for (int i = 0; i < level; ++i) {
			out << "         ";
		}
		out << "  " << Tree->getKey() << "\n";
		outputTree(Tree->left, level + 1, out);
	}
}

double count(Node* Tree)
{
	if (isdigit(Tree->getKey()[0])) {
		return stof(Tree->getKey());
	}
	switch (Tree->getKey()[0]) {
	case '+':
		return count(Tree->left) + count(Tree->right);
	case '-':
		return count(Tree->left) - count(Tree->right);
	case '*':
		return count(Tree->left) * count(Tree->right);
	case '/':
		return count(Tree->left) / count(Tree->right);
	}
}

void clearMemory(Node* Tree)
{
	if (Tree != NULL) {
		clearMemory(Tree->left);
		clearMemory(Tree->right);
		free(Tree);
	}
}
