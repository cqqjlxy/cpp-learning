#include <iostream>

#include "list_manip.h"

using namespace std;

//测试向前插入
void test01() { node* list1 = CreateFW(); }

//测试向后插入
void test02() { node* list2 = CreateBW(); }

//测试查找结点
void test03() {
  node* list = CreateBW();  //先用后插法生成一个列表
  cout << "请输入要查找的数： " << endl;
  int x;
  cin >> x;

  const node* pHeader = Search(list, x);
  if (pHeader == NULL) {
    cout << "在列表中找不到该数据" << endl;
  } else {
    cout << "该数据的指针为：" << pHeader << endl;
  }
}

//测试删除节点
void test04() {
  node* list = CreateBW();
  cout << "请输入要删除的节点: " << endl;
  int val;
  cin >> val;

  deleteNode(val, list);
}

//测试输出链表
void test05() {
  node* list = CreateBW();
  Print(list);
}

//测试删除链表
void test06() {
  node* list = CreateBW();
  cout << "删除前" << endl;
  Print(list);
  cout << "删除后" << endl;
  deleteChain(list);
  Print(list);
}

//测试学生实例
void test_student() {
  student* class1 = create();
  Print(class1);
  delChain(class1);
  Print(class1);
}

//测试模拟堆栈
void test_stack() {
  node* stack1 = new node;
  stack1->next = NULL;
  stack1 = push(stack1, 1);
  stack1 = push(stack1, 2);
  stack1 = push(stack1, 3);
  cout << getFirst(stack1) << endl;
  display(stack1);
  int d;
  stack1 = pop(stack1, d);
  cout << d << endl;
  cout << getFirst(stack1) << endl;
  display(stack1);
  freestack(stack1);
  display(stack1);
}

//测试链表的翻转算法1
void test07() {
  node* list = CreateBW();
  Print(list);
  ListNodeReverse1(list);
  Print(list);
}

//测试链表的排序
void test08() {
  node* list = CreateBW();
  Print(list);

  ListNodeSort(list);
  Print(list);
}
int main() {
  // test01();
  // test02();
  // test03();
  // test04();
  // test05();
  // test06();
  // test_student();
  // test_stack();
  // test07();
  test08();

  return EXIT_SUCCESS;
}
