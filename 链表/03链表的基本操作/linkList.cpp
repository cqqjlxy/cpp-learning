#include <iostream>

#include "linkList.h"
using namespace std;

//初始化链表
struct LinkNode* initLinkList() {
  //创建头节点
  struct LinkNode* pHeader = new struct LinkNode;

  if (pHeader == NULL) {
    return NULL;
  }

  //初始化头节点
  // pHeader->num = -1;  //头节点不维护数据域
  pHeader->next = NULL;

  //让用户初始化几个节点，如果用户输入-1，代表插入结束
  cout << "请输入几个数据，输入-1结束" << endl;
  //记录尾节点的位置，方便插入新的数据
  struct LinkNode* pTail = pHeader;
  while (1) {
    int val;
    cin >> val;
    if (val == -1) {
      break;
    }
    //如果输入不是-1，插入节点到链表中
    struct LinkNode* newNode = new struct LinkNode;
    newNode->num = val;
    newNode->next = NULL;

    //更改指针的指向
    pTail->next = newNode;
    //更新尾节点的指向；
    pTail = newNode;
  }
  return (pHeader);
}

//遍历链表
void foreach_LinkList(struct LinkNode* pHeader) {
  if (pHeader == NULL) {
    return;
  }

  struct LinkNode* pCurrent = pHeader->next;  //指向第一个有真实数据的节点

  while (pCurrent != NULL) {
    cout << pCurrent->num << " ";
    pCurrent = pCurrent->next;
  }
}

//插入链表
void insert_LinkList(struct LinkNode* pHeader, int oldVal, int newVal) {
  if (pHeader == NULL) {
    return;
  }

  //创建两个临时的节点
  struct LinkNode* pPrev = pHeader;
  struct LinkNode* pCurrent = pHeader->next;

  while (pCurrent != NULL) {
    if (pCurrent->num == oldVal) {
      break;
    }
    //如果没找到位置，辅助指针向后移动
    //如果数据里面没有oldVal，pCurrent指向无意义的位置，pPrev指向尾节点
    pPrev = pCurrent;
    pCurrent = pCurrent->next;
  }
  //创建新的节点
  struct LinkNode* newNode = new struct LinkNode;
  newNode->num = newVal;
  newNode->next = NULL;
  //建立关系
  newNode->next = pCurrent;
  pPrev->next = newNode;
}

//删除链表某一节点
void delete_LinkList(struct LinkNode* pHeader, int val) {
  if (pHeader == NULL) {
    return;
  }

  //创建两个辅助的指针变量
  struct LinkNode* pPrev = pHeader;
  struct LinkNode* pCurrent = pHeader->next;

  while (pCurrent != NULL) {
    if (pCurrent->num == val) {
      break;
    }
    //没有找到数据向后移动
    pPrev = pCurrent;
    pCurrent = pCurrent->next;
  }
  //没有找到用户需要的数据
  if (pCurrent == NULL) {
    cout << "没有找到需要删除的数据:"
         << "\"" << val << "\"" << endl;
    return;
  }
  pPrev->next = pCurrent->next;
  delete pCurrent;
  pCurrent = NULL;
}

//清空链表（只删除掉有数据的节点，链表还能再重新使用）
void clear_LinkList(struct LinkNode* pHeader) {
  if (pHeader == NULL) {
    return;
  }

  struct LinkNode* pCurrent = pHeader->next;

  while (pCurrent != NULL) {
    //先保存住下一个节点的位置
    struct LinkNode* nextNode = pCurrent->next;

    delete pCurrent;

    pCurrent = nextNode;
  }
  pHeader->next = NULL;
}

//销毁链表（删除整张链表，包括头节点，链表不能再使用）
void destory_LinkList(struct LinkNode* pHeader) {
  //先清空链表
  clear_LinkList(pHeader);
  delete pHeader;
  pHeader = NULL;
}
