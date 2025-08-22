#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// 包含所有图形类的头文件
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ResultPrinter.h"

using namespace std;

// 工具函数：获取有效输入
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "输入错误！请输入一个正数。\n";
    }
}

// 工具函数：获取有效单位
char getValidUnit() {
    char unit;
    while (true) {
        cout << "请输入单位 (c:厘米, i:英寸): ";
        cin >> unit;
        if (unit == 'c' || unit == 'i') {
            return unit;
        }
        cout << "输入错误！请输入 'c' 或 'i'。\n";
    }
}

int main() {
    int choice;
    double param1, param2;
    char unit;

    while (true) {
        cout << "\n------------------------------------------------------" << endl;
        cout << "通用面积计算器" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "请选择您要计算面积的图形：" << endl;
        cout << "1. 正方形" << endl;
        cout << "2. 长方形" << endl;
        cout << "3. 三角形" << endl;
        cout << "4. 圆形" << endl;
        cout << "5. 退出" << endl;
        cout << "------------------------------------------------------" << endl;

        cout << "请输入您的选择 (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入无效，请输入一个数字。\n" << endl;
            continue;
        }

        switch (choice) {
        case 1: {
            param1 = getValidInput("请输入正方形的边长: ");
            unit = getValidUnit();

            Square square(param1, unit);
            double area = square.calculateArea();

            ResultPrinter::print("正方形", param1, 0, area, unit);
            break;
        }
        case 2: {
            param1 = getValidInput("请输入长方形的长: ");
            param2 = getValidInput("请输入长方形的宽: ");
            unit = getValidUnit();

            Rectangle rect(param1, param2, unit);
            double area = rect.calculateArea();

            ResultPrinter::print("长方形", param1, param2, area, unit);
            break;
        }
        case 3: {
            param1 = getValidInput("请输入三角形的底: ");
            param2 = getValidInput("请输入三角形的高: ");
            unit = getValidUnit();

            Triangle tri(param1, param2, unit);
            double area = tri.calculateArea();

            ResultPrinter::print("三角形", param1, param2, area, unit);
            break;
        }
        case 4: {
            param1 = getValidInput("请输入圆形的直径: ");
            unit = getValidUnit();

            Circle circle(param1, unit);
            double area = circle.calculateArea();

            ResultPrinter::print("圆形", param1, 0, area, unit);
            break;
        }
        case 5:
            cout << "\n感谢使用，程序已退出。\n" << endl;
            return 0;
        default:
            cout << "选择无效，请输入 1-5 之间的数字。\n" << endl;
            break;
        }
    }

    return 0;
}