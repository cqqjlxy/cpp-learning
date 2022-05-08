/*
1）	跟踪p1.fun()和p2.fun()所调用的函数
2）	注释掉函数int Point::fun()的定义;再次跟踪p1.fun()所调用的函数
*/
/*
  结论：
  p1优先调用没有const修饰的函数，只有const修饰的函数存在时，也可以调用const修饰的函数
  而p2作为一个常对象只能调用有const修饰的函数。
*/
#include <iostream>
using namespace std;

class Point {
  int x;
  const int y;

 public:
  Point(int a = 0, int b = 0) : x(a), y(b) {}
  // int fun();
  int fun() const;  // 类中声明有const
};
// int Point::fun() { return x + y; }

int Point::fun() const  // 类外定义也必须有const
{
  return x - y;
}

int main() {
  Point p1(1, 8);
  const Point p2(1, 8);
  cout << p1.fun() << ',';  //若只定义了常成员函数则调常成员函数
  cout << p2.fun() << endl;

  return 0;
}
