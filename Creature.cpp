/* Authors: Al Zahra, Yihang Yuan, Gaurav Dubey
   Date: 12-07-2023
   Description: This file implements functions of class Creature
*/

#include "Creature.h"

// @brief Constructor for Creature
// @param x The x-coordinate of the Creature
// @param y The y-coordinate of the Creature
// @param symbol The symbol representing the Creature
Creature::Creature(int x, int y, string symbol) : FieldInhabitant(symbol), x(x), y(y) {}


// @brief Getter for the x-coordinate of the Creature
// @return The x-coordinate of the Creature
int Creature::getX() {
	return x;
}


// @brief Setter for the x-coordinate of the Creature
// @param newx The new x-coordinate to set for the Creature
void Creature::setX(int newx) {
	x = newx;
}
    

// @brief Getter for the y-coordinate of the Creature
// @return The y-coordinate of the Creature
int Creature::getY() {
	return y;
}


// @brief Setter for the y-coordinate of the Creature
// @param newy The new y-coordinate to set for the Creature
void Creature::setY(int newy) {
	y = newy;
}

