#include "Rabbit.h"

Rabbit::Rabbit(int x, int y) : Creature(x, y, "R") {}

int Rabbit::getX() {
	return Creature::getX();
}

void Rabbit::setX(int x) {
	Creature::setX(x);
}

int Rabbit::getY() {
	return Creature::getY();
}

void Rabbit::setY(int y) {
	Creature::setY(y);
}

