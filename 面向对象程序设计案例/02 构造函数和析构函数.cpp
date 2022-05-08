#include <iostream>
using namespace std;

class Person {
 public:  //构造和析构函数必须要声明在全局的作用域下
  //构造函数
  //没有返回值  不用写void
  //函数名 与 类名相同
  //可以有参数，可以发生重载
  //构造函数由编译器自动调用一次，无须手动调用

  Person() { cout << "Person构造函数调用" << endl; }

  //析构函数 主要做清理工作
  //没有返回值，不需要写void
  //函数名与类名相同 函数的名称前加 ～
  //不可以有参数，不可以发生重载
  //析构函数也是编译器自动调用一次，无须手动调用
  ~Person() { cout << "Person的析构函数调用" << endl; }
};

void test01() { Person p; }

int main() {
  test01();

  Person p;
  cout << 1 << endl;

  return EXIT_SUCCESS;
}