#include <iostream>
#include <string>
#include <limits>
#include <iomanip> // For std::fixed and std::setprecision

// ʹ�� using namespace std; �򻯴���
using namespace std;

// Include the headers for all shape classes
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

// ��ӡ���������ʵ�֣������������κ����У����ǿ���ֱ���ڴ˴�����
void printResult(const string& shape, double param1, double param2, double area, char unit);

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
            cout << "�����������εı߳�: ";
            cin >> param1;
            cout << "�����뵥λ (c:����, i:Ӣ��): ";
            cin >> unit;

            Square square(param1, unit);
            double area = square.calculateArea();

            printResult("������", param1, 0, area, unit);
            break;
        }
        case 2: {
            cout << "�����볤���εĳ�: ";
            cin >> param1;
            cout << "�����볤���εĿ�: ";
            cin >> param2;
            cout << "�����뵥λ (c:����, i:Ӣ��): ";
            cin >> unit;

            Rectangle rect(param1, param2, unit);
            double area = rect.calculateArea();

            printResult("������", param1, param2, area, unit);
            break;
        }
        case 3: {
            cout << "�����������εĵ�: ";
            cin >> param1;
            cout << "�����������εĸ�: ";
            cin >> param2;
            cout << "�����뵥λ (c:����, i:Ӣ��): ";
            cin >> unit;

            Triangle tri(param1, param2, unit);
            double area = tri.calculateArea();

            printResult("������", param1, param2, area, unit);
            break;
        }
        case 4: {
            cout << "������Բ�ε�ֱ��: ";
            cin >> param1;
            cout << "�����뵥λ (c:����, i:Ӣ��): ";
            cin >> unit;

            Circle circle(param1, unit);
            double area = circle.calculateArea();

            printResult("Բ��", param1, 0, area, unit);
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

// ��ӡ���������ʵ��
void printResult(const string& shape, double param1, double param2, double area, char unit) {
    cout << "\n------------------------------------" << endl;
    cout << "��ѡ���ͼ����: " << shape << endl;

    if (shape == "������" || shape == "Բ��") {
        cout << "������ı߳�/ֱ����: " << param1 << " " << ((unit == 'i') ? "Ӣ��" : "����") << endl;
    }
    else {
        cout << "������ĳ��ȺͿ��/����: " << param1 << " �� " << param2 << " " << ((unit == 'i') ? "Ӣ��" : "����") << endl;
    }

    cout.precision(3);
    cout << "�������: " << fixed << area << " ƽ������" << endl;
    cout << "------------------------------------" << endl;
}
