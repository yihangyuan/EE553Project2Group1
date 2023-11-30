#include "GameEngine.h"
using namespace std;

int main() {
  GameEngine* game = new GameEngine();
  game->initializeGame();
  game->intro();
  int remainingVeggies = game->remainingVeggies();
  while (remainingVeggies > 0) {
    cout << remainingVeggies << " veggies remaining. "; 
    cout << "Current score: " << game->getScore() << endl;
    game->printField();
    game->moveRabbits();
    game->moveCaptain();
    remainingVeggies = game->remainingVeggies();
  }
  game->gameOver();
  // delete game;
  return 0;

}