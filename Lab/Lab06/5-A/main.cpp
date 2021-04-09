#include <iostream>
#include "SortedType.h"
using namespace std;

int main(){
    SortedType<int> list1;
    int item[7] = {3, 6, 3, 2, 1, 4, 5};

    for (int i = 0; i < 7; i++)
        list1.InsertItem(item[i]);

    int data;
    list1.ResetList();
    for (int i = 0; i < list1.LengthIs(); i++){
        list1.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl;
    list1.DeleteItem(6);

    list1.ResetList();
    for (int i = 0; i < list1.LengthIs(); i++){
        list1.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl;
    
    return 0;
}