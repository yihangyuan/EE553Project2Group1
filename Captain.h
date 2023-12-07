/* Author: Gaurav Dubey
Date: 12/5/2023
Description: Header file which defines class named Captain.
*/
#ifndef CAPTAIN_H                           // Header guards
#define CAPTAIN_H
#include "Creature.h"
#include "Veggie.h"
#include <vector>
using namespace std;

class Captain : public Creature {
  protected :
    vector<Veggie*> collectedveggies;       // Vector to store pointers to collected Veggie objects
  public:
    //Captain(int,int,string);
    // Declarations for constructor, addVeggie and getter functions
    Captain(int x,int y);                 
    void addVeggie(Veggie*);

    vector<string> getCollectedVeggies();
    void loseLast5Veggies();
};

#endif
