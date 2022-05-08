#include <iostream>
using namespace std;

class MyString {
 public:
  MyString(char* str) {}

  explicit MyString(int len) {}
};

void test01() {
  MyString str("abcd");

  MyString str2(10);

  // MyString str3 = 10; //explicit用途： 防止利用隐式类型转换的方式来构造对象
}

int main() {
  test01();

  return EXIT_SUCCESS;
}

/*

#include <iostream>
#include <string>

using namespace std;

void test01() {

}

int main() {
  test01();

  return EXIT_SUCCESS;
}
*/