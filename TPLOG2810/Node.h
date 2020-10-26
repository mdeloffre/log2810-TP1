#pragma once
using namespace std;
#include <string>

class Node {
	string id;
	string type;

public:
	void init(string, string);
	string getId();
	string getType();
};

void Node::init(string id, string type) {
	Node::id = id;
	Node::type = type;
}

string Node::getId() {
	return id;
}

string Node::getType() {
	return type;
}
