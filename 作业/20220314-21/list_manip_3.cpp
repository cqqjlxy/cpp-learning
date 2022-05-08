/*
    14.用链表实现一个简单的堆栈。所谓堆栈是一种数据结构，类似于一个桶，物品可
  以按顺序一个一个放进去，再按顺序一个一个取出来。后放进去的物品，先取出来;先放进
  去的物品，后取出来。本题中把整型量看成物品，把链表看成水桶即堆栈,链表的尾结点是
  桶底,首结点是桶口，链表的首指针指向首结点，即指向桶口。结点结构如下
  struct node {
    int data;
    struct node * next;
  };

  编写函数：
  (1) node * push(node * head, int a);参数 head 是链表首指针。函数完成入栈操作。
  即以参数a作为data值构建一个新结点插人到链表的首部，返回新链表首指针。
  (2) node * pop(node * head, int &d);完成出栈操作。将链表首结点的 data 值通过参
  数d带回到主调函数，同时删除首结点并释放其空间，返回新链表首指针。
  (3) int getFirst(node * head);完成获取栈顶元素操作，即将链表首结点 data 值返
  回,链表本身不变。
  (4) void display(node * head) ;显示堆栈中全体元素，即输出链表中全体结点的值。
  (5) void freestack(node * head);撤销堆栈，即释放链表全体结点的空间。
  在主函数中，自行设计过程，分别调用上述5个函数，完成堆栈的入栈、出栈等测试
  工作。
  提示：初始堆栈为空栈，即链表为空链表，首指针的值为 NULL!
*/

#include <iostream>

#include "list_manip.h"

using namespace std;

//完成入栈的操作
node* push(node* head, int a) {
  node* pNew = new node;
  pNew->data = a;
  pNew->next = head;
  head = pNew;
  return head;
}

//完成出栈的操作
node* pop(node* head, int& d) {
  d = head->data;
  //临时记录一下head的位置
  node* temp = head;
  head = head->next;
  delete temp;
  temp = NULL;
  return head;
}

//获取栈顶的元素
int getFirst(node* head) {
  if (head == NULL) {
    cout << "NULL!" << endl;
    return 0;
  }
  return head->data;
}

//展示栈中的元素
void display(node* head) {
  while (head != NULL) {
    cout << head->data << endl;
    head = head->next;
  }
}

//撤销堆栈
void freestack(node* head) {
  //临时保存一下下一个结点的地址
  while (head != NULL) {
    node* temp = head->next;
    delete head;
    head = temp;
  }
}
