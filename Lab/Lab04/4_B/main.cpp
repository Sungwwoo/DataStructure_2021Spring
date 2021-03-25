// Test driver
#include <iostream>
#include <fstream>
#include "StackType.h"
using namespace std;


int main(){
  StackType stack;
  stack.Push(2);
  stack.Push(3);
  stack.Push(2);
  stack.Push(3);
  stack.Push(3);

  stack.ReplaceItem(3, 4);

  int item;
  while(!stack.IsEmpty()){
    item = stack.Top();
    stack.Pop();
    cout << "Item: " << item << endl;
  }
}