/* Author: Gaurav Dubey, Yihang Yuan, Al Zahra
Date: 12/5/2023
Description: Header file which defines classes named Snake, gNode and others typedefs.
*/

#ifndef SNAKE_H
#define SNAKE_H
#include "Creature.h"
#include <climits>
#include <cfloat>

class Snake : public Creature {
public:
    // @brief Snake constructor
    // @return nothing
    Snake(int x, int y);            // Declaration of constructor
};


/*
This class is used to represent a graph node
of a 2D matrix
double f,g,h are defined as 
g = the movement cost to move from the starting point to a given square on the grid, following the path generated to get there. 
h = the estimated movement cost to move from that given square on the grid to the final destination. 
f = g + h
two integers represents its parent node's euclidean coordinates:
pR
pC
two boolen represents:
blocked = whether the node is blocked i.e. an obstacle
closed = this flag for the purpose of a* algorithm represents that the node once added to the open list is now closed
*/
class gNode {
  public:
    double f,g,h;
    int pR,pC;
    bool blocked;
    bool closed;
    // @brief gNode constructor
    // @return nothing
    gNode(){
      f=g=h=INT_MAX;
      pR=pC=-1;
      blocked=false;
      closed=false;
    }
    // @brief gNode constructor
    // @param f is f
    // @param g is g
    // @param h is h
    // @param pR is parent node's row index
    // @param pC is parent node's column index
    // @param blocked is blocked
    // @param closed is closed
    // @return nothing
    gNode(double f, double g, double h, int pR, int pC, bool blocked, bool closed){
      this->f=f;
      this->g=g;
      this->g=h;
      this->pR=pR;
      this->pC=pC;
      this->blocked=blocked;
      this->closed=closed;
    }
    // @brief mutator function to set all the members of gNode
    // @param f is f
    // @param g is g
    // @param h is h
    // @param pR is parent node's row index
    // @param pC is parent node's column index
    // @param blocked is blocked
    // @param closed is closed
    // @return nothing
    void setParams(double f, double g, double h, int pR, int pC,bool blocked, bool closed){
      this->f=f;
      this->g=g;
      this->g=h;
      this->pR=pR;
      this->pC=pC;
      this->blocked=blocked;
      this->closed=closed;
    }
    // @brief mutator function to set the f, g, h, pR, and pC members of gNode
    // @param f is f
    // @param g is g
    // @param h is h
    // @param pR is parent node's row index
    // @param pC is parent node's column index
    // @return nothing
    void setParams(double f, double g, double h, int pR, int pC){
      this->f=f;
      this->g=g;
      this->g=h;
      this->pR=pR;
      this->pC=pC;
    }
    // @brief mutator function to set the f, g, h members of gNode
    // @param f is f
    // @param g is g
    // @param h is h
    // @return nothing
    void setParams(double f, double g, double h){
      this->f=f;
      this->g=g;
      this->g=h;
    }
    // @brief mutator function to set the pR and pC members of gNode
    // @param pR is parent node's row index
    // @param pC is parent node's column index
    // @return nothing
    void setParams(int pR, int pC){
      this->pR=pR;
      this->pC=pC;
    }
    // @brief mutator function to set the closed member of gNode
    // @param closed is closed
    // @return nothing
    void setParams(bool closed){
      this->closed=closed;
    }
};
//typedefs
typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;
//defines
#define isUnBlocked(g,x,y) !g[x][y].blocked
#endif
