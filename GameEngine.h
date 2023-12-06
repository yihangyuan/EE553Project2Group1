#ifndef GAMEENGINE_H								// Header guards
#define GAMEENGINE_H
#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"
#include "Creature.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime> 

//class GameEngine : public Creature {
class GameEngine {
//protected:
private:
	FieldInhabitant*** array2D;						// 2D dynamic array representing the game field
	int height;										// Height of the game field
	int width;										// Width of the game field	
	int score;										// Current score of the game

	const int NUMBEROFVEGGIES = 30;					// Total number of veggies to place on the field
	const int NUMBEROFRABBITS = 5;					// Total number of rabbits to place on the field

	Captain* captain;								// Pointer to the Captain object
	vector<Rabbit*> rabbits;						// Vector of pointers to Rabbit objects
	vector<Veggie*> veggies;						// Vector of pointers to Veggie objects

	// Private member functions for initializing game components
	void initVeggies();
	void initCaptain();
	void initRabbits();

	// Private member functions for moving the captain
	void moveCptVertical(int movement);
	void moveCptHorizontal(int movement);

public:
	// Public member functions for game flow and control
	void initializeGame();
	void intro();
	void printField();
	void moveRabbits();
	void moveCaptain();
	void gameOver();

	// Public member functions for retrieving game information
	int getScore();
	int remainingVeggies();

	
};

#endif
