/* Author: Gaurav Dubey
Date: 12/5/2023
Description: Header file which defines class named Rabbit.
*/
#ifndef RABBIT_H        // Header guards
#define RABBIT_H
#include "Creature.h"

class Rabbit : public Creature {
protected :
public:
    //Rabbit(int,int,string);
    // Declarations of constructor, getter and setter functions
    Rabbit(int x, int y);

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);
};
#endif
