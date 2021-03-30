#include <iostream>
#include "StackType.h"
using namespace std;

int main(){
    StackType inputList;
    StackType outputList;

    int N, value;
    cin >> N;
    for (int i = 0; i < N; i ++){
        cin >> value;
        inputList.Push(value);
    }

    int inputListItem;

    while (!inputList.IsEmpty()){
        inputListItem = inputList.Top();
        inputList.Pop();
        if (outputList.IsEmpty()){
            outputList.Push(inputListItem);
        }
        if (inputListItem > outputList.Top()){
            outputList.Push(inputListItem);
        }
        else
            continue;
        
    }

    int length = 0;
    while(!outputList.IsEmpty()){
        outputList.Pop();
        length ++;
    }
    cout << length << endl;
    return 0;
}