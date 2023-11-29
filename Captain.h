#ifndef CAPTAIN_H
#define CAPTAIN_H
#include "Creature.h"
#include "Veggie.h"
#include <vector>
using namespace std;

class Captain : public Creature {
  protected :
    vector<Veggie*> collectedveggies;
  public:
    //Captain(int,int,string);
    Captain(int x,int y);
    void addVeggie(Veggie*);

    vector<Veggie*>& getCollectedVeggies();
    void setCollectedVeggies(vector<Veggie*>&);
};

#endif
