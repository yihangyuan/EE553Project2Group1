#include "Captain.h"

// @brief Constructor for Captain
// @param x The x-coordinate of the Captain
// @param y The y-coordinate of the Captain
Captain::Captain(int x, int y) : Creature(x, y, "V") {}


// @brief Adds a Veggie object to the Captain's collection
// @param veggie Pointer to the Veggie object to be added
void Captain::addVeggie(Veggie* veggie) {
	collectedveggies.push_back(veggie);
}


// @brief Gets the names of the collected veggies
// @return A vector of strings representing the names of the collected veggies
vector<string> Captain::getCollectedVeggies() {
	vector<string> veggies;
	veggies.clear();
	for(int i=0; i<this->collectedveggies.size(); i++)				// Loop through collected veggies
		veggies.push_back(this->collectedveggies[i]->getName());		// Get and store the name of each Veggie
	return veggies;									// Return the list of Veggie names
}


/*void Captain::setCollectedVeggies(vector<Veggie*>& newcollectedveggies) {
	collectedveggies = newcollectedveggies;
}*/

void Captain::loseLast5Veggies() {
	if(this->collectedveggies.size() > 5) {
    for(int i=0;i<5;i++)
      this->collectedveggies.pop_back();
  }
  else
    this->collectedveggies.clear();
}


