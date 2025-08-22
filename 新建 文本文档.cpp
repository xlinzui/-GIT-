#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string>

// 前置声明，确保编译器识别Shape类
class Shape;

// 抽象图形基类：定义统一接口
class Shape {
public:
    // 纯虚函数：计算面积（子类必须实现）
    virtual double calculateArea() const = 0;
    // 纯虚函数：获取用户输入的尺寸
    virtual void inputSize(int unitChoice) = 0;
    // 纯虚函数：输出图形信息与计算结果
    virtual void printResult() const = 0;

    // 静态工具函数：英寸转厘米（1英寸 = 2.54厘米）
    static double inchesToCm(double inches) {
        return inches * 2.54;
    }

    // 虚析构函数
    virtual ~Shape() = default;
};

// 正方形子类
class Square : public Shape {
private:
    double side;  // 边长（厘米）

public:
    void inputSize(int unitChoice) override {
        double input;
        while (true) {
            std::cout << "├─ 请输入正方形的边长：";
            if (std::cin >> input && input > 0) {
                side = (unitChoice == 2) ? inchesToCm(input) : input;
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "│  输入错误！请重新输入正数（如 5、3.8）\n";
        }
    }

    double calculateArea() const override {
        return side * side;
    }

    void printResult() const override {
        std::cout << "├─ 图形类型：正方形\n";
        std::cout << "├─ 边长：" << std::fixed << std::setprecision(3) << side << " 厘米\n";
        std::cout << "└─ 面积：" << std::fixed << std::setprecision(3) << calculateArea() << " 平方厘米\n";
    }
};

// 长方形子类
class Rectangle : public Shape {
private:
    double length, width;  // 长、宽（厘米）

public:
    void inputSize(int unitChoice) override {
        // 输入长度
        while (true) {
            std::cout << "├─ 请输入长方形的长度：";
            if (std::cin >> length && length > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "│  输入错误！请重新输入正数（如 5、3.8）\n";
        }
        // 输入宽度
        while (true) {
            std::cout << "├─ 请输入长方形的宽度：";
            if (std::cin >> width && width > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "│  输入错误！请重新输入正数（如 5、3.8）\n";
        }
        // 单位转换
        if (unitChoice == 2) {
            length = inchesToCm(length);
            width = inchesToCm(width);
        }
    }

    double calculateArea() const override {
        return length * width;
    }

    void printResult() const override {
        std::cout << "├─ 图形类型：长方形\n";
        std::cout << "├─ 长×宽：" << std::fixed << std::setprecision(3) << length 
                  << " × " << width << " 厘米\n";
        std::cout << "└─ 面积：" << std::fixed << std::setprecision(3) << calculateArea() << " 平方厘米\n";
    }
};

// 三角形子类
class Triangle : public Shape {
private:
    double base, height;  // 底、高（厘米）

public:
    void inputSize(int unitChoice) override {
        // 输入底
        while (true) {
            std::cout << "├─ 请输入三角形的底：";
            if (std::cin >> base && base > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "│  输入错误！请重新输入正数（如 5、3.8）\n";
        }
        // 输入高
        while (true) {
            std::cout << "├─ 请输入三角形的高：";
            if (std::cin >> height && height > 0) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "│  输入错误！请重新输入正数（如 5、3.8）\n";
        }
        // 单位转换
        if (unitChoice == 2) {
            base = inchesToCm(base);
            height = inchesToCm(height);
        }
    }

    double calculateArea() const override {
        return (base * height) / 2.0;
    }

    void printResult() const override {
        std::cout << "├─ 图形类型：三角形\n";
        std::cout << "├─ 底：" << std::fixed << std::setprecision(3) << base 
                  << " 厘米，高：" << height << " 厘米\n";
        std::cout << "└─ 面积：" << std::fixed << std::setprecision(3) << calculateArea() << " 平方厘米\n";
    }
};

// 圆形子类
class Circle : public Shape {
private:
    double diameter;  // 直径（厘米）

public:
    void inputSize(int unitChoice) override {
        double input;
        while (true) {
            std::cout << "├─ 请输入圆形的直径：";
            if (std::cin >> input && input > 0) {
                diameter = (unitChoice == 2) ? inchesToCm(input) : input;
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "│  输入错误！请重新输入正数（如 5、3.8）\n";
        }
    }

    double calculateArea() const override {
        double radius = diameter / 2.0;
        return M_PI * radius * radius;
    }

    void printResult() const override {
        std::cout << "├─ 图形类型：圆形\n";
        std::cout << "├─ 直径：" << std::fixed << std::setprecision(3) << diameter << " 厘米\n";
        std::cout << "└─ 面积：" << std::fixed << std::setprecision(3) << calculateArea() << " 平方厘米\n";
    }
};

// 工具函数：获取用户有效选择
int getValidChoice(const std::string& title, const std::string& options, int min, int max) {
    int choice;
    while (true) {
        std::cout << "\n========================================\n";
        std::cout << " " << title << "\n";
        std::cout << "========================================\n";
        std::cout << options;
        std::cout << "├─ 请输入选择（" << min << "-" << max << "）：";
        
        if (std::cin >> choice && choice >= min && choice <= max) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "│  输入无效！请输入" << min << "-" << max << "之间的整数\n";
    }
    return choice;
}

int main() {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "欢迎使用 图形面积计算器 V1.0\n";

    // 选择图形类型
    int shapeChoice = getValidChoice(
        "第一步：选择图形类型",
        "├─ 1. 正方形\n├─ 2. 长方形\n├─ 3. 三角形\n├─ 4. 圆形\n",
        1, 4
    );

    // 选择输入单位
    int unitChoice = getValidChoice(
        "第二步：选择输入单位",
        "├─ 1. 厘米（cm）\n├─ 2. 英寸（in）\n",
        1, 2
    );
    std::cout << "\n========================================\n";
    std::cout << "  第三步：输入图形尺寸（" << (unitChoice == 1 ? "厘米" : "英寸") << "）\n";
    std::cout << "========================================\n";

    // 修复指针声明方式，确保编译器正确识别
    Shape* shape = 0;  // 使用0代替nullptr，兼容更多编译器
    switch (shapeChoice) {
        case 1: shape = new Square();    break;
        case 2: shape = new Rectangle(); break;
        case 3: shape = new Triangle();  break;
        case 4: shape = new Circle();    break;
    }

    // 执行核心逻辑
    if (shape != 0) {  // 同样使用0进行判断
        shape->inputSize(unitChoice);
        std::cout << "\n========================================\n";
        std::cout << "  计算结果（单位统一转换为厘米）\n";
        std::cout << "========================================\n";
        shape->printResult();
        delete shape;
        shape = 0;
    } else {
        std::cout << "\n│  程序异常：图形对象创建失败\n";
        return 1;
    }

    // 结束提示
    std::cout << "\n========================================\n";
    std::cout << "  计算完成！感谢使用\n";
    std::cout << "========================================\n";
    return 0;
}

