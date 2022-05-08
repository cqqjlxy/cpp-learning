#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//默认参数语法 形参 类型 变量 = 默认值
//如果一个位置有了默认参数，那么从这个位置起从左到右都必须要有默认参数
int func(int a = 10, int b = 10) { return a + b; }
//函数的声明和实现不能同时提供默认参数

//占位参数
void func2(int a, int) {}
//只写一个类型进行占位，调用的时候必须要传入一个参数
//占位参数的用途？ 目前没用
void test01() { cout << func(10, 10) << endl; }

int main() {
  test01();

  return EXIT_SUCCESS;
}