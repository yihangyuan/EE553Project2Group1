#include "Veggie.h"

// @brief Constructor for Veggie
// @param symbol The symbol representing the Veggie
// @param name The name of the Veggie
// @param points The points associated with the Veggie
Veggie::Veggie(string symbol,string name,int points) : FieldInhabitant(symbol), name(name), points(points) {}


// @brief Getter for the Veggie's name
// @return The name of the Veggie
string Veggie::getName() {
	return name;
}


// @brief Setter for the Veggie's name
// @param newname The new name to set for the Veggie
void Veggie::setName(string newname) {
	name = newname;
}


// @brief Getter for the Veggie's points
// @return The points of the Veggie
int Veggie::getPoints() {
	return points;
}


// @brief Setter for the Veggie's points
// @param newpoints The new points value to set for the Veggie
void Veggie::setPoints(int newpoints) {
	points = newpoints;
}

