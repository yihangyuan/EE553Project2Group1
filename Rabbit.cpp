#include "Rabbit.h"

// @brief Constructor for Rabbit
// @param x The x-coordinate of the Rabbit
// @param y The y-coordinate of the Rabbit
Rabbit::Rabbit(int x, int y) : Creature(x, y, "R") {}


// @brief Getter for the x-coordinate of the Rabbit. Overrides Creature's getX
// @return The x-coordinate of the Rabbit
int Rabbit::getX() {
	return Creature::getX();
}


// @brief Setter for the x-coordinate of the Rabbit. Overrides Creature's setX
// @param x The new x-coordinate for the Rabbit
void Rabbit::setX(int x) {
	Creature::setX(x);
}


// @brief Getter for the y-coordinate of the Rabbit. Overrides Creature's getY
// @return The y-coordinate of the Rabbit
int Rabbit::getY() {
	return Creature::getY();
}


// @brief Setter for the y-coordinate of the Rabbit. Overrides Creature's setY
// @param y The new y-coordinate for the Rabbit
void Rabbit::setY(int y) {
	Creature::setY(y);
}

