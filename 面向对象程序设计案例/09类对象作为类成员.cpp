#include <iostream>
#include <string>

using namespace std;

class Phone {
 public:
  Phone(string pName) {
    m_PhoneName = pName;
    cout << "Phone的有参构造函数调用" << endl;
  }

  ~Phone() { cout << "Phone的析构函数调用" << endl; }

  string m_PhoneName;
};

class Game {
 public:
  Game(string gName) {
    m_GameName = gName;
    cout << "Game的有参构造函数调用" << endl;
  }

  ~Game() { cout << "Game的析构函数调用" << endl; }

  string m_GameName;
};

class Person {
 public:
  Person(string name, string pName, string gName)
      : m_Name(name), m_Phone(pName), m_Game(gName) {
    cout << "Person的有参构造函数调用" << endl;
  }

  ~Person() { cout << "Person的析构函数调用" << endl; }

  string m_Name;
  Phone m_Phone;
  Game m_Game;
};

void test01() { Person p("张三", "iPhone", "王者"); }

int main() {
  test01();

  return EXIT_SUCCESS;
}
/*
Phone的有参构造函数调用
Game的有参构造函数调用
Person的有参构造函数调用
Person的析构函数调用
Game的析构函数调用
Phone的析构函数调用
*/
//注意顺序