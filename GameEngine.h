#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Creature.h"
class GameEngine : public Creature {
  protected :
    FieldInhabitant *** array2D;
    int height;
    int width;
    int score;
  public:
};
#endif