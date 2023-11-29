#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"
#include "Creature.h"

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
	vector<Rabbit*> rabbits;
	vector<Veggie*> veggies;

	void initVeggies();
	void initCaptain();
	void initRabbits();

	void moveCptVertical(int movement);
	void moveCptHorizontal(int movement);

public:
	GameEngine(int height, int width);

	void initializeGame();
	void intro();
	void printField();
	void moveRabbits();
	void moveCaptain();
	void gameOver();

	int getScore();
	int remainingVeggies();

	~GameEngine();
};

#endif
