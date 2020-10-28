#pragma once
#include "Node.h"
using namespace std;

class Label {
	Node currentNode;
	Node previousNode;
	int cost;
	bool hasBeenVisited;
	bool isMarked;

public:
	Label(Node, Node, int, bool);
	Label(Node, int, bool);
	Label();
	void setMarked(bool);
	void setCost(int);
	Node getCurrentNode();
};

Label::Label(Node currentNode, Node previousNode, int cost, bool hasBeenVisited) {
	Label::currentNode = currentNode;
	Label::previousNode = previousNode;
	Label::cost = cost;
	Label::hasBeenVisited = hasBeenVisited;
	Label::isMarked = false;
}

Label::Label(Node currentNode, int cost, bool hasBeenVisited) {
	Label::currentNode = currentNode;
	Label::cost = cost;
	Label::hasBeenVisited = hasBeenVisited;
	Label::isMarked = false;
}

Label::Label() {}

void Label::setMarked(bool marked) {
	isMarked = marked;
}

void Label::setCost(int cost) {
	Label::cost = cost;
}

Node Label::getCurrentNode() {
	return currentNode;
}