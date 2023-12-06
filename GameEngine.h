#ifndef GAMEENGINE_H								// Header guards
#define GAMEENGINE_H
#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"
#include "Creature.h"
#include "Snake.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime> 
<<<<<<< HEAD

=======
#include <unordered_map> 
#include <set>
#include <cmath>
#include <stack>


#define isValid(x,y) ((x>=0) && (x < (this->height)) && (y >=0) && (y< (this->width)))
#define isDestination(x,y) ((x==captain->getX())&&(y==captain->getY()))
#define calculateHValue(x,y) (double) sqrt(pow((x-captain->getX()),2)+pow((y-captain->getY()),2))
>>>>>>> d5e754bcf511384e1ad49d4459802161677c59a8
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

<<<<<<< HEAD
	Captain* captain;								// Pointer to the Captain object
	vector<Rabbit*> rabbits;						// Vector of pointers to Rabbit objects
	vector<Veggie*> veggies;						// Vector of pointers to Veggie objects

	// Private member functions for initializing game components
=======
	Captain* captain;
	Snake* snake;
	vector<Rabbit*> rabbits;
	vector<Veggie*> veggies;

  unordered_map<string,int> VeggiePoints;
  int bites;

>>>>>>> d5e754bcf511384e1ad49d4459802161677c59a8
	void initVeggies();
	void initCaptain();
	void initRabbits();
	void initSnake();

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
	void moveSnake();
	void gameOver();

	// Public member functions for retrieving game information
	int getScore();
	int remainingVeggies();

	
};

#endif
