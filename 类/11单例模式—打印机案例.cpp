#include <iostream>
#include <string>

using namespace std;

class Printer {
 public:
  static Printer* getInstence() { return printer; }

  void printText(string text) {
    cout << text << endl;
    m_Count++;
  }

  int m_Count;

 private:
  Printer() { m_Count = 0; }
  Printer(const Printer& p) {}
  static Printer* printer;
};
Printer* Printer::printer = new Printer;
void test01() {
  Printer* p1 = Printer::getInstence();
  p1->printText("入职证明");
  p1->printText("离职证明");

  cout << "打印机的使用次数： " << p1->m_Count << endl;

  Printer* p2 = Printer::getInstence();
  p2->printText("调休申请");

  cout << "打印机的使用次数： " << p2->m_Count << endl;
}

int main() {
  test01();
  return EXIT_SUCCESS;
}