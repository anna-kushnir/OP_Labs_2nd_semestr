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
			continue;
		}
		if (st == "(" || st == ")") {
			mass.push_back(st);
			k++;
			continue;
		}
		if (isOperation(st)) {
			mass.push_back(st);
			k++;
			continue;
		}
		if (isdigit(expr[k])) {
			m = k + 1;
			while (m < expr.length()) {
				if (isdigit(expr[m]) || expr[m] == ',') {
					m++;
				}
				else break;
			}
			string num = expr.substr(k, m - k);
			mass.push_back(num);
			k = m;
			continue;
		}
		return { 0 };
	}
	return mass;
}

void outputVector(const vector<string>& vect)
{
	int i = 0;
	while (i < vect.size()) {
		cout << vect[i] << " ";
		i++;
	}
	cout << "\n\n";
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
