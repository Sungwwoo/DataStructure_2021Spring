#include <iostream>
#include "QueType.h"
using namespace std;

void ReplaceItem(QueType<int>& queue, int oldItem, int newItem);

int main(){
    QueType<int> queue1;
    
    int items[9] = {2, 6, 7, 4, 5, 6, 10, 15, 6};
    cout << "Original queue: " << endl;
    for (int i = 0; i < 9; i ++){
        cout << items[i] << " ";
        queue1.Enqueue(items[i]);
    }
    cout << endl;

    ReplaceItem(queue1, 6, 20);

    cout << "Modified queue: " << endl;
    int item;
    for (int i = 0; i < 9; i ++){
        queue1.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;

    return 0;
}

void ReplaceItem(QueType<int>& queue, int oldItem, int newItem){
    QueType<int> tempQue;
    int tempItem;
    
    while (!queue.IsEmpty()){
        queue.Dequeue(tempItem);
        if (tempItem == oldItem){
            tempQue.Enqueue(newItem);
        }
        else{
            tempQue.Enqueue(tempItem);
        }
    }

    while (!tempQue.IsEmpty()){
        tempQue.Dequeue(tempItem);
        queue.Enqueue(tempItem);
    }

    return;
}