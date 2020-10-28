#pragma once
#include "Arc.h"
#include "Node.h"
#include "Label.h"
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

class Graph {
	vector<Node> nodes;
	vector<Arc> arcs;
	vector<Label> labels;
	Vehicle vehicle;

public:
	Graph();
	void display_graph();
	void readFromFile(string);
	vector<string> split(string, char);
	Node getNodeById(string id);
	int shortestPath(string, string, Vehicle);
	void extractSubGraph(string, string);
	bool nodeExists(string);
	Label findLabel(Node);
	int getIndex(Label);
};

Graph::Graph() {}

void Graph::display_graph() {
	//Create a list with sorted nodes and their neighbors for the display
	vector<vector<Node>> sortedNodes;
	vector<Node> current;
	cout << "Graphe choisi : " << endl;
	if (arcs.empty()) {
		cout << "Pas d'arcs dans le graphe !" << endl;
	}
	else {
		
		Node compareNode = Graph::getNodeById(arcs[0].getStartingNode());
		
		cout << endl << "(" << compareNode.getId() << ", " << compareNode.getType() << ", (" << arcs[0].getEndingNode();
		compareNode.addSuccessor(arcs[0]);

		//current.push_back(Graph::getNodeById(arcs[0].getEndingNode()));
		for (size_t i = 1; i < arcs.size(); i++) {
			Node currentNode = Graph::getNodeById(arcs[i].getStartingNode());
			//cout << "Ici, on compare le node " << currentNode.getId() << " avec le node " << compareNode.getId() << endl;
			if (currentNode.getId().compare(compareNode.getId()) == 0) {
				cout << ", " << arcs[i].getEndingNode();
				compareNode.addSuccessor(arcs[i]);
			}

			else {
				cout << "))" << endl;

				compareNode = currentNode;
				//cout << "Nouveau node de comparaison : " << compareNode.getId() << endl;

				cout << "(" << compareNode.getId() << ", " << compareNode.getType() << ", (" << arcs[i].getEndingNode();
				compareNode.addSuccessor(arcs[i]);
			}

		}

		cout << ")";
	}
	cout << ")" << endl;
}

void Graph::readFromFile(string filename) {

	fstream file;
	file.open(filename, ios::in);
	vector<string> current;
	if (file.is_open()) {
		string line;
		int lineNumber = 0;
		while (getline(file, line)) {
			//Split the line at each ';' character
			vector<string> tab = split(line, ';');

			for (size_t i = 0; i < tab.size(); i++) {
				//And then split each value to get each node's id and type
				current = split(tab[i], ',');

				//Nodes are on the first line
				if (lineNumber == 0) {
					string type = current[1];
					if (type.compare("rien") == 0) type = "null";
					Node node(current[0], type);
					nodes.push_back(node);
				}

				//Arcs are defined on the second line
				if (lineNumber == 1) {
					Arc arc(current[0], current[1], current[2]);
					arcs.push_back(arc);
				}
			}
			lineNumber++;
		}
		file.close();
	}

	/* This is just a raw display of all the data */
	
	/*for (size_t i = 0; i < nodes.size(); i++) {
		cout << nodes[i].getId() << ":" << nodes[i].getType() << endl;
	}
	for (size_t i = 0; i < arcs.size(); i++) {
		cout << arcs[i].getStartingNode() << " - " << arcs[i].getEndingNode() << endl;
	}*/
}

vector<string> Graph::split(string toSplit, char delimeter) {
	stringstream ss(toSplit);
	string item;
	vector<string> splittedStrings;
	while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}

Node Graph::getNodeById(string id) {
	Node node = nodes[0];
	//cout << "Entering getNodeById() function with argument " << id << endl;
	for (size_t i = 0; i < nodes.size(); i++) {
		if (nodes[i].getId().compare(id) == 0) {
			//cout << "Found the node ! It's " << nodes[i].getId() << endl;
			return nodes[i];
			
		}
	}
	return node;
}

int Graph::shortestPath(string start, string end, Vehicle usedVehicle) {
	vehicle = usedVehicle;

	Node startingNode = getNodeById(start);
	Node endingNode = getNodeById(end);
	
	Label startingLabel(startingNode, 0, true);
	labels.push_back(startingLabel);

	vector<Arc> predecessorArcs;
	int remainingAutonomy = vehicle.getAutonomie();
	bool finished = false;
	
	Label currentLabel = startingLabel;
	Label nextLabel;
	int currentIndex, currentDistance;
	int nextIndex;
	int totalDistance = 0;

	for (size_t i = 0; i < nodes.size(); i++) {
		if (nodes[i].getId().compare(start) != 0) {
			Label currentLabel(nodes[i], numeric_limits<int>::max(), false);
			labels.push_back(currentLabel);
		}
	}

	while (!finished) {

		currentLabel.setMarked(true);
		int bestCost = numeric_limits<int>::max();

		if (currentLabel.getCurrentNode().getId().compare(end) == 0) {
			finished = true;
		}
		vector<Arc> successors = currentLabel.getCurrentNode().getSuccessors();
		for (size_t i = 0; i < successors.size(); i++) {

			Label currentSuccessor = findLabel(getNodeById(successors[i].getEndingNode()));
			//The label for the node we're currently visiting
			currentIndex = getIndex(currentSuccessor);
			//The distance between it and the previous node
			currentDistance = successors[i].getDistance();

			labels[currentIndex].setCost(totalDistance + currentDistance);
			cout << "Le cout du label correspondant au node " << currentLabel.getCurrentNode().getId() << " est " << currentDistance + totalDistance;
			
			if ((totalDistance + currentDistance < bestCost) && (remainingAutonomy > currentDistance)) {
				bestCost = totalDistance + currentDistance;				
			}

		}

		
	}
	
	return remainingAutonomy;
}

void Graph::extractSubGraph(string nodeID, string vehicleType) {

}

bool Graph::nodeExists(string id) {
	bool retValue = false;
	for (size_t i = 0; i < nodes.size(); i++) {
		if (nodes[i].getId().compare(id) == 0) retValue = true;
	}
	return retValue;
}

Label Graph::findLabel(Node node) {
	Label label;
	for (size_t i = 0; i < labels.size(); i++) {
		if (labels[i].getCurrentNode().getId().compare(node.getId()) == 0) {
			label = labels[i];
			break;
		}
	}
	return label;
}

int Graph::getIndex(Label label) {
	auto it = find(labels.begin(), labels.end(), label);

	if (it != labels.end()) { 
		int index = distance(labels.begin(), it);
		cout << index << endl;
	}
	else {
		cout << "-1" << endl;
	}
}