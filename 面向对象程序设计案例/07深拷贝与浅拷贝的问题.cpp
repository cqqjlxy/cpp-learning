#include <iostream>
using namespace std;

class Person {
 public:
  Person(char* name, int age) {
    m_Name = (char*)malloc(strlen(name) + 1);

    strcpy(m_Name, name);

    m_Age = age;
  }

  ~Person() {
    if (m_Name != NULL) {
      free(m_Name);
      m_Name = NULL;
    }
  }
  //简单的值拷贝带来的内存重复释放
  Person(const Person& p) {
    m_Name = (char*)malloc(strlen(p.m_Name) + 1);
    strcpy(m_Name, p.m_Name);
    m_Age = p.m_Age;
  }

  char* m_Name;  //姓名
  int m_Age;     //年龄
};

void test01() {
  Person p("smith", 18);
  cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;

  Person p2(p);
  cout << "name: " << p2.m_Name << " age: " << p2.m_Age << endl;
}

int main() {
  test01();

  return EXIT_SUCCESS;
}