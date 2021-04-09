#include <iostream>
#include "StackType.h"
using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem);

int main(){
    StackType stack;
    stack.Push(2);
    stack.Push(3);
    stack.Push(2);
    stack.Push(3);
    stack.Push(3);

    ReplaceItem(stack, 2, 4);

    int item;
    while(!stack.IsEmpty()){
        item = stack.Top();
        stack.Pop();
        cout << "Item: " << item << endl;
    }

    return 0;
}

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem){
    StackType temp_stack;   // 백업용 스택
    ItemType temp_item;     // top을 받는 ItemType
    
    while(!stack.IsEmpty()){
        temp_item = stack.Top();
        stack.Pop();
        if (temp_item == oldItem){
            temp_stack.Push(newItem);
        }
        else{
            temp_stack.Push(temp_item);
        }
    }

    while(!temp_stack.IsEmpty()){
        temp_item = temp_stack.Top();
        temp_stack.Pop();
        stack.Push(temp_item);
    }
}