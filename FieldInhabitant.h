/* Author: Gaurav Dubey
Date: 12/5/2023
Description: Header file which defines class named FieldInhabitant.
*/
#ifndef FIELDINHABITANT_H         // Header guards
#define FIELDINHABITANT_H
#include <string>
using namespace std;

class FieldInhabitant {
  protected :
    string symbol;                // symbol representing the FieldInhabitant
  public:
    // Declarations of Constructor, getter, setter and virtual deconstructor functions
    FieldInhabitant(string);
    void setSymbol(string);
    string getSymbol();
    virtual ~FieldInhabitant();
};

#endif
