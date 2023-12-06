/* Authors: Al Zahra, Yihang Yuan, Gaurav Dubey
   Date: 12-07-2023
   Description: This program implements a simple game called "Captain Veggie". In the game, a 'GameEngine' object is created, initializing the game field with vegetables (veggies),
                a captain, and rabbits. The player, as the captain, must collect as many veggies as possible before they are eaten by the rabbits. 
                The game field is represented as a grid, where each cell can contain a veggie, a rabbit, the captain, or be empty. 
                The game proceeds in turns, where the player can move the captain to collect veggies and avoid rabbits. The rabbits also move randomly around the field. 
                The game ends when all veggies are either collected by the captain or eaten by the rabbits. The player's score is based on the number and type of veggies collected.
*/

#include "GameEngine.h"
using namespace std;

int main() {

  GameEngine* game = new GameEngine();                          // Create a new instance of GameEngine  
  game->initializeGame();                                       // Initialize the game elements such as veggies, captain, and rabbits
  game->intro();                                                // Display the introductory message for the game
  int remainingVeggies = game->remainingVeggies();              // Get the initial count of remaining vegetables on the field
            
  while (remainingVeggies > 0) {                                // Game loop that continues as long as there are veggies remaining
    cout << remainingVeggies << " veggies remaining. ";         // Display the count of remaining veggies and the current score
    cout << "Current score: " << game->getScore() << endl;

    game->printField();
    game->moveRabbits();
    game->moveCaptain();
    game->moveSnake();
    remainingVeggies = game->remainingVeggies();

  }
  game->gameOver();                                             // When no veggies are left, end the game and display the final results
  // delete game;
  return 0;

}
