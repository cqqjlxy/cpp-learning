/*
        实验指导书实验11-2
*/

#include <iostream>

using namespace std;

class Node {
 private:
  int data;
  Node* next;
  friend class List;
};

class List {
 private:
  Node* head;  //指向链表头节点的指针

 public:
  //缺省构造函数，创建一个空链表
  List() {
    head = new Node;
    head->data = 0;
    head->next = NULL;
    cout << "调用缺省构造函数" << endl;
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
      cout << "删除的结点数据为：" << pCurrent->data << endl;
      delete pCurrent;
      pCurrent = pNext;
    }
    delete head;
  }
};

int main() {
  //新建一个链表
  List l1;
  List l2(1);
  cout << "l2的数据为：" << endl;
  l2.print();
  cout << "调用追加函数后l2的数据为：" << endl;
  l2.append(2);
  l2.print();

  return 0;
}