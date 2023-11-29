#include "Captain.h"

Captain::Captain(int x, int y) : Creature(x, y, "V") {}

void Captain::addVeggie(Veggie* veggie) {
	collectedveggies.push_back(veggie);
}

vector<Veggie*>& Captain::getCollectedVeggies() {
	return collectedveggies;
}

void Captain::setCollectedVeggies(vector<Veggie*>& newcollectedveggies) {
	collectedveggies = newcollectedveggies;
}

