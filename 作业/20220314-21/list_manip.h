#include "node_def.h"

//向前生成无序链表
node* CreateFW();

//向后生成无序链表
node* CreateBW();

//在链表中查找一个结点，利用指向常量的指针保护节点的数据
const node* Search(const node* pHeader, int x);

//从链表中删除一个结点
void deleteNode(int val, struct node* pHeader);

//输出一个链表
void Print(struct node* pHeader);

//释放链表
void deleteChain(struct node* pHeader);

//升序插入函数
void insert(student* head, student* p);

//创建链表
student* create();

//输出结点所有数据
void Print(student* head);

// 释放链表中全部结点的存储空间
void delChain(student* head);

//完成入栈的操作
node* push(node* head, int a);

//完成出栈的操作
node* pop(node* head, int& d);

//获取栈顶的元素
int getFirst(node* head);

//展示栈中的元素
void display(node* head);

//撤销堆栈
void freestack(node* head);

//翻转算法1
void ListNodeReverse1(node* pHeader);

//排序算法
void ListNodeSort(node* head);
void ListNodeSort(node* low, node* high);