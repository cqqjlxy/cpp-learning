//动态链表
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "linkList.h"

using namespace std;

void test01() {
  //初始化链表
  struct LinkNode* pHeader = initLinkList();

  //遍历链表
  cout << "链表的结果为：" << endl;
  foreach_LinkList(pHeader);
  cout << endl;

  //插入链表
  insert_LinkList(pHeader, 10, 1000);
  insert_LinkList(pHeader, 20, 2000);
  insert_LinkList(pHeader, -1, 500);

  //遍历链表
  cout << "插入链表后的结果为：" << endl;
  foreach_LinkList(pHeader);
  cout << endl;

  //删除链表某一节点
  delete_LinkList(pHeader, 2000);
  delete_LinkList(pHeader, 1000);
  delete_LinkList(pHeader, 5000);

  //遍历链表
  cout << "删除链表某一节点后的结果为：" << endl;
  foreach_LinkList(pHeader);
  cout << endl;

  //清空链表
  clear_LinkList(pHeader);

  //遍历链表
  cout << "清空链表后的结果为：" << endl;
  foreach_LinkList(pHeader);

  //重新验证能否继续使用
  insert_LinkList(pHeader, 10, 1000);
  insert_LinkList(pHeader, 20, 2000);
  insert_LinkList(pHeader, -1, 500);

  //遍历链表
  cout << "复用链表后的结果为：" << endl;
  foreach_LinkList(pHeader);
  cout << endl;

  //销毁链表
  destory_LinkList(pHeader);
}
int main() {
  test01();

  return EXIT_SUCCESS;
}