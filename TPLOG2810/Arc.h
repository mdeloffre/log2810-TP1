#pragma once
#include "Node.h"
#include <string>
using namespace std;

class Arc {
	int distance;
	string startingNode;
	string endingNode;
public:
	void init(string, string, string);
	int getDistance();
	string getStartingNode();
	string getEndingNode();
};

void Arc::init( string start, string end, string dist) {
	distance = stoi(dist);
	startingNode = start;
	endingNode = end;
}

int Arc::getDistance() {
	return distance;
}

string Arc::getStartingNode() {
	return startingNode;
}

string Arc::getEndingNode() {
	return endingNode;
}
