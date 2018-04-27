/*


Jacob Alderink 
C++ stack implementation of stack.h

*/


#include "stack.h"

bool stack::IsIn(int l){
  node* m = head;
  while(m ->next != NULL){
    // cout << "checking " << m->data << " for  " << l << endl;
    if(m->data == l)
      return true;
    m = m->next;
  }
  if(m->data == l)
      return true;
  return false;
}

bool stack::isEmpty(){
  if( head == NULL)
    return true;
  else
    return false;
}

int stack::list(int x){
  node* m = head;
  if(x == 0)
    return m->data;
  
  for(int i = 0; i < x; i++){
    m = m -> next;
  }
  return m->data;
}

int stack::size(){
  int sizel = 0;
  node* n = head;
  while(n->next != NULL){
    n = n->next;
    sizel++;
  }
  return sizel;
}


void stack::push(int x){
  node* ptr = new node;
  ptr -> data = x;
  ptr -> next = NULL;
  if(head== NULL){
    head = ptr;
  }
  else{
    ptr -> next = head;
    head = ptr;
  }
  
}


int stack::pop(){
  if(head == NULL){
    cout << " Stack is empty" << endl;
    return -1;
  }
  else{
    node* ptr;
    ptr = head;
    head = head -> next;
    int x = ptr -> data;
    ptr -> next = NULL;
    delete ptr;
    return x;
  }
}

int stack::peek(){
    if(head == NULL){
    cout << " Stack is empty" << endl;
    return -1;
  }
  else{
    int x = head -> data;
    return x;
  }
}


void stack::print(){
  node* p = head;
  cout << "List contents:";
  while(p != NULL){
    cout << p->data << "    ";
    p = p->next;
  }
  cout << endl;
}
