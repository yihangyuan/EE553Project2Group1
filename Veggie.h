#ifndef VEGGIE_H              // Header guards
#define VEGGIE_H
#include "FieldInhabitant.h"
using namespace std;

class Veggie : public FieldInhabitant {
  protected :
    string name;            // Name of the vegetable
    int    points;          // Point value of the vegetable
  public:
    // Declarations of constructor, getter and setter functions
    Veggie(string,string,int);
    void setName(string);
    string getName();
    void setPoints(int);
    int getPoints();
};

#endif
