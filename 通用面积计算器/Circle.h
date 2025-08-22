#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double diameter; // ֱ�������ף�
    char unit;       // ��λ

public:
    Circle(double diameter, char unit);
    double calculateArea() const override;
};

#endif