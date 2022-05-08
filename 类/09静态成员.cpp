#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
  //静态成员变量：编译阶段就分配了内存
  //类内声明、类外初始化
  static int m_A;

  // 2、静态成员函数
  //所有对象都共享同一个func函数
  //静态的成员函数能访问静态成员变量 但是 不能 访问非静态成员变量
  static void func() { cout << "func的调用" << endl; }

 private:
  static int m_B;
  //静态成员变量也是有访问权限的，类外不能访问
};
int Person::m_A = 0;
int Person::m_B = 0;

void test01() {
  //通过对象进行访问
  Person p1;
  cout << p1.m_A << endl;

  Person p2;
  p2.m_A = 100;
  cout << p1.m_A << endl;
  // 2、通过类名进行访问

  cout << Person::m_A << endl;

  //通过对象调用静态对象函数
  p1.func();
  //通过类名调用静态对象函数
  Person::func();
}

int main() {
  test01();
  return EXIT_SUCCESS;
}