#include "GameEngine.h"

void GameEngine::initializeGame() {
	initVeggies();
	initCaptain();
	initRabbits();
	score = 0;
}

void GameEngine::initVeggies() {
	string filename;
	ifstream inveggief;

	while(true) {
		cout << "Please enter the name of the vegetable point file: ";
		getline(cin, filename);
		inveggief.open(filename);

		if(inveggief)
			break;
		else
			cout << filename << " does not exist! Please enter the name of the vegetable point file: ";
	}

	// these variables are for dealing with format
	string dummy;
	char comma; 
	inveggief >> dummy >> height >> comma >> width;

	// Garlic,G,5
	while(inveggief) { // add veggies to vector
		string name;
		string symbol;
		int points;

		inveggief >> name >> comma >> symbol >> comma >> points;
		Veggie* veggie = new Veggie(symbol, name, points);
		veggies.push_back(veggie);
	}

	array2D = new FieldInhabitant** [height]; // create 2D array
	for(int i =0; i < height; ++i) {
		array2D[i] = new FieldInhabitant* [width];
		for(int j =0; j < width; ++j) {
			array2D[i][j] = nullptr;
		}
	}

	srand(time(NULL)); // current time as seed

	for(int i = 0; i < NUMBEROFVEGGIES; ++i) {
		int xp, yp, vegIndex;
		do {
			xp = rand() % height;
			yp = rand() % width;
			vegIndex = rand() % veggies.size();
		}while(array2D[xp][yp] != nullptr);

		array2D[xp][yp] = veggies[vegIndex];
	}

	inveggief.close();

}

void GameEngine::initCaptain(){

	srand(time(NULL));
	int xp, yp;
	do {
			xp = rand() % height;
			yp = rand() % width;

	}while(array2D[xp][yp] != nullptr);

	Captain * myCaptain = new Captain( xp, yp);
	captain = myCaptain;
	array2D[xp][yp] = captain;

}


void GameEngine::initRabbits() {
	srand(time(NULL));

	for(int i = 0; i < NUMBEROFRABBITS; ++i) {
		int xp, yp;
		do {
			xp = rand() % height;
			yp = rand() % width;
		}while(array2D[xp][yp] != nullptr);

		Rabbit* rabbit = new Rabbit(xp, yp);
		rabbits.push_back(rabbit);
		array2D[xp][yp] = rabbit;
	}
}

int GameEngine::remainingVeggies(){

}

void GameEngine::intro() {

}