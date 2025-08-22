#pragma once
#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
    // 构造函数，接收边长和单位
    Square(double side, char unit);

    // 计算面积的方法
    double calculateArea();
};

#endif // SQUARE_H


