#include <iostream>
#include "DoubleStack.h"
using namespace std;

DoubleStack::DoubleStack(){
    top_small = -1;
    top_big = 200;
}

void DoubleStack::Push(int data){
    if (IsFull()){
        throw FullStack();
    }
    if (data <= 1000){
        top_small ++;
        items[top_small] = data;
    }
    else{
        top_big --;
        items[top_big] = data;
    }
}

void DoubleStack::Print(){
    cout << "Lower Stack: " << endl;
    for (int i = top_small; i >=0; i --){
        cout << items[i] << " ";
    }
    cout << endl << "Higher Stack: " << endl;
    for (int i = top_big; i <200; i ++){
        cout << items[i] << " ";
    }
    cout << endl;
}

bool DoubleStack::IsFull() const{
    return (top_big == top_small + 1);
}