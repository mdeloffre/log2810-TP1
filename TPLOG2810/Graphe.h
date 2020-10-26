#pragma once
#include "Arc.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Graph {
	vector<Node> nodes;
	vector<Arc> arcs;
	public:
		void display_graph();
		void readFromFile();
		vector<string> split(string, char);
		Node getNodeById(string id);
};


void Graph::display_graph() {
	//Create a list with sorted nodes and their neighbors for the display
	vector<vector<Node>> sortedNodes;
	cout << "Affichage du graphe : " << endl;
	if (arcs.empty()) {
		cout << "Pas d'arcs dans le graphe !" << endl;
	}
	else {
		
		Node compareNode = Graph::getNodeById(arcs[0].getStartingNode());
		
		cout << "(" << compareNode.getId() << ", " << compareNode.getType() << ", (" << arcs[0].getEndingNode();

		for (size_t i = 1; i < arcs.size(); i++) {
			Node currentNode = Graph::getNodeById(arcs[i].getStartingNode());
			//cout << "Ici, on compare le node " << currentNode.getId() << " avec le node " << compareNode.getId() << endl;
			if (currentNode.getId().compare(compareNode.getId()) == 0) {
				cout << ", " << arcs[i].getEndingNode();
			}

			else {
				cout << "))" << endl;

				compareNode = currentNode;
				//cout << "Nouveau node de comparaison : " << compareNode.getId() << endl;

				cout << "(" << compareNode.getId() << ", " << compareNode.getType() << ", (" << arcs[i].getEndingNode();
			}

		}

		cout << ")" << endl;
	}
	
}

void Graph::readFromFile() {

	fstream file;
	file.open("graphe.txt", ios::in);
	vector<string> current;
	if (file.is_open()) {
		string line;
		int lineNumber = 0;
		while (getline(file, line)) {
			//Split the line at each ';' character
			vector<string> tab = Graph::split(line, ';');

			for (size_t i = 0; i < tab.size(); i++) {
				//And then split each value to get each node's id and type
				current = Graph::split(tab[i], ',');

				//Nodes are on the first line
				if (lineNumber == 0) {
					Node node;
					string type = current[1];
					if (type.compare("rien") == 0) node.init(current[0], "null");
					else node.init(current[0], current[1]);
					Graph::nodes.push_back(node);
				}

				//Arcs are defined on the second line
				if (lineNumber == 1) {
					Arc arc;
					arc.init(current[0], current[1], current[2]);
					Graph::arcs.push_back(arc);
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
	Node node;
	//cout << "Entering getNodeById() function with argument " << id << endl;
	for (size_t i = 0; i < nodes.size(); i++) {
		if (nodes[i].getId().compare(id) == 0) {
			//cout << "Found the node ! It's " << nodes[i].getId() << endl;
			return nodes[i];
			
		}
	}
	return node;
}