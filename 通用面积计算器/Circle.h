#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double diameter; // 直径（厘米）
    char unit;       // 单位

public:
    Circle(double diameter, char unit);
    double calculateArea() const override;
};

#endif