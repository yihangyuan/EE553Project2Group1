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

	int count = 0; 

	for(int i = 0; i < height; i++){

		for(int j = 0; j < width; j++){

			Veggie * veggie = dynamic_cast<Veggie *>(array2D[i][j]);

			if(veggie != nullptr){
				count += 1;
			}
		}
	}

	return count;
}

void GameEngine::intro() {

	cout << "Welcome to Captain Veggie!" << endl
		 << "The rabbits have invaded your garden and you must harvest" << endl
		 << "as many vegetables as possible before the rabbits eat them" << endl
		 << "all! Each vegetable is worth a different number of points" << endl
		 << "so go for the high score!" << endl
		 << endl
		 << "The vegetables are:" << endl;

	for(int i = 0; i < veggies.size(); i ++){
		
		cout << veggies[i]->getSymbol() <<": "
			 << veggies[i]->getName() << " "
			 << veggies[i]->getPoints() << " points" 
			 << endl;
	}

	cout << "Captain Veggie is V, and the rabbits are R's." << endl
		 << endl
		 << "Good luck!" << endl
		 << endl;
	

}

void GameEngine::printField(){

	cout << string(width + 2, '#') << endl; // header
	
	for(int i = 0; i < height; i++){
		
		cout << '#';
		
		for(int j = 0; j< width; j++){

			Veggie * veggie = dynamic_cast<Veggie *>(array2D[i][j]);
			
			if(veggie != nullptr){

				cout << veggie->getSymbol();

			}else{

				Rabbit * rabbit = dynamic_cast<Rabbit *>(array2D[i][j]);
				
				if(rabbit != nullptr){
					
					cout << "R";
					 
				}else{

					Captain * myCaptain = dynamic_cast <Captain *>(array2D[i][j]);

					if(myCaptain != nullptr){

						cout << "V";

					}else{

						cout << " ";
					}
				}
				
			}
		}

		cout << '#' << endl;

	}

	cout << string(width + 2, '#') << endl;

}

int GameEngine::getScore(){
	return this->score;
}

void GameEngine::moveRabbits(){

	srand(time(NULL));

	int x, y, xdp, ydp;
	bool illegal;
	Rabbit * myRabbit;

	for(int i = 0; i < rabbits.size(); i ++){

		illegal = true; 
		myRabbit = rabbits[i];
		x = myRabbit->getX();
		y = myRabbit->getY();
		
		do{

			xdp = rand() % 3 - 1;
			ydp = rand() % 3 - 1;

			if(xdp == 0 && ydp ==0){
				
				illegal = false;

			}else{

				

			}


		}while(illegal);

		
		
	}
}

