#include <iostream>
#include <random>
#include "StackType.h"
using namespace std;

int main(){
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 50);
    StackType<int> stack;
    int temp;
    for (int i = 0; i <= 6; i ++){
        temp = distribution(generator);
        cout << temp << " ";
        stack.Push(temp);
    }
    cout << endl << endl;
    while (!stack.IsEmpty()){
        temp = stack.Top();
        stack.Pop();
        cout << temp << " ";
    }

    cout << endl;
    // 최우선순위 원소: time stamp가 가장 큰 원소

    // push: time stamp 증가시키고 enqueue
    // pop: time stamp 가장 큰 원소 dequeue, time stamp 감소시킴

    // 4장의 push, pop: array를 이용
    // array 마지막 원소에 바로 접근해서 push, pop -> O(1)
    // Priority Queue를 이용한 경우 모두 O(logN)
    return 0;
}