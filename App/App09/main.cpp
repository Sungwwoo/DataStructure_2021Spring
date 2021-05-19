#include <iostream>
#include <string>
#include "TreeType.h"
using namespace std;

int main(){
    TreeType tree;
    string in;
    getline(cin, in);

    int item;
    bool found = false;
    
    for (int i = 0; i < in.length(); i++){
        if (isdigit(in[i]))
            item = in[i];
        else
            continue;
        if (item == -1){
            tree.DeleteLeaf();
        }
        tree.RetrieveItem(item, found);
        if (!found)
            tree.InsertItem(item);
        else
            tree.DeleteItem(item);
    }

    cout << tree.LeafCount() << endl;
    
    return 0;
}