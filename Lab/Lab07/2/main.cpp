#include <iostream>
#include "StackType.h"
using namespace std;

int main(){
    StackType list1, list2;
    for (int i = 0; i < 5; i++){
        list1.Push(i);
    }

    list1.Copy(list2);

    return 0;
}