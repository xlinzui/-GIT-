#ifndef RESULT_PRINTER_H
#define RESULT_PRINTER_H

#include <string>

class ResultPrinter {
public:
    static void print(const std::string& shape, double param1, double param2, double area, char unit);
};

#endif