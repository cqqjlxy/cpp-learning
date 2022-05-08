#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
  Person(int age) {
    // age = age;
    this->age = age; //this指针指向被调用的成员函数所属的对象
  }
  //this指针用途：
  //1、解决名称的冲突
  //this指针 隐式 加在每个成员函数中

  int age;
};

void test01() {
  Person p1(18);

  cout << "p1的年龄为: " << p1.age << endl;
}

int main() {
  test01();
  return EXIT_SUCCESS;
}