/*
  10-5
  对上一题增加构造函数：
  (1）增加定义缺省构造函数：
      Student(char * Name = NULL, char * Num = NULL,
      int Math = 0, int English = 0, int Physics = 0, int Cpp =0);
  完成对类中所有私有数据成员的初始化，需动态分配“学号”的存储空间。
  提示：本函数的参数与数据成员同名，为了区分参数和数据成员，解决办法有两种，一是
  在成员名前加 “this->”，二是在成员名前加类名限定（本题类名限定为 Student::）。
  (2）增加定义拷贝构造函数 Student (Student &)。
  提示：需要为“学号”动态分配空间，实现“深”拷贝，
  (3）增加定义析构函数~Student(），释放“学号”动态空间。
  在主函数中完成对所有构造函数和析构函数的测试工作。
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

  //缺省构造函数
  Student(char* Name = NULL, char* Num = NULL, int Math = 0, int English = 0,
          int Physics = 0, int Cpp = 0) {
    if (Name == NULL) {
      this->Name[0] = '\0';
    } else {
      strcpy(this->Name, Name);
    }
    this->Num = Num;
    this->Math = Math;
    this->English = English;
    this->Physics = Physics;
    this->Cpp = Cpp;
  }

  //拷贝构造函数
  Student(Student& src) {
    strcpy(Name, src.Name);
    Num = new char[strlen(src.Num) + 1];
    strcpy(Num, src.Num);
    Math = src.Math;
    English = src.English;
    Physics = src.Physics;
    Cpp = src.Cpp;
  }

  //析构函数
  ~Student() { delete[] Num; }

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

  //测试缺省构造函数，测试成功输出”该对象构造为缺省“
  Student s2;
  s2.outputInfo();

  //测试拷贝构造函数
  Student s3(s1);
  s3.outputInfo();

  return 0;
}
