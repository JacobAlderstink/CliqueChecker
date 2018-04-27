/*

stack.h
C++ stack header file

*/
#include <iostream>
using namespace std;

class stack{
 private:
  struct node{
    int data;
    node * next;
  };
  node* head;

 public:
  bool isEmpty();
  int size();
  bool IsIn(int l);
  int list(int x);
  void push(int x);
  int pop();
  int peek();
  void print();
};
