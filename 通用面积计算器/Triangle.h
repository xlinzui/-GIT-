#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    double base;   // 底边（厘米）
    double height; // 高（厘米）
    char unit;     // 单位

public:
    Triangle(double base, double height, char unit);
    double calculateArea() const override;
};

#endif