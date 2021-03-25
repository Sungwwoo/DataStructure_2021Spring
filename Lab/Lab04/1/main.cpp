#include <iostream>
#include "StackTType.h"
using namespace std;

int main(){
    StackType<int> stack;

    for (int i = 1; i <= 6; i ++){
        stack.Push(i);
    }

    while (!stack.IsEmpty()){
        int result = stack.Top();
        stack.Pop();
        cout << result << endl;
    }
    return 0;
}