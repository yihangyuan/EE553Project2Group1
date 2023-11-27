#ifndef CREATURE_H
#define CREATURE_H
#include "FieldInhabitant.h"
using namespace std;

class Creature : public FieldInhabitant {
  protected :
    int x;
    int y;
  public:
    Creature(int,int,string);
    void setX(int);
    int getX();
    void setY(int);
    int getY();
};

#endif
