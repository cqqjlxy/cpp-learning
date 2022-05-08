#include <string>
using namespace std;

struct node {
  int data;
  node* next;
};

struct student {
  string num;
  string name;
  int age;
  int score;
  student* next;
};