//设计一个类，求圆的周长
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const double PI = 3.14;
// class + 类名
//周长的公式： 2 * pi * m_R
class Circle {
 public:  //公共权限
  //类中的函数称为 成员函数 或 成员方法
  //类中的变量称为 成员变量 或 成员属性
  //求圆周长
  double calculateC() { return 2 * PI * m_R; }

  //设置半径
  void setR(int r) { m_R = r; }

  //获取半径
  int getR() { return m_R; }

  //半径
  int m_R;
};

void test01() {
  Circle c1;  //通过类创建一个对象（实例化对象）

  //给c1半径赋值
  // c1.m_R = 10;
  c1.setR(10);

  //求c1圆的周长
  cout << "圆的周长为： " << c1.calculateC() << endl;
}

int main() {
  test01();

  return EXIT_SUCCESS;
}