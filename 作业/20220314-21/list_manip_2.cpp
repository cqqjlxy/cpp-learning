/*
  13.建立一条有序链表，并输出这条链表上各个结点的值。结点为一个结构体类型
  student的量，结构体类型student包含属性：学号(num,宇符串)、姓名(name,字符串）,年
  龄(age,整型量）,成绩(score,整型量）和next(指向下一结点的指针)。
  要求定义函数：
  (1)void insert(student *head, student *p),head 指向的链表结点已经是按
  学号排成升序的，将p结点插入后，保持学号升序;
  (2)student* create()循环输入多个结点数据，以输入学号一1结束，每输人一个结
  点数据，动态创建一个结点并调用 insert()函数将该新结点插入，完成有序链表的建立;
  (3)void Print(student* head)输出链表所有结点的数据.
  (4)void delChain(student* head)释放链表中全部结点的存储空间
*/

#include <iostream>

#include "list_manip.h"

using namespace std;

//升序插入函数
void insert(student* head, student* p) {
  //只有头节点的情况
  if (head->next == NULL) {
    head->next = p;
    return;
  }

  student* pCurrent = head->next;
  student* pPrev = head;
  while (pCurrent->num < p->num) {
    pPrev = pCurrent;  //记录一下上一个结点的位置
    if (pCurrent->next == NULL) {
      pCurrent = NULL;
      break;
    }
    pCurrent = pCurrent->next;
  }

  p->next = pCurrent;  //插入
  pPrev->next = p;
}

//创建链表
student* create() {
  //新建一个头节点
  student* pHeader = new student;

  //判断头节点是否申请成功
  if (pHeader == NULL) {
    return NULL;
  }

  pHeader->num = "0";
  pHeader->age = 0;
  pHeader->name = "0";
  pHeader->score = 0;
  pHeader->next = NULL;

  //新建一个结点
  cout << "请输入学生的学号、姓名、年龄、成绩，以空格隔开，输入-1结束: "
       << endl;
  string num, name;
  int age, score;
  cin >> num >> name >> age >> score;

  while (num != "-1") {
    student* pNew = new student;
    pNew->num = num;
    pNew->name = name;
    pNew->age = age;
    pNew->score = score;
    pNew->next = NULL;

    insert(pHeader, pNew);
    cout << "请输入学生的学号、姓名、年龄、成绩，以空格隔开，输入-1结束: "
         << endl;
    cin >> num >> name >> age >> score;
  }
  return (pHeader);
}

//输出链表所有结点的数据
void Print(student* head) {
  student* pCurrent = head->next;  //指向非头结点的第一个结点
  while (pCurrent != NULL) {
    cout << "学号：" << pCurrent->num << endl
         << "姓名：" << pCurrent->name << endl
         << "年龄：" << pCurrent->age << endl
         << "分数：" << pCurrent->score << endl
         << endl;
    pCurrent = pCurrent->next;
  }
}

// 释放链表中全部结点的存储空间
void delChain(student* head) {
  if (head == NULL) {
    return;
  }
  //先删除除了头节点以外的节点
  struct student* pCurrent = head->next;

  while (pCurrent != NULL) {
    //先保存一下下一个节点的位置
    struct student* pNext = pCurrent->next;

    delete pCurrent;

    pCurrent = pNext;
  }
  //再删除头节点
  delete head;
  head = NULL;
}
