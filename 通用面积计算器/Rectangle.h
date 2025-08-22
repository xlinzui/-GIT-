#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double length;  // 长（厘米）
    double width;   // 宽（厘米）
    char unit;      // 单位

public:
    Rectangle(double length, double width, char unit);
    double calculateArea() const override;
};

#endif