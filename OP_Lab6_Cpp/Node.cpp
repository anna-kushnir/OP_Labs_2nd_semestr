#include "Node.h"

Node::Node()
{
	this->key = "";
	left = NULL;
	right = NULL;
}

void Node::setKey(string key)
{
	this->key = key;
}
string Node::getKey()
{
	return key;
}
