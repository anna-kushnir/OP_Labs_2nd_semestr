#include "BinaryTree.h"
#include "Functions.h"
using namespace std;

BinaryTree::BinaryTree(const vector<string>& symbs)
{
	int index = 0;
	Root = createTree(symbs, index);
}
Node* BinaryTree::createTree(const vector<string>& symbs, int& index)
{
	Node* node = new Node();
	while (index < symbs.size()) {
		if (symbs[index] == ")") {
			return node;
		}
		if (symbs[index] == "(") {
			node->left = createTree(symbs, ++index);
			index++;
		}
		if (isdigit(symbs[index][0])) {
			node->setKey(symbs[index]);
			return node;
		}
		if (isOperation(symbs[index])) {
			node->setKey(symbs[index]);
			node->right = createTree(symbs, ++index);
			index++;
		}
	}
	return node;
}

void BinaryTree::printTree(Node* node, int level, ofstream& out)
{
	if (node != NULL) {
		printTree(node->right, level + 1, out);
		for (int i = 0; i < level; ++i) {
			out << "\t";
		}
		out << "  " << node->getKey() << "\n";
		printTree(node->left, level + 1, out);
	}
}
void BinaryTree::printTree(ofstream& out)
{
	printTree(Root, 0, out);
}

void BinaryTree::clearMemory(Node* node)
{
	if (node->left == NULL && node->right == NULL) {
		free(node);
		return;
	}
	if (node->left != NULL) {
		clearMemory(node->left);
	}
	if (node->right != NULL) {
		clearMemory(node->right);
	}
}
void BinaryTree::clearMemory()
{
	clearMemory(Root);
}

double BinaryTree::count(Node* node)
{
	if (isdigit(node->getKey()[0])) {
		return stof(node->getKey());
	}
	switch (node->getKey()[0]) {
	case '+':
		return count(node->left) + count(node->right);
	case '-':
		return count(node->left) - count(node->right);
	case '*':
		return count(node->left) * count(node->right);
	case '/':
		return count(node->left) / count(node->right);
	}
}
double BinaryTree::countValueOfExpression()
{
	return count(Root);
}
