#include <iostream>
using namespace std;

struct Person {
  char name[64];
  int age;

  void PersonEat() { cout << "PersonEat" << endl; }
};
// c++可以将属性的行为封装到一起

class Person {
 public:
  char name[64];
  int age1;

  void PersonEat();
};
void test01() {
  struct Person p1;
  p1.age1 = 2;
  Person p2;
}
// struct和class区别？
// class默认权限 私有权限 而struct的默认权限是 公共权限
//访问权限
// public 公共权限  类内 类外 都可以访问
// private 私有权限  类内可以访问 类外不可以访问
// protected 保护权限 类内可以访问 类外不可以访问

int main() {
  test01();

  return EXIT_SUCCESS;
  ;
}