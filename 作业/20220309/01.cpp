/*
  1．	创建动态大小的一维数组，调用函数用void Fill(int *pt,int n)
  用随机数填充该数组， 调用函数void Sort(int *pt,int n)
  对该数组排序，main函数调用函数并输出排序后的数组。 程序退出时释放动态内存。
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//利用随机数填充数组
void Fill(int *pt, int n) {
  for (int i = 0; i < n; i++) {
    *(pt + i) = (rand() % 20 + 1);  //填充20以内的整数
  }
}

//对数组进行排序
void Sort(int *pt, int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (*(pt + j) > *(pt + j + 1)) {
        temp = *(pt + j);
        *(pt + j) = *(pt + j + 1);
        *(pt + j + 1) = temp;
      }
    }
  }
}

int main() {
  srand((unsigned)time(NULL));
  //创建动态大小的随机数组，数组的大小每次随机取1-10的整数
  int n;
  n = (rand() % 10 + 1);
  int *pt = new int[n];

  Fill(pt, n);
  cout << "生成的数组为：" << endl;
  for (int i = 0; i < n; i++) {
    cout << *(pt + i) << endl;
  }

  Sort(pt, n);

  cout << "排序后的数组为：" << endl;
  for (int i = 0; i < n; i++) {
    cout << *(pt + i) << endl;
  }
  delete[] pt;
  return 0;
}