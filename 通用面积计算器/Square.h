#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    double side;  // �߳������ף�
    char unit;    // ��λ

public:
    Square(double side, char unit);
    double calculateArea() const override;
};

#endif