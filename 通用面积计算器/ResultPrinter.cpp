#include "ResultPrinter.h"
#include <iostream>
#include <iomanip>

void ResultPrinter::print(const std::string& shape, double param1, double param2, double area, char unit) {
    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "��ѡ���ͼ����: " << shape << std::endl;

    if (shape == "������" || shape == "Բ��") {
        std::cout << "������ı߳�/ֱ����: " << param1 << " " << ((unit == 'i') ? "Ӣ��" : "����") << std::endl;
    } else {
        std::cout << "������ĳ��ȺͿ��/����: " << param1 << " �� " << param2 << " " << ((unit == 'i') ? "Ӣ��" : "����") << std::endl;
    }

    std::cout.precision(3);
    std::cout << "�������: " << std::fixed << area << " ƽ������" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}