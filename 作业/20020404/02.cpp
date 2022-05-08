/*
  10-4
  定义一个描述学生基本情况的类(Student)，数据成员包括: 姓名(Name)、学号(Num)、
  数学（Math)、英语(English）、物理(Physics)和C++(Cpp)成绩，
  要求：用宇符数组实现“姓名”，用字符指针实现“学号”（动态分配存放学号字符串的存储空间)。
  课程成绩均为整型量。参见教材例 10.6
  成员函数包括：
  (1) void setNameNo(char * name, char * no);设置姓名和学号，注意需要给学号动态
      分配空间。
  (2) void setScores(int m, int e, int p, int c);设置4门课的成绩。
  (3) int total();求出并返回总成绩。
  (4) int average();求出并返回平均成绩，要求在本数中调用 total()函数。
  (5) void outputInfo();输出一个学生的全部数据，包括平均成绩，要求在本函数中调
      用 average()函数。
  请编写完整的程序，在主函数中完成上述成员函数(1)、(2)和(5)的测试工作。
  注意成员函数(3)和(4)的测试工作在其他成员函数内部完成。
*/

#include <cstring>
#include <iostream>

using namespace std;

class Student {
 public:
  void setNameNo(char* name, char* no) {  //设置姓名和学号，给学号动态分配空间
    strcpy(Name, name);
    Num = new char[strlen(no) + 1];  //申请动态空间
    strcpy(Num, no);
  }

  void setScores(int m, int e, int p, int c) {  //设置4门课的成绩
    Math = m;
    English = e;
    Physics = p;
    Cpp = c;
  }

  int total() {  //求总成绩
    int total;
    total = Math + English + Physics + Cpp;
    return total;
  }

  int average() {  //求平均成绩
    int average = total() / 4;
    return average;
  }

  void outputInfo() {  //输出学生的数据
    if (this->Num == NULL) {
      cout << "该对象构造为缺省" << endl;
      return;
    }
    cout << Name << endl
         << Num << endl
         << "数学: " << Math << endl
         << "英语: " << English << endl
         << "物理: " << Physics << endl
         << "C++: " << Cpp << endl
         << "平均分: " << average() << endl;
  }

 private:
  char Name[10];
  char* Num;
  int Math, English, Physics, Cpp;
};

int main() {
  Student s1;
  char name[10];
  char no[50];
  cout << "请输入姓名和学号: ";
  cin >> name >> no;
  s1.setNameNo(name, no);

  cout << "请依次输入数学、英语、物理、c++的分数: ";
  int m, e, p, c;
  cin >> m >> e >> p >> c;
  s1.setScores(m, e, p, c);

  cout << "求出的总成绩为: " << s1.total() << endl;
  cout << "求出的平均分为: " << s1.average() << endl;
  s1.outputInfo();

  return 0;
}
