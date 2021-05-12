#include <iostream>
#include "TreeType.h"
using namespace std;


int main(){
    TreeType tree;
    int n;
    cin >> n;

    int item;
    for (int i = 0; i < n; i++){
        cin >> item;
        tree.InsertItem(item);
    }

    int m;
    cin >> m;
    
    bool finished;
    for (int i = 0; i < m; i++){
        tree.DeleteMin();
    }

    cout << tree.LeafCount() << endl;

    return 0;
}