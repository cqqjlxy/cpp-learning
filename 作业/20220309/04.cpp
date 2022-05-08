/*
  4．假设定义了如下描述学生信息的结构类型：
  struct  student   //定义结构体类型
  {   int num;    学号
      char name*; 姓名
      int age;    年龄
      char sex;   性别
      int score;  成绩
  };
1）	编写程序，main函数中进行动态内存，创建一个动态结构数组，并录入学生信息
2）	调用函数void Sort(student  *ps,int n)对结构数组按照学生成绩排序
3）	main函数调用函数并输出排序后的结构数组
4）	程序退出时释放全部动态内存。
注意结构中的name指针也需要进行动态内存分配和释放
*/

#include <iostream>
using namespace std;

struct student {
  int num;     //学号
  char* name;  //姓名
  int age;     //年龄
  char sex;    //性别
  int score;   //成绩
};

void Sort(student* ps, int n) {
  student* temp;
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if ((ps + j)->score > (ps + j + 1)->score) {
        student **temp1, **temp2;
        *temp1 = ps + j;
        *temp2 = ps + j + 1;
        temp = (ps + j);
        *temp1 = *temp2;
        *temp2 = temp;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  cout << "请依次输入学号，姓名，年龄，性别，成绩：" << endl;
  student* stud = new student[n];
  for (int i = 0; i < n; i++) {
    cin >> (stud + i)->num >> (stud + i)->name >> (stud + i)->age >>
        (stud + i)->sex >> (stud + i)->score;
  }
  Sort(stud, n);
  for (int i = 0; i < n; i++) {
    cout << (stud + i)->num << endl
         << (stud + i)->name << endl
         << (stud + i)->age << endl
         << (stud + i)->sex << endl
         << (stud + i)->score << endl
         << endl
         << endl;
  }

  delete[] stud;
  return 0;
}