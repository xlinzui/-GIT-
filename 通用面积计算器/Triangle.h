#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    double base;   // �ױߣ����ף�
    double height; // �ߣ����ף�
    char unit;     // ��λ

public:
    Triangle(double base, double height, char unit);
    double calculateArea() const override;
};

#endif