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

	inveggief >> height >> width;

	array2D = new FieldInhabitant** [height];
	for(int i =0; i < height; ++i) {
		array2D[i] = new FieldInhabitant* [width];
		for(int j =0; j < width; ++j) {
			array2D[i][j] = nullptr;
		}
	}

	srand(0);

	for(int i = 0; i < NUMBEROFVEGGIES; ++i) {
		int xp, yp;
		do {
			xp = rand() % height;
			yp = rand() % width;
		}while(array2D[xp][yp] != nullptr);

		array2D[xp][yp] = veggies.back();
	}

	inveggief.close();

}
