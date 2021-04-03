#include <iostream>
#include <chrono>
#include <random>
#include "QueType.h"
using namespace std;

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

    cout << "Length is: " << queue1.Length() << endl;

    return 0;
}