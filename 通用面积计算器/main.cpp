#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// ��������ͼ�����ͷ�ļ�
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ResultPrinter.h"

using namespace std;

// ���ߺ�������ȡ��Ч����
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�������������һ��������\n";
    }
}

// ���ߺ�������ȡ��Ч��λ
char getValidUnit() {
    char unit;
    while (true) {
        cout << "�����뵥λ (c:����, i:Ӣ��): ";
        cin >> unit;
        if (unit == 'c' || unit == 'i') {
            return unit;
        }
        cout << "������������� 'c' �� 'i'��\n";
    }
}

int main() {
    int choice;
    double param1, param2;
    char unit;

    while (true) {
        cout << "\n------------------------------------------------------" << endl;
        cout << "ͨ�����������" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "��ѡ����Ҫ���������ͼ�Σ�" << endl;
        cout << "1. ������" << endl;
        cout << "2. ������" << endl;
        cout << "3. ������" << endl;
        cout << "4. Բ��" << endl;
        cout << "5. �˳�" << endl;
        cout << "------------------------------------------------------" << endl;

        cout << "����������ѡ�� (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������Ч��������һ�����֡�\n" << endl;
            continue;
        }

        switch (choice) {
        case 1: {
            param1 = getValidInput("�����������εı߳�: ");
            unit = getValidUnit();

            Square square(param1, unit);
            double area = square.calculateArea();

            ResultPrinter::print("������", param1, 0, area, unit);
            break;
        }
        case 2: {
            param1 = getValidInput("�����볤���εĳ�: ");
            param2 = getValidInput("�����볤���εĿ�: ");
            unit = getValidUnit();

            Rectangle rect(param1, param2, unit);
            double area = rect.calculateArea();

            ResultPrinter::print("������", param1, param2, area, unit);
            break;
        }
        case 3: {
            param1 = getValidInput("�����������εĵ�: ");
            param2 = getValidInput("�����������εĸ�: ");
            unit = getValidUnit();

            Triangle tri(param1, param2, unit);
            double area = tri.calculateArea();

            ResultPrinter::print("������", param1, param2, area, unit);
            break;
        }
        case 4: {
            param1 = getValidInput("������Բ�ε�ֱ��: ");
            unit = getValidUnit();

            Circle circle(param1, unit);
            double area = circle.calculateArea();

            ResultPrinter::print("Բ��", param1, 0, area, unit);
            break;
        }
        case 5:
            cout << "\n��лʹ�ã��������˳���\n" << endl;
            return 0;
        default:
            cout << "ѡ����Ч�������� 1-5 ֮������֡�\n" << endl;
            break;
        }
    }

    return 0;
}