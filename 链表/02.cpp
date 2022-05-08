//动态链表
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

using namespace std;

//节点的结构体
struct LinkNode {
  int num;                //数据域
  struct LinkNode* next;  //指针域
};

void test01() {
  //创建节点
  struct LinkNode* node1 = new LinkNode;
  struct LinkNode* node2 = new LinkNode;
  struct LinkNode* node3 = new LinkNode;
  struct LinkNode* node4 = new LinkNode;
  struct LinkNode* node5 = new LinkNode;

  //给数据赋初值
  node1->num = 100;
  node2->num = 200;
  node3->num = 300;
  node4->num = 400;
  node5->num = 500;

  //建立关系
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = NULL;

  //遍历链表
  struct LinkNode* pCurrent = node1;

  while (pCurrent != NULL) {
    cout << pCurrent->num;
    pCurrent = pCurrent->next;
  }
}

int main() {
  test01();

  return EXIT_SUCCESS;
}