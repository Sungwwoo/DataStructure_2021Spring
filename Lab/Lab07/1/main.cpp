#include <iostream>
#include "SortedType.h"
using namespace std;

int main(){
    SortedType<int> list1;

    int numOfItem; cin >> numOfItem;
    int item;
    for (int i = 0; i < numOfItem; i++){
        cin >> item;
        list1.InsertItem(item);
    }

    int listLength = list1.LengthIs();
    list1.ResetList();
    for (int i = 0; i < listLength; i++){
        list1.GetNextItem(item);
        cout << item << " ";
    }
    cout << endl;

    list1.PrintReverse();

    return 0;
}