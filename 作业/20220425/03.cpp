/*
        2.
   为链表类定义一个友元函数，可以输出链表所有节点的数据，函数参数为链表类的常对象引用或者常对象指针
*/

#include <iostream>

using namespace std;

class List;
class Node {
 private:
  int data;
  Node* next;
  friend class List;
  friend void print1(const List* list);  //常对象指针
  friend void print2(const List& list);  //常对象引用
};

class List {
 private:
  Node* head;

 public:
  //缺省构造函数，创建一个空链表
  List() {
    head = new Node;
    head->data = 0;
    head->next = NULL;
  }

  //生成结点数据域值为d的单结点链表
  List(int d) {
    head = new Node;
    head->data = 0;
    head->next = new Node;
    head->next->data = d;
    head->next->next = NULL;
  }

  //输出链表各结点的值
  void print() {
    Node* pCurrent = head->next;  //指向当前结点的指针
    while (pCurrent) {
      cout << pCurrent->data << endl;
      pCurrent = pCurrent->next;
    }
  }

  //追加结点
  void append(int d) {
    Node* pCurrent = head->next;
    //寻找最后一个结点
    while (pCurrent->next) {
      pCurrent = pCurrent->next;
    }
    pCurrent->next = new Node;
    pCurrent->next->data = d;
    pCurrent->next->next = NULL;
  }

  //析构函数，释放链表结点的空间
  ~List() {
    Node* pCurrent = head->next;  //记录当前结点的位置
    while (pCurrent) {
      Node* pNext = pCurrent->next;  //先保存一下下一个结点的地址
      delete pCurrent;
      pCurrent = pNext;
    }
    delete head;
  }
  friend void print1(const List* list);  //常对象指针
  friend void print2(const List& list);  //常对象引用
};

void print1(const List* list) {
  Node* pCurrent = list->head->next;
  while (pCurrent) {
    cout << pCurrent->data << endl;
    pCurrent = pCurrent->next;
  }
}

void print2(const List& list) {
  Node* pCurrent = list.head->next;
  while (pCurrent) {
    cout << pCurrent->data << endl;
    pCurrent = pCurrent->next;
  }
}

int main() {
  List l1(1);
  l1.append(2);
  l1.append(3);

  print1(&l1);
  print2(l1);

  return 0;
}