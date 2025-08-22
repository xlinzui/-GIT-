#include "Circle.h"
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(double diameter, char unit) {
    this->diameter = (unit == 'i') ? inchesToCm(diameter) : diameter;
    this->unit = unit;
}

double Circle::calculateArea() const {
    double radius = diameter / 2.0;
    return M_PI * radius * radius;
}