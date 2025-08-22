#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(double length, double width, char unit) {
    if (unit == 'i') {
        this->length = inchesToCm(length);
        this->width = inchesToCm(width);
    } else {
        this->length = length;
        this->width = width;
    }
    this->unit = unit;
}

double Rectangle::calculateArea() const {
    return length * width;
}