#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main(){
    int items[4] = {1, 3, 2, 5};
    UnsortedType<int> list;
    for (int i = 0; i < 4; i++){
        list.InsertItem(items[i]);
    }

    list.PrintSumSquares();

    return 0;
}