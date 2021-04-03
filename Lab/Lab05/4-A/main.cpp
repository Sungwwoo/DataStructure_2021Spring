#include <iostream>
#include <chrono>
#include <random>
#include "QueType.h"
using namespace std;

int Length(QueType& queue);

int main(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, 100);

    QueType queue1;
    int randomValue;
    cout << "Enqueue: " << endl;
    for (int i = 0; i < 120; i ++){
        randomValue = distribution(generator);
        cout << randomValue << " ";
        queue1.Enqueue(randomValue);
    }
    cout << endl;

    cout << "Length is: " << Length(queue1) << endl;

    return 0;
}

int Length(QueType& queue){
    QueType tempQueue;
    int count = 0;
    int item = 0;
    while(!queue.IsEmpty()){
        queue.Dequeue(item);
        tempQueue.Enqueue(item);
        count ++;
    }

    while(!tempQueue.IsEmpty()){
        tempQueue.Dequeue(item);
        queue.Enqueue(item);
    }
    
    return count;
}