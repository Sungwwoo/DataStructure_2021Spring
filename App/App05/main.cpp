#include <iostream>
#include "QueType.h"
using namespace std;

int main(){
    int N;
    cin >> N;
    ItemType item;
    QueType card(N);
    QueType discarded(N - 1);

    for (int i = 0; i < N; i ++){
        card.Enqueue(i + 1);
    }

    while (!discarded.IsFull()){
        card.Dequeue(item);
        discarded.Enqueue(item);
        card.Dequeue(item);
        card.Enqueue(item);
    }

    while (!discarded.IsEmpty()){
        discarded.Dequeue(item);
        cout << item << " ";
    }
    card.Dequeue(item);
    cout << item << endl;

    return 0;
}