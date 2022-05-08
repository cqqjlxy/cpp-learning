/*
  3.
  为线性表类定义一个友元函数，可以输出线性表中的数据，函数参数为线性表类的常对象引用或者常对象指针
*/
#include <iostream>

using namespace std;

class ListClass {
 private:
  int *ListPtr;  //指向线性表的指针
  int nLen;      //线性表的长度
  int nElem;     //线性表中当前元素的个数

 public:
  ListClass(int n = 10) {  //构造函数，线性表长度的缺省值为10
    nElem = 0;             //当前元素个数为0
    nLen = n;
    if (n) {  //当长度不为零时
      ListPtr = new int[n];
    } else {
      ListPtr = NULL;  //线性表长度为0，则指向空指针
    }
  }

  //拷贝构造函数
  ListClass(ListClass &L) {
    nLen = L.nLen;
    nElem = L.nElem;
    ListPtr = new int[nLen];
    for (int i = 0; i < nLen; i++) {
      ListPtr[i] = L.ListPtr[i];
    }
  }

  ~ListClass(void) {  //析构函数，释放线性表空间
    delete[] ListPtr;
  }

  int Elem(int);  //重载函数（1），在线性表末尾增加一个函数

  int &Elem(unsigned n) {  //重载函数（2），返回线性表下标为n的元素的引用
    return ListPtr[n];
  }

  int Elem(void) {  //重载函数（3），返回线性表中现有的元素个数
    return nElem;
  }

  int Len(void) {  //返回线性表的长度
    return nLen;
  }

  void GetElem(int i, int result) {
    //返回线性表下标为i的元素的值，flag保存是否查找成功
    if ((i >= 0) && (i < nElem)) {
      result = ListPtr[i];
    } else {
      cout << "下标越界" << endl;
    }
  }

  void Print(void);  //输出线性表中的所有元素，在类体外实现

  void Sort(void);  //排序成员函数，在类体外实现

  int Insert(
      int data,
      int n);  //在位置n处插入数据的成员函数，返回线性表现在的长度，在类体外实现

  friend void print1(const ListClass *list);  //常对象指针
  friend void print2(const ListClass &list);  //常对象引用
};

//重载函数（1），在线性表末尾增加一个函数
int ListClass::Elem(int elem) {
  if (nElem == nLen) {
    //线性表已满
    int *newptr;
    newptr = new int[nLen + 10];  //申请新的线性表空间，一次扩充10个元素空间

    //将原来的数据拷贝过来
    for (int i = 0; i < nElem; i++) {
      newptr[i] = ListPtr[i];
    }

    delete[] ListPtr;  //释放掉原来的空间
    nLen += 10;
    ListPtr = newptr;
  }
  ListPtr[nElem++] = elem;
  return (nElem);
}

//输出线性表中的全体元素
void ListClass::Print(void) {
  for (int i = 0; i < nElem; i++) {
    cout << ListPtr[i] << '\t';
  }
  cout << endl;
}

//排序
void ListClass::Sort(void) {
  for (int i = 0; i < nElem - 1; i++) {
    for (int j = 0; j < nElem - 1 - i; j++) {
      if (ListPtr[j] > ListPtr[j + 1]) {
        int temp = ListPtr[j];
        ListPtr[j] = ListPtr[j + 1];
        ListPtr[j + 1] = temp;
      }
    }
  }
}

//在位置n处插入数据，返回值为现在的线性表的长度
int ListClass::Insert(int data, int n) {
  if (nElem == nLen) {
    //线性表已满
    int *newptr;
    newptr = new int[nLen + 10];  //申请新的线性表空间，一次扩充10个元素空间

    //将原来的数据拷贝过来
    for (int i = 0; i < nElem; i++) {
      newptr[i] = ListPtr[i];
    }

    delete[] ListPtr;  //释放掉原来的空间
    nLen += 10;
    ListPtr = newptr;
  }
  //先把位置n及其之后的元素向后移动一位
  for (int i = nElem - 1; i > n - 1; i--) {
    ListPtr[i + 1] = ListPtr[i];
  }
  ListPtr[n] = data;
  nElem++;
  return nElem;
}

//利用常对象指针输出线性表里面的数据
void print1(const ListClass *list) {
  for (int i = 0; i < list->nElem; i++) {
    cout << list->ListPtr[i] << '\t';
  }
  cout << endl;
}

//利用常对象引用输出线性表里面的数据
void print2(const ListClass &list) {
  for (int i = 0; i < list.nElem; i++) {
    cout << list.ListPtr[i] << '\t';
  }
  cout << endl;
}

int main() {
  ListClass l1;
  l1.Elem(1);
  l1.Elem(2);
  l1.Elem(3);

  print1(&l1);
  print2(l1);

  return 0;
}