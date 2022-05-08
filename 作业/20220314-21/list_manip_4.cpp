/*
  3．	在1的基础上，添加如下函数：
    1）	链表翻转，可以考虑几种算法
    2）链表排序，可以考虑几种算法
*/

//链表的翻转
#include <iostream>

#include "list_manip.h"

using namespace std;

//翻转算法1
void ListNodeReverse1(node *pHeader) {
  //新建三个指针，分别指向三个连着的节点
  if (pHeader == NULL || pHeader->next == NULL || pHeader->next->next == NULL) {
    return;
  }

  node *pPrev = pHeader->next;
  node *pCurrent = pPrev->next;
  node *pNext = pCurrent->next;

  pPrev->next = NULL;  //先处理掉第一个结点的指针域
  while (pNext) {
    pCurrent->next = pPrev;

    pPrev = pCurrent;
    pCurrent = pNext;
    pNext = pNext->next;
  }
  pCurrent->next = pPrev;
  pHeader->next = pCurrent;
}

//链表排序

void ListNodeSort(node *head) {
  node *low = head->next;  //有头节点的链表第一个结点
  node *high = head->next;
  if (head != NULL) {
    while (high->next != NULL) {
      high = high->next;
    }
  }

  int pivot = low->data;
  node *i = low;
  node *iPrev = head;
  node *j = low;
  int temp;
  while (j != NULL) {
    if (j->data > pivot || j->data == pivot) {
      j = j->next;
    }

    if (j->data < pivot) {
      temp = i->data;
      i->data = j->data;
      j->data = temp;

      i = i->next;
      iPrev = iPrev->next;
      j = j->next;
    }
  }
  ListNodeSort(low, iPrev);
  ListNodeSort(i, j);
}

void ListNodeSort(node *low, node *high) {
  if (low == NULL || low->next == NULL || low == high) {
    return;
  }
  int pivot = low->data;
  node *i = low;
  node *iPrev = low;
  node *j = low;

  while (j != NULL) {
    if (j->data > pivot || j->data == pivot) {
      j = j->next;
    }

    if (j->data < pivot) {
      if (iPrev == i) {
        i = i->next;
      } else {
        i = i->next;
        iPrev = iPrev->next;
      }
      j = j->next;
    }
  }
  ListNodeSort(low, iPrev);
  ListNodeSort(i, j);
}