#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main(){
    UnsortedType<int> list1, list2, list3;
    int item1[5] = {3, 3, 1, 2, 3};
    int item2[5] = {3, 2, 1, 3, 3};
    int item3[5] = {1, 2, 3, 4, 3};

    for (int i = 0; i < 5; i++){
        list1.InsertItem(item1[i]);
        list2.InsertItem(item2[i]);
        list3.InsertItem(item3[i]);
    }
    int data;
    list1.ResetList();
    list2.ResetList();
    list3.ResetList();
    for (int i = 0; i < list1.LengthIs(); i++){
        list1.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl;
    list1.DeleteItem(3);
    list1.ResetList();
    for (int i = 0; i < list1.LengthIs(); i++){
        list1.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl << endl;
    
    for (int i = 0; i < list2.LengthIs(); i++){
        list2.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl;
    list2.DeleteItem(3);
    list2.ResetList();
    for (int i = 0; i < list2.LengthIs(); i++){
        list2.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < list3.LengthIs(); i++){
        list3.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl;
    list3.DeleteItem(3);
    list3.ResetList();
    for (int i = 0; i < list3.LengthIs(); i++){
        list3.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl << endl;

    return 0;
}