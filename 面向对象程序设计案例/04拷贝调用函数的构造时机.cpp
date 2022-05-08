#include <iostream>
using namespace std;

class Person {
 public:
  Person() { cout << "Person的构造函数调用" << endl; }

  Person(int a) {
    m_Age = a;
    cout << "Person的有参数构造函数调用" << endl;
  }

  Person(string) { cout << "Person的有参数int构造函数调用" << endl; }

  //拷贝构造函数
  Person(const Person &p) {
    m_Age = p.m_Age;
    cout << "Person的拷贝构造函数调用" << endl;
  }

  //析构
  ~Person() { cout << "Person的析构函数调用" << endl; }
  int m_Age;
};

// 1、用已经创建好了的对象来初始化新的对象
void test01() {
  Person p1(18);

  Person p2(p1);

  cout << "p2的年龄：" << p2.m_Age << endl;
}

// 2、用值传递的方式 给函数参数传值
void doWork(Person p) {}

void test02() {
  Person p1(100);

  doWork(p1);
}

// 3、以值的方式来返回局部对象
Person doWork2() {
  Person p;
  return p;
}

void test03() { Person p = doWork2(); }

int main() {
  // test01();
  // test02();
  test03();

  return EXIT_SUCCESS;
}