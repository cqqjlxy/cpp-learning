#include <iostream>
using namespace std;

class Person {
 public:
  Person(int a, int b, int c) {
    m_A = a;
    m_B = b;
    m_C = c;
  }
  int m_A;
  int m_B;
  int m_C;

  Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}
};

void test01() {
  Person p(10, 20, 30);

  cout << p.m_A;
}