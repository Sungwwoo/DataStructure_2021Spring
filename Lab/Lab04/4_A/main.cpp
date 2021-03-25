// Test driver
#include <iostream>
#include <fstream>
#include "StackType.h"
using namespace std;

void ReplaceItem(StackType &stack, int oldItem, int newItem);

int main(){
  StackType stack;
  stack.Push(2);
  stack.Push(3);
  stack.Push(2);
  stack.Push(3);
  stack.Push(3);

  ReplaceItem(stack, 3, 4);

  int item;
  while(!stack.IsEmpty()){
    item = stack.Top();
    stack.Pop();
    cout << "Item: " << item << endl;
  }
}

void ReplaceItem(StackType &stack, int oldItem, int newItem){
  StackType tempStack;
  ItemType tempItem;
  while(!stack.IsEmpty()){
    tempItem = stack.Top();
    stack.Pop();
    if (tempItem == oldItem){
      tempStack.Push(newItem);
    }
    else{
      tempStack.Push(tempItem);
    }
  }
  while(!tempStack.IsEmpty()){
    tempItem = tempStack.Top();
    tempStack.Pop();
    stack.Push(tempItem);
  }
}