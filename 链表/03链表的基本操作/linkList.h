#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include <cstdlib>
#include <iostream>

struct LinkNode {
  int num;
  struct LinkNode* next;
};

//初始化链表
struct LinkNode* initLinkList();

//遍历链表
void foreach_LinkList(struct LinkNode* pHeader);

//插入链表
void insert_LinkList(struct LinkNode* pHeader, int oldVal, int newVal);

//删除链表某一节点
void delete_LinkList(struct LinkNode* pHeader, int val);

//清空链表（只删除掉有数据的节点，链表还能再重新使用）
void clear_LinkList(struct LinkNode* pHeader);

//销毁链表（删除整张链表，包括头节点，链表不能再使用）
void destory_LinkList(struct LinkNode* pHeader);