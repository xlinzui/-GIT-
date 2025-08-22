#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string>

// ǰ��������ȷ��������ʶ��Shape��
class Shape;

// ����ͼ�λ��ࣺ����ͳһ�ӿ�
class Shape {
public:
    // ���麯��������������������ʵ�֣�
    virtual double calculateArea() const = 0;
    // ���麯������ȡ�û�����ĳߴ�
    virtual void inputSize(int unitChoice) = 0;
    // ���麯�������ͼ����Ϣ�������
    virtual void printResult() const = 0;

    // ��̬���ߺ�����Ӣ��ת���ף�1Ӣ�� = 2.54���ף�
    static double inchesToCm(double inches) {
        return inches * 2.54;
    }

    // ����������
    virtual ~Shape() = default;
};

// ����������
class Square : public Shape {
private:
    double side;  // �߳������ף�

public:
    void inputSize(int unitChoice) override {
        double input;
        while (true) {
            std::cout << "���� �����������εı߳���";
            if (std::cin >> input && input > 0) {
                side = (unitChoice == 2) ? inchesToCm(input) : input;
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "��  ������������������������� 5��3.8��\n";
        }
    }

    double calculateArea() const override {
        return side * side;
    }

    void printResult() const override {
        std::cout << "���� ͼ�����ͣ�������\n";
        std::cout << "���� �߳���" << std::fixed << std::setprecision(3) << side << " ����\n";
        std::cout << "���� �����" << std::fixed << std::setprecision(3) << calculateArea() << " ƽ������\n";
    }
};

// ����������
class Rectangle : public Shape {
private:
    double length, width;  // ���������ף�

public:
    void inputSize(int unitChoice) override {
        // ���볤��
        while (true) {
            std::cout << "���� �����볤���εĳ��ȣ�";
            if (std::cin >> length && length > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "��  ������������������������� 5��3.8��\n";
        }
        // ������
        while (true) {
            std::cout << "���� �����볤���εĿ�ȣ�";
            if (std::cin >> width && width > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "��  ������������������������� 5��3.8��\n";
        }
        // ��λת��
        if (unitChoice == 2) {
            length = inchesToCm(length);
            width = inchesToCm(width);
        }
    }

    double calculateArea() const override {
        return length * width;
    }

    void printResult() const override {
        std::cout << "���� ͼ�����ͣ�������\n";
        std::cout << "���� ������" << std::fixed << std::setprecision(3) << length 
                  << " �� " << width << " ����\n";
        std::cout << "���� �����" << std::fixed << std::setprecision(3) << calculateArea() << " ƽ������\n";
    }
};

// ����������
class Triangle : public Shape {
private:
    double base, height;  // �ס��ߣ����ף�

public:
    void inputSize(int unitChoice) override {
        // �����
        while (true) {
            std::cout << "���� �����������εĵף�";
            if (std::cin >> base && base > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "��  ������������������������� 5��3.8��\n";
        }
        // �����
        while (true) {
            std::cout << "���� �����������εĸߣ�";
            if (std::cin >> height && height > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "��  ������������������������� 5��3.8��\n";
        }
        // ��λת��
        if (unitChoice == 2) {
            base = inchesToCm(base);
            height = inchesToCm(height);
        }
    }

    double calculateArea() const override {
        return (base * height) / 2.0;
    }

    void printResult() const override {
        std::cout << "���� ͼ�����ͣ�������\n";
        std::cout << "���� �ף�" << std::fixed << std::setprecision(3) << base 
                  << " ���ף��ߣ�" << height << " ����\n";
        std::cout << "���� �����" << std::fixed << std::setprecision(3) << calculateArea() << " ƽ������\n";
    }
};

// Բ������
class Circle : public Shape {
private:
    double diameter;  // ֱ�������ף�

public:
    void inputSize(int unitChoice) override {
        double input;
        while (true) {
            std::cout << "���� ������Բ�ε�ֱ����";
            if (std::cin >> input && input > 0) {
                diameter = (unitChoice == 2) ? inchesToCm(input) : input;
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "��  ������������������������� 5��3.8��\n";
        }
    }

    double calculateArea() const override {
        double radius = diameter / 2.0;
        return M_PI * radius * radius;
    }

    void printResult() const override {
        std::cout << "���� ͼ�����ͣ�Բ��\n";
        std::cout << "���� ֱ����" << std::fixed << std::setprecision(3) << diameter << " ����\n";
        std::cout << "���� �����" << std::fixed << std::setprecision(3) << calculateArea() << " ƽ������\n";
    }
};

// ���ߺ�������ȡ�û���Чѡ��
int getValidChoice(const std::string& title, const std::string& options, int min, int max) {
    int choice;
    while (true) {
        std::cout << "\n========================================\n";
        std::cout << " " << title << "\n";
        std::cout << "========================================\n";
        std::cout << options;
        std::cout << "���� ������ѡ��" << min << "-" << max << "����";
        
        if (std::cin >> choice && choice >= min && choice <= max) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "��  ������Ч��������" << min << "-" << max << "֮�������\n";
    }
    return choice;
}

int main() {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "��ӭʹ�� ͼ����������� V1.0\n";

    // ѡ��ͼ������
    int shapeChoice = getValidChoice(
        "��һ����ѡ��ͼ������",
        "���� 1. ������\n���� 2. ������\n���� 3. ������\n���� 4. Բ��\n",
        1, 4
    );

    // ѡ�����뵥λ
    int unitChoice = getValidChoice(
        "�ڶ�����ѡ�����뵥λ",
        "���� 1. ���ף�cm��\n���� 2. Ӣ�磨in��\n",
        1, 2
    );
    std::cout << "\n========================================\n";
    std::cout << "  ������������ͼ�γߴ磨" << (unitChoice == 1 ? "����" : "Ӣ��") << "��\n";
    std::cout << "========================================\n";

    // �޸�ָ��������ʽ��ȷ����������ȷʶ��
    Shape* shape = 0;  // ʹ��0����nullptr�����ݸ��������
    switch (shapeChoice) {
        case 1: shape = new Square();    break;
        case 2: shape = new Rectangle(); break;
        case 3: shape = new Triangle();  break;
        case 4: shape = new Circle();    break;
    }

    // ִ�к����߼�
    if (shape != 0) {  // ͬ��ʹ��0�����ж�
        shape->inputSize(unitChoice);
        std::cout << "\n========================================\n";
        std::cout << "  ����������λͳһת��Ϊ���ף�\n";
        std::cout << "========================================\n";
        shape->printResult();
        delete shape;
        shape = 0;
    } else {
        std::cout << "\n��  �����쳣��ͼ�ζ��󴴽�ʧ��\n";
        return 1;
    }

    // ������ʾ
    std::cout << "\n========================================\n";
    std::cout << "  ������ɣ���лʹ��\n";
    std::cout << "========================================\n";
    return 0;
}

