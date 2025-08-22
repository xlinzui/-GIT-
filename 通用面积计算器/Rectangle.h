#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double length;  // �������ף�
    double width;   // �����ף�
    char unit;      // ��λ

public:
    Rectangle(double length, double width, char unit);
    double calculateArea() const override;
};

#endif