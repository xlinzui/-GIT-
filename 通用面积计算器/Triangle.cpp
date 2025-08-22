#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double base, double height, char unit) {
    if (unit == 'i') {
        this->base = inchesToCm(base);
        this->height = inchesToCm(height);
    } else {
        this->base = base;
        this->height = height;
    }
    this->unit = unit;
}

double Triangle::calculateArea() const {
    return (base * height) / 2.0;
}