#include <iostream>
#include "TreeType.h"
using namespace std;

int main(){
    TreeType a;
    a.InsertItem(6);
    a.InsertItem(3);
    a.InsertItem(2);
    a.InsertItem(8);
    a.InsertItem(7);

    if (a.IsBST())
        cout << "BST" << endl;
    else
        cout << "NO" << endl;

    return 0;
}