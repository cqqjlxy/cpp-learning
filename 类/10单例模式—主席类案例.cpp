#include <iostream>
#include <string>

using namespace std;
//主席类
class ChairMan {
 public:
  static ChairMan* getInstance() { return singleMan; }

 private:
  //将构造函数私有化，不可以创建多个对象
  ChairMan() {}
  static ChairMan* singleMan;  //类内声明，类外初始化 对外提供只读接口
  ChairMan(const ChairMan* c) {}
};

ChairMan* ChairMan::singleMan = new ChairMan;  //利用作用域来访问private的内容

void test01() {
  /*
  ChairMan c1;
  ChairMan c2;
  ChairMan* c3 = new ChairMan;
  */
  /*
   ChairMan* c1 = ChairMan::singleMan;
   ChairMan* c2 = ChairMan::singleMan;
   */
  // c1 = c2
  ChairMan* c1 = ChairMan::getInstance();  //提供只读的权限

  ChairMan* c3 = new ChairMan(
      *c1);  //若是直接通过拷贝构造函数来构造，则c3和c1并不相等，不是单例模式了
}

int main() {
  test01();
  return EXIT_SUCCESS;
}