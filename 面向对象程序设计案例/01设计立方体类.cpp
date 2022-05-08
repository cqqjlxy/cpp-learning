#include <iostream>
using namespace std;
//设计立方体类，求出面积体积
//分别用全局函数和成员函数判断两个立方体是否相等
class Cube {
 public:
  //设置长宽高
  void setL(int l) { m_L = l; }

  void setW(int w) { m_W = w; }

  void setH(int h) { m_H = h; }

  //获取长宽高
  int getL() { return m_L; }

  int getW() { return m_W; }
  int getH() { return m_H; }

  //求面积
  int calculateS() { return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H; }

  int calculateV() { return m_L * m_W * m_H; }

  //利用成员函数判断两个立方体是否相等
  //只需要传递一个参数
  bool compareCubeByClass(Cube &c2) {
    return getL() == c2.getL() && getW() == c2.getW() && getH() == c2.getH();
  }

 private:
  int m_L;  //长
  int m_W;  //宽
  int m_H;  //高
};

//利用全局函数判断两个立方体是否相等
//引用传递提高代码的效率
bool compareCube(Cube &c1, Cube &c2) {
  if (c1.getL() == c2.getL() && c1.getW() == c2.getW() &&
      c1.getH() == c2.getH()) {
    return true;
  } else {
    return false;
  }
}
void test01() {
  Cube c1;
  c1.setL(10);
  c1.setW(10);
  c1.setH(10);

  cout << "c1的面积为：" << c1.calculateS() << endl;
  cout << "c1的体积为：" << c1.calculateV() << endl;

  Cube c2;
  c2.setL(10);
  c2.setW(10);
  c2.setH(10);
  bool ret = compareCube(c1, c2);
  if (ret) {
    cout << 1 << endl;
  } else {
    cout << 2 << endl;
  }
}

int main() {
  test01();
  return EXIT_SUCCESS;
}