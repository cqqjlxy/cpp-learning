/*
  2．将前面所写的链表程序改写成面向对象的程序
    1）定义一个构造函数，用数组作为参数构造一个链表
    2）定义缺省构造函数，构造一个空链表
    3）在析构函数里面释放链表。
    4）添加链表反转成员函数
    5）添加链表排序成员函数
    6）添加向链表加入数据的成员函数
    7）添加从链表删除数据的成员函数(可能要删除多个结点)，参考前面写的高考录取程序
    8）添加获取链表节点数的成员函数
    9）添加显示链表节点数据的成员函数
    10）Main函数中实现各个成员函数的测试
*/

#include <iostream>

using namespace std;

class Node {
 public:
  //用数组作为参数构造一个链表。
  Node(int a[], int n, int flag) {
    if (flag != n - 1) {
      data = a[flag];
      flag++;
      next = new Node(a, n, flag);
      return;
    }
    if (flag == n - 1) {
      data = a[flag];
      next = NULL;  //如果为最后一个数据，则最后一个指针为空指针
      return;
    } else {
      return;
    }
  }

  //缺省构造函数，构造一个空链表
  Node() {
    data = 0;
    next = NULL;
  }

  //析构函数，释放链表
  ~Node() {
    //测试是否调用析构函数
    cout << "调用析构函数，结点数据为: " << this->data << endl;
    if (this->next != NULL) {
      delete this->next;
    }
  }

  //链表反转成员函数
  void reverse() {
    if (next == NULL || next->next == NULL) {
      return;
    }
    //新建三个指针，分别指向当前结点，上一个结点和下一个结点。
    Node* pPrev =
        next;  //假设在头节点调用这个成员函数，那么第一个元素就应该是next
    Node* pCurrent = next->next;
    Node* pNext = pCurrent->next;

    pPrev->next = NULL;        //先处理第一个结点的指针域
    while (pNext) {            //不是最后一个结点的时候
      pCurrent->next = pPrev;  //后一个结点指向前一个结点

      //向后移动
      pPrev = pCurrent;
      pCurrent = pNext;
      pNext = pNext->next;
    }
    //最后一个结点时
    pCurrent->next = pPrev;
    next = pCurrent;
  }

  //排序成员函数
  void sort() {  //假设在头节点调用该函数
    //先遍历链表有多少个元素
    int flag = 0;
    Node* temp = next;  //临时指针
    while (temp->next != NULL) {
      temp = temp->next;
      flag++;
    }

    temp = next;
    for (int i = 0; i < flag; i++) {
      for (int j = 0; j < flag - i; j++) {
        if (temp->data > temp->next->data) {
          int a = temp->data;
          temp->data = temp->next->data;
          temp->next->data = a;
        }
        temp = temp->next;
      }
      temp = next;
    }
  }

  //向链表中加入数据的成员函数
  void insert_data(int val, int data) {
    // val为待加入的数据，data为需要在链表中查找的数据
    //找到后会自动加在其前面，如果没有找到，插入到链表结尾
    //定义两个指针
    Node *pPrev, *pCurrent;
    pPrev = this;
    pCurrent = next;

    //寻找待插入的位置
    while (pCurrent->data != data) {
      if (pCurrent->next == NULL) {
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
        break;
      }
      pPrev = pCurrent;
      pCurrent = pCurrent->next;
    }

    //插入
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = pCurrent;
    pPrev->next = newNode;
  }

  //寻找链表里的某一节点删除
  void delete_data(int data) {
    //定义三个临时指针
    Node* pPrev = this;
    Node* pCurrent = next;
    Node* pNext = next->next;

    //定位待删除的数据
    while (pCurrent->data != data) {
      if (pNext == NULL) {
        cout << "没有找到待删除的数据，或已经全部删除完毕。";
        return;
      }
      pPrev = pCurrent;
      pCurrent = pNext;
      pNext = pNext->next;
    }
    pPrev->next = pNext;
    //先将待删除结点的next指针置空，防止析构时误删后面的数据
    pCurrent->next = NULL;
    delete pCurrent;

    delete_data(data);  //再次遍历，确保已经删除完成
  }

  //获取链表成员个数
  int get_num() {
    //获取不含头节点的链表成员个数
    Node* temp = next;
    int flag = 0;
    while (temp != NULL) {
      temp = temp->next;
      flag++;
    }
    return flag;
  }

  //显示链表各成员的数据
  void display() {
    Node* temp = next;
    while (temp != NULL) {
      cout << temp->data << endl;
      temp = temp->next;
    }
  }

  int data;
  Node* next;
};

int main() {
  //测试链表的反转
  int a[3] = {1, 2, 3};
  Node* Head1 = new Node;  //先调用缺省构造函数新建一个头节点
  Head1->next = new Node(a, 3, 0);
  cout << "反转前的链表为：" << endl;
  Head1->display();
  Head1->reverse();
  cout << "反转后的链表为：" << endl;
  Head1->display();

  //测试链表的排序
  int b[5] = {5, 4, 1, 3, 2};
  Node* Head2 = new Node;
  Head2->next = new Node(b, 5, 0);
  cout << "排序前的链表为：" << endl;
  Head2->display();
  Head2->sort();
  cout << "排序后的链表为：" << endl;
  Head2->display();

  //测试向链表里面加入一个数
  //在中间某一个数之前插入
  Head2->insert_data(6, 1);  //在上一个链表的1前面插入6
  cout << "插入后的结果为：" << endl;
  Head2->display();
  //若寻找的数不存在，插入在链表的最后
  Head2->insert_data(6, -1);  //在-1前插入6，但是-1不存在，所以应该插在最后
  cout << "第二次插入后的结果为：" << endl;
  Head2->display();

  //在链表中删除6，插入后6应该有2个，验证是否能删除多个同一数据
  Head2->delete_data(6);
  cout << "删除后的结果为：" << endl;
  Head2->display();

  //测试获取结点数量
  cout << "结点的数量为：" << Head2->get_num() << endl;

  //测试析构函数，若显示结点数据为0，则可能为头节点
  delete Head1;
  delete Head2;

  return 0;
}