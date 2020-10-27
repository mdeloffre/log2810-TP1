// TPLOG2810.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Graphe.h"
#include "Arc.h"
#include "Node.h"
#include "Vehicle.h"
using namespace std;

int main()
{

    string filename = "graphe.txt";
    int answer;

    string vehicleType = "null";
    int vehicleAutonomy = 100;
    int vehicleMaxAutonomy = 150;
    string startingID, endingID;

    Graph graph;
    Vehicle vehicle(vehicleType, vehicleAutonomy, vehicleMaxAutonomy);



    while (1) {
        cout << endl << "============ Menu Principal ============" << endl;
        cout << "Caracteristiques du vehicule actuel : " << vehicle.getType() << " - autonomie " << vehicle.getAutonomie() << "/" << vehicle.getAutonomieMax() << "km" << endl << endl;
        cout << "1. Changer les caracteristiques du vehicule" << endl;
        cout << "2. Mettre a jour la carte" << endl;
        cout << "3. Extraire le sous-graphe" << endl;
        cout << "4. Calculer le plus court chemin" << endl;
        cout << "5. Quitter l'application" << endl << endl;
        cout << "Effectuez votre choix : ";
        cin >> answer;
        cout << endl;

        switch (answer) {
        case 1:
            do {
                cout << "Type du vehicule (essence/electrique/hybride) : ";
                cin >> vehicleType;
            } while (!((vehicleType.compare("essence") == 0) || (vehicleType.compare("hybride") == 0) || (vehicleType.compare("electrique") == 0)));
            vehicle.setType(vehicleType);
            cout << "Autonomie maximale du vehicule : ";
            cin >> vehicleMaxAutonomy;
            vehicle.setAutonomieMax(vehicleMaxAutonomy);
            cout << "Autonomie actuelle du vehicule : ";
            cin >> vehicleAutonomy;
            vehicle.setAutonomie(vehicleAutonomy);
            break;
        case 2:
            cout << "Entrez le nom du fichier a lire : ";
            cin >> filename;
            graph.readFromFile(filename);
            graph.display_graph();
            break;
        case 3:
            if (vehicleType.compare("null") == 0) {
                cout << "Veuillez d'abord choisir un type de vehicule !" << endl;
                break;
            }
            else {
                cout << "Not implemented yet" << endl;
                break;
            }
        case 4:
            do {
                cout << "Entrez l'ID du sommet de depart : ";
                cin >> startingID;
            } while (graph.nodeExists(startingID));
            
            do {
                cout << "Entrez l'ID du sommet d'arrivee : ";
                cin >> endingID;
            } while (graph.nodeExists(endingID));

            graph.shortestPath(startingID, endingID);
            break;
        case 5:
            exit(1);
        default:
            cout << "Entrez un chiffre entre 1 et 5 pour choisir une des options" << endl;
        }
    }
}

