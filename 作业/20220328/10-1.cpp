/*
  二维坐标体系中的一条线段可以通过两个端点的坐标(x1, y1)和(x2, y2)来描述。
  定义一个“线段”类(Line)，其数据成员为两个端点坐标，成员函数包括：
  (1)void setPoint1(int, int); 设置第一个点的坐标。
  (2)void setPoint2(int, int); 设置第二个点的坐标。
  (3)void getPoint1(int *, int *); 获取第一个点的坐标，指针作为参数。
  (4)void getPoint1(int &, int &); 获取第二个点的坐标，引用作为参数。
  (5)void outputTwoPoint(); 输出两个端点的坐标。
  (6)double length(); 求出线段的长度
  请编写完整的程序，并在主函数中完成上述所有成员函数的测试工作。
*/

#include <cmath>
#include <iostream>

#define square(a) ((a) * (a))  //定义求一个数的平方写起来方便点

using namespace std;

class Line {
 public:
  //设置两个点的坐标
  void setPoint1(int x, int y) {
    m_p1x = x;
    m_p1y = y;
  }

  void setPoint2(int x, int y) {
    m_p2x = x;
    m_p2y = y;
  }

  //获取第一个点的坐标，传入的指针来保存结果
  void getPoint1(int *px, int *py) {
    *px = m_p1x;
    *py = m_p1y;
  }

  //获取第二个点的坐标，传入引用参数来保存结果
  void getPoint2(int &x, int &y) {
    x = m_p2x;
    y = m_p2y;
  }

  //输出两个端点的坐标，引用调用来输出结果
  void outputTwoPoint() {
    cout << "第一个点的坐标为: (" << m_p1x << ", " << m_p1y << "), "
         << "第二个点的坐标为: (" << m_p2x << ", " << m_p2y << ")" << endl;
  }

  //求出线段的长度
  double length() {
    return sqrt(square(m_p1x - m_p2x) + square(m_p1y - m_p2y));
  }

 private:
  int m_p1x, m_p1y, m_p2x, m_p2y;
};

int main() {
  int p1x = 0, p1y = 0, p2x = 0, p2y = 0;
  Line l1;
  cout << "请输入第一个点的横坐标: ";
  cin >> p1x;
  cout << "请输入第一个点的纵坐标: ";
  cin >> p1y;

  cout << "请输入第二个点的横坐标: ";
  cin >> p2x;
  cout << "请输入第二个点的纵坐标: ";
  cin >> p2y;

  //测试setPoint函数
  l1.setPoint1(p1x, p1y);
  l1.setPoint2(p2x, p2y);

  //测试getPoint函数
  //设置四个变量来获取坐标
  int _p1x, _p1y;
  int _p2x, _p2y;
  l1.getPoint1(&_p1x, &_p1y);
  l1.getPoint2(_p2x, _p2y);

  cout << "用getPoint函数获取到的两个点的坐标分别为: "
       << "(" << _p1x << ", " << _p1y << ")"
       << ", "
       << "(" << _p2x << ", " << _p2y << ")" << endl;

  //测试outputTwoPoin函数
  l1.outputTwoPoint();

  //测试length函数
  cout << "线段的长度为: " << l1.length() << endl;

  return EXIT_SUCCESS;
}