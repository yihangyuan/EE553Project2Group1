#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H
#include <string>
using namespace std;

class FieldInhabitant {
  protected :
    string symbol;
  public:
    FieldInhabitant(string);
    void setSymbol(string);
    string getSymbol();
    virtual ~FieldInhabitant();
};

#endif
