#ifndef VEGGIE_H
#define VEGGIE_H
#include "FieldInhabitant.h"
using namespace std;

class Veggie : public FieldInhabitant {
  protected :
    string name;
    int    points;
  public:
    Veggie(string,string,int);
    void setName(string);
    string getName();
    void setPoints(int);
    int getPoints();
};

#endif
