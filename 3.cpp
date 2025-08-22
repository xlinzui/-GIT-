#include<iostream>
#include<iomanip>
#include<cmath>
#include<limits>
using namespace std;
void calculateTriangle();
void calculateCircle();
void displayMainMenu();
int main()
{ int choice;
    do {
        displayMainMenu();
        cout << "请选择操作 (1-3): ";
        cin >> choice;
        switch(choice) {
            case 1:
                calculateTriangle();
                break;
            case 2:
                calculateCircle();
                break;
            case 3:
                cout << "感谢使用面积计算器！再见！" << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
		void displayMainMenu() {
    cout << "\n==================================================" << endl;
    cout << "                   主菜单" << endl;
    cout << "==================================================" << endl;
    cout << "1. 计算三角形面积" << endl;
    cout << "2. 计算圆形面积" << endl;
    cout << "3. 退出程序" << endl;
    cout << "==================================================" << endl;
}
	void calculateTriangle(){
	cont<<"\n===== 计算三角形面积 ====="<<endl;
	double base; 
	cin>>base;
    double height;
	cin>>height;
	double area = 0.5 * base * height;
	cout << "图形类型: 三角形" << endl;
    cout << "底长: " << base << " cm" << unit << endl;
    cout << "高: " << height << " cm" << endl;
    cout << "面积: " << area << " cm²" << endl;

}
	void calculateCircle() {
    cout << "\n===== 计算圆形面积 =====" << endl;
    double diameter;
	cin>>diameter;
    double radius = diameter/2.0;
    double area = 3.14*radius*radius;
	 cout << "图形类型: 圆形" << endl;
    cout << "输入直径: " << diameter << " " << unit << endl;
    cout << "半径: " << radius << " cm" << endl;
    cout << "面积: " << area << " cm²" << endl;
}
}