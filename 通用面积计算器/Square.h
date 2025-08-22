#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    double side;  // 边长（厘米）
    char unit;    // 单位

public:
    Square(double side, char unit);
    double calculateArea() const override;
};

#endif