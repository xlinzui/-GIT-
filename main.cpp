#include <iostream>
#include <string>
#include <limits>
#include <iomanip> // For std::fixed and std::setprecision

// 使用 using namespace std; 简化代码
using namespace std;

// Include the headers for all shape classes
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

// 打印结果函数的实现，由于它不在任何类中，我们可以直接在此处定义
void printResult(const string& shape, double param1, double param2, double area, char unit);

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
            cout << "请输入正方形的边长: ";
            cin >> param1;
            cout << "请输入单位 (c:厘米, i:英寸): ";
            cin >> unit;

            Square square(param1, unit);
            double area = square.calculateArea();

            printResult("正方形", param1, 0, area, unit);
            break;
        }
        case 2: {
            cout << "请输入长方形的长: ";
            cin >> param1;
            cout << "请输入长方形的宽: ";
            cin >> param2;
            cout << "请输入单位 (c:厘米, i:英寸): ";
            cin >> unit;

            Rectangle rect(param1, param2, unit);
            double area = rect.calculateArea();

            printResult("长方形", param1, param2, area, unit);
            break;
        }
        case 3: {
            cout << "请输入三角形的底: ";
            cin >> param1;
            cout << "请输入三角形的高: ";
            cin >> param2;
            cout << "请输入单位 (c:厘米, i:英寸): ";
            cin >> unit;

            Triangle tri(param1, param2, unit);
            double area = tri.calculateArea();

            printResult("三角形", param1, param2, area, unit);
            break;
        }
        case 4: {
            cout << "请输入圆形的直径: ";
            cin >> param1;
            cout << "请输入单位 (c:厘米, i:英寸): ";
            cin >> unit;

            Circle circle(param1, unit);
            double area = circle.calculateArea();

            printResult("圆形", param1, 0, area, unit);
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

// 打印结果函数的实现
void printResult(const string& shape, double param1, double param2, double area, char unit) {
    cout << "\n------------------------------------" << endl;
    cout << "您选择的图形是: " << shape << endl;

    if (shape == "正方形" || shape == "圆形") {
        cout << "您输入的边长/直径是: " << param1 << " " << ((unit == 'i') ? "英寸" : "厘米") << endl;
    }
    else {
        cout << "您输入的长度和宽度/高是: " << param1 << " 和 " << param2 << " " << ((unit == 'i') ? "英寸" : "厘米") << endl;
    }

    cout.precision(3);
    cout << "最终面积: " << fixed << area << " 平方厘米" << endl;
    cout << "------------------------------------" << endl;
}
