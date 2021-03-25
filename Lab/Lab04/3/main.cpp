#include <iostream>
#include "DoubleStack.h"
using namespace std;

int main(){
    DoubleStack stack;
    for (int i = 0; i < 200; i ++){
        if (i % 2 == 0)
            stack.Push(i / 2);
        else
            stack.Push(1001 + i / 2);
    }

    stack.Print();

    return 0;
}