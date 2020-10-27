#pragma once

#include <string>
using namespace std;

class Arc {
	int distance;
	string startingNode;
	string endingNode;
public:
	Arc(string, string, string);
	int getDistance();
	string getStartingNode();
	string getEndingNode();
};

Arc::Arc(string start, string end, string dist) {
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
