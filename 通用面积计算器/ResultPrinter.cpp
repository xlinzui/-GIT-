#include "ResultPrinter.h"
#include <iostream>
#include <iomanip>

void ResultPrinter::print(const std::string& shape, double param1, double param2, double area, char unit) {
    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "您选择的图形是: " << shape << std::endl;

    if (shape == "正方形" || shape == "圆形") {
        std::cout << "您输入的边长/直径是: " << param1 << " " << ((unit == 'i') ? "英寸" : "厘米") << std::endl;
    } else {
        std::cout << "您输入的长度和宽度/高是: " << param1 << " 和 " << param2 << " " << ((unit == 'i') ? "英寸" : "厘米") << std::endl;
    }

    std::cout.precision(3);
    std::cout << "最终面积: " << std::fixed << area << " 平方厘米" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}