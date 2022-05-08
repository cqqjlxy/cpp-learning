/*
  1．	整合教材上关于链表的程序片段，形成完整程序，并包括如下函数：
    1）	 向前生成无序链表（新结点插在链首）
    2）	 向后生成无序链表（新结点插在链尾）
    3）	 在链表中查找一个结点
    4）	 从删除一个结点
    5）	 输出一个链表
    6）	释放链表
*/

#include <iostream>

#include "list_manip.h"

using namespace std;

//向前生成无序链表
node *CreateFW() {
  node *pHeader, *pNext,
      *pCurrent;  //创建三个指针：链表的头指针、后一个节点、当前新生成的节点
  int data;       //数据域

  //创建一个头节点
  pHeader = new struct node;
  pHeader->data = 0;  //头节点数据域初始化为0

  //判断内存空间有没有申请成功
  if (pHeader == NULL) {
    return NULL;
  }

  //初始化链表
  pNext = NULL;  //后一个节点先设置为空

  cout << "请输入数据，以-1结束: " << endl;
  cin >> data;

  while (data != -1) {
    pCurrent = new struct node;
    pCurrent->data = data;

    if (pNext == NULL) {
      //判断现在是不是第一个节点

      pCurrent->next = NULL;  //前插时第一个节点为最后一个节点，next置为空
      pNext = pCurrent;          //记录后一个节点的位置
      pHeader->next = pCurrent;  //头节点指向现在的第一个节点
    } else {
      pCurrent->next = pNext;  //向前插入一个节点，连接到上一轮生成的节点
      pNext = pCurrent;          //记录后一个节点的位置
      pHeader->next = pCurrent;  //头节点指向现在的第一个节点
    }
    cout << "请输入下一个数据，以-1结束: " << endl;
    cin >> data;
  }

  return pHeader;
}

//向后生成无序链表
node *CreateBW() {
  //定义头节点、当前节点、上一个节点
  node *pHeader, *pCurrent, *pPrev;
  int data;

  //初始化头节点
  pHeader = new struct node;
  pHeader->data = 0;

  //判断头节点是否申请成功
  if (pHeader == NULL) {
    return NULL;
  }

  //初始化链表
  pPrev = NULL;  //上一个节点位置先置空

  cout << "请输入数据，以-1结束: " << endl;
  cin >> data;

  while (data != -1) {
    pCurrent = new node;  //新建一个内存空间
    pCurrent->data = data;

    //判断是否为第一个生成的节点
    if (pPrev == NULL) {
      pHeader->next = pCurrent;  //头节点指向现在的节点
      pPrev = pCurrent;          //记录上一个节点的位置
      pCurrent->next = NULL;     //下个节点指针先置空
    } else {
      pPrev->next = pCurrent;
      pPrev = pCurrent;
    }

    cout << "请输入下一个数据，以-1结束: " << endl;
    cin >> data;
  }

  return pHeader;
}

//在链表中查找一个结点，利用指向常量的指针保护节点的数据
const node *Search(const node *pHeader, int x) {
  const node *pCurrent;

  pCurrent = pHeader->next;
  while (pCurrent != NULL) {
    if (pCurrent->data == x) {
      return pCurrent;
    }
    pCurrent = pCurrent->next;
  }
  return NULL;
}

//从链表中删除一个结点
void deleteNode(int val, struct node *pHeader) {
  if (pHeader == NULL) {
    return;
  }

  //创建两个辅助指针变量
  struct node *pCurrent, *pPrev;
  pCurrent = pHeader->next;  // pCurrent指向第一个非空结点
  pPrev = pHeader;

  while (pCurrent != NULL) {
    //寻找待删除的节点
    if (pCurrent->data == val) {
      break;
    }

    pPrev = pCurrent;
    pCurrent = pCurrent->next;

    //没有找到用户要删除的数据
    if (pCurrent == NULL) {
      cout << "没有找到需要删除的数据: " << val << endl;
      return;
    }
  }
  pPrev->next = pCurrent->next;  //将上一个结点连接到现在的下一个结点
  delete pCurrent;               //释放内存空间
  pCurrent = NULL;               //置空指针

  return;
}

//输出一个链表
void Print(struct node *pHeader) {
  if (pHeader == NULL) {
    cout << "链表为空！" << endl;
    return;
  }

  node *pCurrent = pHeader->next;

  while (pCurrent != NULL) {
    cout << pCurrent->data << '\t';
    pCurrent = pCurrent->next;
  }

  return;
}

//释放链表
void deleteChain(struct node *pHeader) {
  if (pHeader == NULL) {
    return;
  }

  //先删除除了头节点以外的节点
  struct node *pCurrent = pHeader->next;

  while (pCurrent != NULL) {
    //先保存一下下一个节点的位置
    struct node *pNext = pCurrent->next;

    delete pCurrent;

    pCurrent = pNext;
  }
  //再删除头节点
  delete pHeader;
  pHeader = NULL;
}