#include "FieldInhabitant.h"

FieldInhabitant::FieldInhabitant(string symbol) : symbol(symbol) {}

string FieldInhabitant::getSymbol() {
	return symbol;
}

void FieldInhabitant::setSymbol(string newsymbol) {
	symbol = newsymbol;
}
    
FieldInhabitant::~FieldInhabitant() {

}

