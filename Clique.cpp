#include <iostream>
#include "stack.h"
using namespace std;
const int sizeofgraph = 6;
stack* graph[sizeofgraph];
void setup();
int cliqueCheck(int);
int factorial(int);
void adjust(int x[], int Asize, int index);
void adjustP(int x[], int NumOfC, int Asize, int index);
int main(){
  setup(); 
  cout << cliqueCheck(3) << endl;
  cout << cliqueCheck(4) << endl;
  cout << cliqueCheck(5) << endl;;
  
}
int factorial(int x)
{
  int sum = 1;
  while(x >= 1){
    sum *= x;
    x--;
  }
  return sum;

}

int permfunction(int n, int r)
{
  return factorial(n)/(factorial(n-r));
}


int choosefunction(int n, int r)
{
  return factorial(n)/(factorial(r)*factorial(n-r));
}

void clear(int x[], int size)
{
  for(int i = 0; i < size; i++)
    {
      x[i] = 0;
    }

}

bool check(int x[], int size){
  for(int i = 0; i < size; i++){
    cout << x[i] << "  ";
    }
  cout << endl;
  int placement[2];
  placement[0] = 0;
  placement[1] = 1;
  
  for(int i = 0; i < choosefunction(size,2); i++){
    if(!graph[x[placement[0]]]->IsIn(x[placement[1]])){
      return false;		 
    }
    adjustP(placement, size, 1, 1);
  }
  cout << "This is True!" << endl; 
  return true;
}


int cliqueCheck(int numOfC){
  stack* visiting = new stack();
  int x[numOfC];
  int count = 0;
  for(int i = 0; i < numOfC; i++)
    {
      x[i] = i;
    }
  for(int i = 0; i < choosefunction(sizeofgraph,numOfC);i++)
    {
      if(check(x, numOfC))
	count++;
      if(choosefunction(sizeofgraph,numOfC) == i +1)
	return count;
      adjust(x, numOfC ,numOfC-1);
    }
  
  
  
}

void adjustP(int x[], int NumOfC, int Asize, int index){
  if(x[index]+1 == (index - Asize + NumOfC)){
    adjustP(x, NumOfC, Asize, index-1);
  }
  else{
    x[index]++;
    while(index != Asize){
      index++;
      x[index] = x[index-1]+1;
    }
  }

}


void adjust(int x[], int Asize, int index){
  if(x[index]+1 == (index - Asize + sizeofgraph+1)){
    adjust(x,Asize,index-1);
  }
  else{
    
    x[index]++;
    while(index != Asize){
      index++;
      x[index] = x[index-1]+1;
    }
  }
}


void setup(){
  for(int i = 0; i < sizeofgraph; i++)
    graph[i] = new stack();

  graph[0] -> push(1);
  graph[0] -> push(3);
  graph[0] -> push(4);

  graph[1] -> push(2);
  graph[1] -> push(4);
  graph[1] -> push(0);

  graph[2] -> push(4);
  graph[2] -> push(5);
  graph[2] -> push(1);
  graph[2] -> push(3);
  
  graph[3] -> push(2);
  graph[3] -> push(4);
  graph[3] -> push(0);
  graph[3] -> push(5);
  
  graph[4] -> push(3);
  graph[4] -> push(2);
  graph[4] -> push(1);
  graph[4] -> push(5);

  graph[5] -> push(2);
  graph[5] -> push(3);
  graph[5] -> push(4);
}
