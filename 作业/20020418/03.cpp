/*
  2．	在教材线性表(例10.15)的基础上修改
    1) 定义拷贝构造函数，实现深拷贝
    2) 添加线性表排序成员函数
    3) 添加在线性表中位置n处插入数据的成员函数，
       需要考虑线性表内存自动扩充的问题，
       线性表末尾追加数据的成员函数也需要考虑这个问题
    4) Main函数中实现各个成员函数的测试
*/

#include <cstdlib>
#include <ctime>
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

int main() {
  //测试拷贝构造函数
  ListClass list1(6);
  for (int i = 0; i < 5; i++) {
    list1.Elem(i);
  }
  cout << "list1为: " << endl;
  list1.Print();
  ListClass list2 = list1;
  cout << "拷贝构造的list2为：" << endl;
  list2.Print();

  //测试排序成员函数，先用随机数填充。
  srand(time(NULL));
  ListClass list3(10);
  for (int i = 0; i < 10; i++) {
    list3.Elem(rand() % 20);
  }
  cout << "排序前的线性表为：" << endl;
  list3.Print();

  cout << "排序后的线性表为：" << endl;
  list3.Sort();
  list3.Print();

  //测试在线性表位置n处插入数据成员函数
  cout << "插入前的线性表为：" << endl;
  list1.Print();

  cout << "在位置3处插入100后的线性表为：" << endl;
  list1.Insert(100, 3);
  list1.Print();

  return 0;
}