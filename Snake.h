#ifndef SNAKE_H
#define SNAKE_H
#include "Creature.h"
#include <climits>
#include <cfloat>

class Snake : public Creature {
public:
    Snake(int x, int y);            // Declaration of constructor
};

class gNode {
  public:
    double f,g,h;
    int pR,pC;
    bool blocked;
    bool closed;
    gNode(){
      f=g=h=INT_MAX;
      pR=pC=-1;
      blocked=false;
      closed=false;
    }
    gNode(double f, double g, double h, int pR, int pC, bool blocked, bool closed){
      this->f=f;
      this->g=g;
      this->g=h;
      this->pR=pR;
      this->pC=pC;
      this->blocked=blocked;
      this->closed=closed;
    }
    void setParams(double f, double g, double h, int pR, int pC,bool blocked, bool closed){
      this->f=f;
      this->g=g;
      this->g=h;
      this->pR=pR;
      this->pC=pC;
      this->blocked=blocked;
      this->closed=closed;
    }
    void setParams(double f, double g, double h, int pR, int pC){
      this->f=f;
      this->g=g;
      this->g=h;
      this->pR=pR;
      this->pC=pC;
    }
    void setParams(double f, double g, double h){
      this->f=f;
      this->g=g;
      this->g=h;
    }
    void setParams(int pR, int pC){
      this->pR=pR;
      this->pC=pC;
    }
    void setParams(bool closed){
      this->closed=closed;
    }
};

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;
#define isUnBlocked(g,x,y) !g[x][y].blocked
#endif
