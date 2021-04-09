#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main(){
    UnsortedType<int> list1;
    int item[5] = {3, 2, 5, 6, 1};

    for (int i = 0; i < 5; i++)
        list1.InsertItem(item[i]);
    
    list1.DeleteItem(4);
    list1.ResetList();
    int data;
    for (int i = 0; i < list1.LengthIs(); i++){
        list1.GetNextItem(data);
        cout << data << " ";
    }
    cout << endl;
    
    return 0;
}