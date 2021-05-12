#include <iostream>
#include "TreeType.h"
using namespace std;

int Smaller(TreeType tree, int value);

int main(){
    TreeType tree;
    int in;
    for (int i = 0; i < 7; i++){
        cin >> in;
        tree.InsertItem(in);
    }

    int value = 4;
    int result = Smaller(tree, value);

    cout << result << endl;

    return 0;
}

int Smaller(TreeType tree, int value){
    ItemType item;
    bool finished = false;
    int count = 0;

    tree.ResetTree(IN_ORDER);

    do {
        tree.GetNextItem(item, IN_ORDER, finished);

        if (item < value)
            count++;
        else
            finished = true;
    } while (!finished);

    return count;
}