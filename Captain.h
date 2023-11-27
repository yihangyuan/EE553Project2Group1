#ifndef CAPTAIN_H
#define CAPTAIN_H
#include "Creature.h"
#include "Veggie.h"
#include <vector>
using namespace std;

class Captain : public Creature {
  protected :
    vector<Veggie*> veggies;
  public:
    Captain(int,int,string);
    void addVeggie(Veggie*);
};

#endif
