// TPLOG2810.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Graphe.h"
#include "Arc.h"
#include "Node.h"
using namespace std;

int main()
{
    Graph graph;
    
    graph.readFromFile();
    graph.display_graph();

}

