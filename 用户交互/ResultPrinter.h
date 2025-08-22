#ifndef RESULT_PRINTER_H
#define RESULT_PRINTER_H

#include <string>

class ResultPrinter {
public:
    // 使用静态方法，以便于直接调用，无需创建对象
    static void print(const std::string& shape, double param1, double param2, double area, char unit);
};

#endif
