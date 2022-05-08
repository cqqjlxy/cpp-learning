#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
  int m_A;
  int m_B;

  void func() {}  //成员函数并不属于类的对象上

  static int m_C;  //静态的成员变量也不属于类对象上

  //只有非静态的成员变量属于类的对象上
  double m_D;
};
int Person::m_C = 0;
void test01() {
  //空类的sizeof结果是1 原因
  //每个对象都应该在哪存上有独一无二的地址，因此给空类分配1个字节的空间
  Person p1;

  cout << "sizeof = " << sizeof(p1) << endl;
}

int main() {
  test01();
  return EXIT_SUCCESS;
}