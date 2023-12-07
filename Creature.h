/* Author: Gaurav Dubey, Yihang Yuan, Al Zahra
Date: 12/5/2023
Description: Header file which defines class named Creature.
*/

#ifndef CREATURE_H                // Header guards
#define CREATURE_H
#include "FieldInhabitant.h"
using namespace std;

class Creature : public FieldInhabitant {
  protected :
    int x;                        // x-coordinate of the Creature 
    int y;                        // y-coordinate of the Creature 
  public:
    // Declarations of Constructor, getter and setter functions
    Creature(int,int,string);
    void setX(int);
    int getX();
    void setY(int);
    int getY();
};

#endif
