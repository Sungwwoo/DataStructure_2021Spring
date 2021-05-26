#include <iostream>
#include "PQType.h"
using namespace std;

int main(){
    PQType<int> pqueue(50);

    pqueue.Enqueue(56);
    pqueue.Enqueue(27);
    pqueue.Enqueue(42);
    pqueue.Enqueue(26);
    pqueue.Enqueue(15);
    pqueue.Enqueue(3);
    pqueue.Enqueue(19);
    pqueue.Enqueue(25);
    pqueue.Enqueue(24);
    pqueue.Enqueue(5);
    
    int x, y, z;

    pqueue.Enqueue(28);
    pqueue.Enqueue(2);
    pqueue.Enqueue(40);
    
    pqueue.Dequeue(x);
    pqueue.Dequeue(y);
    pqueue.Dequeue(z);

    cout << "Output must be \n56 42 40" << endl;


    cout << x << " " << y << " " << z << endl;

    /* Heap 연산과 비교*/
    // Heap을 통해 구현하면 O(logN)
    // Sorted list를 통해 구현하면 
    // 우선순위에 따라 정렬되어야 하므로 O(N)

    return 0;
}
