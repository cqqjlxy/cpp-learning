/*
  2．	采用动态内存分配的方式，以最节省的方式存储m个长度不同的字符串的存储。
  完成字符串输入输出，程序退出时释放全部动态内存。
  动态二维数组列数不固定，根据输入的字符串长度动态分配内存。
*/

#include <cstring>
#include <iostream>

using namespace std;

int main() {
  string a, b, c;
  cout << "请输入三个字符串：" << endl;
  cin >> a >> b >> c;
  int la, lb, lc;
  la = a.length();
  lb = b.length();
  lc = c.length();  //获取输入的三个字符串的长度

  char** char1 = new char*[3];  //首先分配三行的空间
  *(char1) = new char[la + 1];  //分配列的空间，+1留出'\0'
  *(char1 + 1) = new char[lb + 1];
  *(char1 + 2) = new char[lc + 1];
  strcpy(*(char1), a.c_str());
  strcpy(*(char1 + 1), b.c_str());
  strcpy(*(char1 + 2), c.c_str());
  //确定字符串里面
  //假设存储三个长度不同的字符串
  cout << *(char1) << endl << *(char1 + 1) << endl << *(char1 + 2) << endl;

  return 0;
}