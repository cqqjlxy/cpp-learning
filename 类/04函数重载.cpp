//同一个函数名在不同的语境下可以有不同的意义
#include <iostream>
using namespace std;

//函数重载条件
// 1、在同一个作用域（不同作用域的同一函数名的函数不需要函数重载）
// 2、函数名称相同
// 3、函数参数数量，顺序，类型不同

void func(int a, int b) { cout << "func()调用" << endl; }

void func(int a) { cout << "func(int a)调用" << endl; }

int func(int a, double b) {}
// c++中允许函数名相同，所需要参数不同的函数重载
//返回值可不可以作为函数重载的条件？
//无法区分 仅用 返回值区分的重载函数 但是可以用参数来区分
void test01() { func(1, 2); }

//函数重载中引用的两个版本
void myFunc(int &a) { cout << "myFunc(int &a)调用" << endl; }

void myFunc(const int &a) { cout << "myFunc(const int &a)调用" << endl; }

void test02() {
  int a = 10;
  myFunc(a);
  myFunc(10);  //需要避免二义性的出现
}

//函数重载碰到默认参数时也要注意避免二义性的出现
void func2(int a) {}

void func2(int a, int b = 10) {}
void test03() {
  // func2(10) //出现二义性
}

int main() {
  // test01();
  // test02();
  test03();
  return EXIT_SUCCESS;
}