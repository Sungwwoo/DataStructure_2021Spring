#include <iostream>
#include <chrono>
#include <random>
#include "QueType.h"
using namespace std;

int main(){

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(10, 99);

    int queueSize = 20;
    QueType queue1(queueSize);
    int randomValue;
    cout << "Enqueue: " << endl;
    for (int i = 0; i < queueSize-2; i ++){
        randomValue = distribution(generator);
        cout << randomValue << " ";
        queue1.Enqueue(randomValue);
    }
    cout << endl;
    cout << "MinDequeue: " << endl;
    int item;
    for (int i = 0; i < 4; i ++){
        queue1.MinDequeue(item);
        cout << item << " ";
    }
    cout << endl;cout << "Enqueue: " << endl;
    for (int i = 0; i < 6; i ++){
        randomValue = distribution(generator);
        cout << randomValue << " ";
        queue1.Enqueue(randomValue);
    }
    cout << endl;
    cout << "Dequeue: " << endl;
    for (int i = 0; i < queueSize; i ++){
        queue1.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;
    return 0;
}