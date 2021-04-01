#include <iostream>
#include <chrono>
#include <random>
#include "QueType.h"
using namespace std;

int main(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, 100);


    QueType queue1(10);
    int randomValue;
    cout << "Enqueue: " << endl;
    for (int i = 0; i < 10; i ++){
        randomValue = distribution(generator);
        cout << randomValue << " ";
        queue1.Enqueue(randomValue);
    }
    cout << endl;
    cout << "Dequeue: " << endl;
    int item;
    for (int i = 0; i < 10; i ++){
        queue1.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;
    return 0;
}