#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
  //设置姓名
  void setName(string name) { m_Name = name; }

  //获取姓名
  string getName() { return m_Name; }

  //获取年龄
  int getAge() { return m_Age; }

  //设置情人
  void setLover(string lover) { m_Lover = lover; }

  //设置年龄
  void setAge(int age) {
    if (age < 0 || age > 150) {
      cout << "error" << endl;
    }
    m_Age = age;
  }

 private:
  string m_Name;   //姓名  可读可写
  int m_Age;       //年龄  可读 可写（0～150）
  string m_Lover;  //情人  只写
};

void test01() {
  Person p;
  p.setName("张三");
  //可以将char* 类型隐式转换为string
  p.setAge(1000);
}

//将成员都设置成私有的好处：可以自己控制访问权限
//可以对设置的内容加有效性验证

int main() {
  test01();
  return EXIT_SUCCESS;
}