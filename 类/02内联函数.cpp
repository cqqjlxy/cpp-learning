//设计一个类，求圆的周长
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//宏缺陷1:必须要加括号来保证运算的完整
#define MYADD(x, y) x + y

void test01() {
  int a = 10;
  int b = 20;
  int ret = MYADD(a, b) * 20;
  cout << ret;
}

//宏缺陷2 ：即使加了括号，有些运算结果依然与预期不符合

#define MYCOMPARE(a, b) a < b ? a : b

void test02() {
  int a = 10;
  int b = 20;

  int ret = MYCOMPARE(++a, b);  //预期是11
  //宏展开时： (++a) < b ? (++a)  : b

  cout << ret << endl;
}

//内联函数
//函数的声明和实现必须同时加关键字inline 才算是内联函数
//内联函数的好处 ：解决宏的缺陷，本身是一个函数，带来宏的优势，在适当的时候展开
//任何在类里面的成员函数自动过定义为内联函数
//除非：
//  1、写了任何形式的循环函数   2、存在过多的条件判断   3、函数过于庞大
//  4、对函数进行了取址操作
//内联只是给编译器一个建议，编译器不一定处理。
int main() {
  // test01();
  test02();

  return EXIT_SUCCESS;
}