#include "Veggie.h"

Veggie::Veggie(string symbol,string name,int points) : FieldInhabitant(symbol), name(name), points(points) {}

string Veggie::getName() {
	return name;
}

void Veggie::setName(string newname) {
	name = newname;
}
    
int Veggie::getPoints() {
	return points;
}

void Veggie::setPoints(int newpoints) {
	points = newpoints;
}

