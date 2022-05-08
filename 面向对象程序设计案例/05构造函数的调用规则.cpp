#include <iostream>
using namespace std;

//编译器会给一个类 至少要添加3个函数
//默认构造 拷贝构造 析构
//如果自己提供了有参构造函数 编译器就不会提供默认构造函数
//但是依然会提供拷贝构造函数
//如果自己提供了拷贝构造函数，编译器不会提供任何其他的构造函数

class Person {
 public:
  Person() { cout << "默认构造函数的调用" << endl; }

  Person(int age) {
    cout << "有参构造函数的调用" << endl;
    m_Age = age;
  }

  Person(const Person &p) {
    cout << "拷贝构造函数的调用" << endl;
    m_Age = p.m_Age;
  }

  ~Person() { cout << "析构" << endl; }
  int m_Age;
};

void test01() {
  Person p1;
  p1.m_Age = 20;

  Person p2(p1);

  cout << p2.m_Age << endl;
}