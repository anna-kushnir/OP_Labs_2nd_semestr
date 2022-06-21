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
