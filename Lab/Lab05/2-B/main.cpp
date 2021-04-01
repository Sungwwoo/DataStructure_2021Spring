#include <iostream>
#include "QueType.h"
using namespace std;



int main(){
    QueType queue1(9);
    QueType queue2(9);
    
    int items[9] = {2, 6, 7, 4, 5, 6, 10, 15, 6};
    cout << "Original queue: " << endl;
    for (int i = 0; i < 9; i ++){
        cout << items[i] << " ";
        queue1.Enqueue(items[i]);
    }
    cout << endl;

    queue1.ReplaceItem(6, 20);

    cout << "Modified queue: " << endl;
    int item;
    for (int i = 0; i < 9; i ++){
        queue1.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;

    return 0;
}