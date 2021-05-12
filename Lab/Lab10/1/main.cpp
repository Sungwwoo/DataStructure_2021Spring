#include <iostream>
#include "TreeType.h"
using namespace std;


int main(){
    TreeType tree;
    int in;
    for (int i = 0; i < 7; i++){
        cin >> in;
        tree.InsertItem(in);
    }

    tree.DeleteItem(6);
    
    return 0;
}