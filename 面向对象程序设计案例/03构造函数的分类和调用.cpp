#include <iostream>
#include <string>
using namespace std;

//构造函数的分类
//按照参数分类： 无参构造 和 有参构造
//按照类型分类： 普通构造函数 拷贝构造函数
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

//构造函数的调用
void test01() {
  Person p;

  //括号法
  Person p5(10);
  //注意事项一
  //不要用括号法调用无参构造函数
  // Person p3();

  //显示法
  Person p3 = Person(10);  //有参构造
  Person p4 = Person(p3);  //拷贝构造
  //注意事项二
  //不要用拷贝构造函数 初始化

  //隐式类型转换法
  Person p6 = 10;  // Person p6 = Person(10);

  Person(10);  //匿名对象 特点：当前执行完毕后 立即释放
}
int main() {
  test01();
  Person p(18);
  Person p2(p);

  cout << "p2:" << p2.m_Age << endl;

  return EXIT_SUCCESS;
}