#include "Creature.h"

Creature::Creature(int x, int y, string symbol) : FieldInhabitant(symbol), x(x), y(y) {}

int Creature::getX() {
	return x;
}
    
void Creature::setX(int newx) {
	x = newx;
}
    
int Creature::getY() {
	return y;
}

void Creature::setY(int newy) {
	y = newy;
}

