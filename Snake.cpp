#include "Snake.h"

// @brief Constructor for Snake
// @param x The initial x-coordinate of the Snake
// @param y The initial y-coordinate of the Snake
// Initializes a Snake object at specified coordinates and inherits from Creature class
Snake::Snake(int x, int y) : Creature(x, y, "S") {}
