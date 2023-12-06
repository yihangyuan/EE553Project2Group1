#ifndef GAMEENGINE_H
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
#include <unordered_map> 
#include <set>
#include <cmath>
#include <stack>


#define isValid(x,y) ((x>=0) && (x < (this->height)) && (y >=0) && (y< (this->width)))
#define isDestination(x,y) ((x==captain->getX())&&(y==captain->getY()))
#define calculateHValue(x,y) (double) sqrt(pow((x-captain->getX()),2)+pow((y-captain->getY()),2))
//class GameEngine : public Creature {
class GameEngine {
//protected:
private:
	FieldInhabitant*** array2D;
	int height;
	int width;
	int score;

	const int NUMBEROFVEGGIES = 30;
	const int NUMBEROFRABBITS = 5;

	Captain* captain;
	Snake* snake;
	vector<Rabbit*> rabbits;
	vector<Veggie*> veggies;

  unordered_map<string,int> VeggiePoints;
  int bites;

	void initVeggies();
	void initCaptain();
	void initRabbits();
	void initSnake();

	void moveCptVertical(int movement);
	void moveCptHorizontal(int movement);

public:
	// GameEngine(int height, int width);

	void initializeGame();
	void intro();
	void printField();
	void moveRabbits();
	void moveCaptain();
	void moveSnake();
	void gameOver();

	int getScore();
	int remainingVeggies();

	// ~GameEngine();
};

#endif
