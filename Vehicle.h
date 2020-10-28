#pragma once
#include <string>
using namespace std;

class Vehicle {
	int autonomie;
	int autonomieMax;
	string type;

public:
	Vehicle(string, int, int);
	Vehicle();
	void setType(string);
	string getType();
	void setAutonomie(int);
	int getAutonomie();
	void setAutonomieMax(int);
	int getAutonomieMax();
};

Vehicle::Vehicle(string type, int autonomie, int autonomieMax) {
	Vehicle::type = type;
	Vehicle::autonomie = autonomie;
	Vehicle::autonomieMax = autonomieMax;
}

Vehicle::Vehicle() {}

void Vehicle::setType(string type) {
	Vehicle::type = type;
}

void Vehicle::setAutonomie(int autonomie) {
	Vehicle::autonomie = autonomie;
}

void Vehicle::setAutonomieMax(int autonomieMax) {
	Vehicle::autonomieMax = autonomieMax;
}

string Vehicle::getType() {
	return type;
}

int Vehicle::getAutonomie() {
	return autonomie;
}

int Vehicle::getAutonomieMax() {
	return autonomieMax;
}