#include "Square.h"
#include <cmath>

Square::Square(double side, char unit) {
    this->side = (unit == 'i') ? inchesToCm(side) : side;
    this->unit = unit;
}

double Square::calculateArea() const {
    return side * side;
}