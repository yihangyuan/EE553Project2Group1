/* Authors: Al Zahra, Yihang Yuan, Gaurav Dubey
   Date: 12-07-2023
   Description: This file implements functions of class FieldInhabitant
*/
#include "FieldInhabitant.h"

// @brief Constructor for FieldInhabitant
// @param symbol The symbol representing the FieldInhabitant
FieldInhabitant::FieldInhabitant(string symbol) : symbol(symbol) {}


// @brief Getter for symbol
// @return The symbol of the FieldInhabitant
string FieldInhabitant::getSymbol() {
	return symbol;
}


// @brief Setter for symbol
// @param newsymbol The new symbol to set for the FieldInhabitant
void FieldInhabitant::setSymbol(string newsymbol) {
	symbol = newsymbol;
}


// @brief Destructor for FieldInhabitant
FieldInhabitant::~FieldInhabitant() {}

