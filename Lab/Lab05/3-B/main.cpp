#include <iostream>
#include "QueType.h"
using namespace std;


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
   
    if (queue1.Identical(queue2))
        cout << "Two queues are equal" << endl;
    else
        cout << "Two queues are not equal" << endl;

    return 0;
}
