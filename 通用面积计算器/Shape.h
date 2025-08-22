#pragma once
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default;
    
    // ��̬���ߺ�����Ӣ��ת����
    static double inchesToCm(double inches) {
        return inches * 2.54;
    }
};

#endif