#include <iostream>
#include "QueType.h"
using namespace std;

bool Identical(QueType& queue1, QueType& queue2);

int main(){
    QueType queue1(9);
    QueType queue2(9);
    int itemList1[9] = {2, 6, 7, 4, 5, 6, 10, 15, 3};
    int itemList2[9] = {2, 6, 7, 4, 5, 6, 12, 15, 3};

    bool equal = true;
    
    for (int i = 0; i < 9; i ++){
        queue1.Enqueue(itemList1[i]);
        queue2.Enqueue(itemList2[i]);
    }

    equal = Identical(queue1, queue2);
    
    if (equal)
        cout << "Two queues are equal" << endl;
    else
        cout << "Two queues are not equal" << endl;

    return 0;
}

bool Identical(QueType& queue1, QueType& queue2) {
    int item1, item2;
    while (!queue1.IsEmpty()) {
        queue1.Dequeue(item1);
        queue2.Dequeue(item2);
        cout << item1 << ", " << item2 << endl;
        if (item1 != item2)
            return false;
    }
    return true;
}