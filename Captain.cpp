#include "Captain.h"

Captain::Captain(int x, int y) : Creature(x, y, "V") {}

void Captain::addVeggie(Veggie* veggie) {
	collectedveggies.push_back(veggie);
}

vector<string> Captain::getCollectedVeggies() {
	vector<string> veggies;
	veggies.clear();
	for(int i=0; i<this->collectedveggies.size(); i++)
		veggies.push_back(this->collectedveggies[i]->getName());
	return veggies;
}

/*void Captain::setCollectedVeggies(vector<Veggie*>& newcollectedveggies) {
	collectedveggies = newcollectedveggies;
}*/

