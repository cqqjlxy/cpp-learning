/*
  10-6
  把教材例10.15中线性表的元素类型由整型改为
  字符型，完成该例相同的要求。
  提示：线性表的字符可以是'A', 'B', 'C',..., '*', '?'等
  请思考，哪些数据类型需要从int修改为char，哪些不需要修改
  */

#include <iostream>

using namespace std;

class ListClass {
 private:
  char *ListPtr;  //指向线性表的指针
  int nLen;       //线性表的长度
  int nElem;      //线性表中当前元素的个数

 public:
  ListClass(int n = 10) {  //构造函数，线性表长度的缺省值为10
    nElem = 0;             //当前元素个数为0
    nLen = n;
    if (n) {  //当长度不为零时
      ListPtr = new char[n];
    } else {
      ListPtr = NULL;  //线性表长度为0，则指向空指针
    }
  }

  ~ListClass(void) {  //析构函数，释放线性表空间
    delete[] ListPtr;
  }

  int Elem(char);  //重载函数（1），在线性表末尾增加一个函数

  char &Elem(unsigned n) {  //重载函数（2），返回线性表下标为n的元素的引用
    return ListPtr[n];
  }

  int Elem(void) {  //重载函数（3），返回线性表中现有的元素个数
    return nElem;
  }

  int Len(void) {  //返回线性表的长度
    return nLen;
  }

  void GetElem(int i, char &result) {
    //返回线性表下标为i的元素的值，flag保存是否查找成功
    if ((i >= 0) && (i < nElem)) {
      result = ListPtr[i];
    } else {
      cout << "下标越界" << endl;
    }
  }

  void Print(void);  //输出线性表中的所有元素，在类体外实现
};

//重载函数（1），在线性表末尾增加一个函数
int ListClass::Elem(char elem) {
  if (nElem == nLen) {
    //线性表已满
    char *newptr;
    newptr = new char[nLen + 10];  //申请新的线性表空间，一次扩充10个元素空间

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

int main() {
  ListClass list(6);
  for (int i = 0; i < 5; i++) {
    char a = 'A' + i;
    list.Elem(a);  //调用重载函数（1），用A-E填充线性表
  }
  cout << "线性表的长度为：" << list.Len() << endl;
  cout << "线性表的元素个数为：";
  cout << list.Elem() << endl;  //调用重载函数(3)
  cout << "线性表的元素为：";
  list.Print();
  cout << "重新赋值前，线性表中下标为3的元素的值为：";
  cout << list.Elem(3U) << endl;
  list.Elem(3U) = 'Z';
  cout << "赋值后，线性表中下标为3的元素的值为：";
  cout << list.Elem(3U) << endl;
  list.Elem('F');
  list.Elem('G');
  cout << "现在线性表的长度为：" << list.Len() << endl;
  cout << "现在线性表中的元素个数为：";
  cout << list.Elem() << endl;
  cout << "线性表的元素为：";
  list.Print();
  cout << "线性表的最后一个元素为：";
  bool flag;  //判断是否获取成功的变量
  char result;
  list.GetElem(list.Elem() - 1, result);
  cout << result;

  return 0;
}