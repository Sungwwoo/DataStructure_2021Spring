#include <iostream>
#include "StackTType.h"
using namespace std;

int main(){
    StackType<int> stack1;
    StackType<int> stack2;
    StackType<int> tempStack;

    stack1.Push(9);
    stack1.Push(8);
    stack1.Push(4);
    stack1.Push(7);
    stack1.Push(5);
    stack1.Push(3);

    while (!stack1.IsEmpty()){
        int data = stack1.Top();
        stack1.Pop();
        tempStack.Push(data);
    }

    while (!tempStack.IsEmpty()){
        int data = tempStack.Top();
        tempStack.Pop();
        stack1.Push(data);
        stack2.Push(data);
    }

    cout << "Stack 1: ";
    while (!stack1.IsEmpty()){
        int result = stack1.Top();
        stack1.Pop();
        cout << result << " ";
    }
    cout << endl;
    
    cout << "Stack 2: ";
    while (!stack2.IsEmpty()){
        int result = stack2.Top();
        stack2.Pop();
        cout << result << " ";
    }
    cout << endl;

    return 0;
}