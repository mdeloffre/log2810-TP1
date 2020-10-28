#pragma once

#include <string>
#include <vector>
#include "Arc.h"
using namespace std;

class Node {
	string id;
	string type;
	vector<Arc> successors;

public:
	Node(string, string);
	Node();
	string getId();
	string getType();
	void addSuccessor(Arc);
	vector<Arc> getSuccessors();
};

Node::Node(string id, string type) {
	Node::id = id;
	Node::type = type;
}

Node::Node() {}

string Node::getId() {
	return id;
}

string Node::getType() {
	return type;
}

void Node::addSuccessor(Arc newArc) {
	successors.push_back(newArc);
}

vector<Arc> Node::getSuccessors() {
	return successors;
}