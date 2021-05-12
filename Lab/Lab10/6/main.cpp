#include <iostream>
#include "UnsortedType.h"
#include "TreeType.h"
using namespace std;

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list);

int main(){
    UnsortedType<int> list;
    for (int i = 1; i <= 7; i++){
        list.InsertItem(i);
    }

    TreeType tree;
    
    return 0;
}


bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list){
    int list_length = list.LengthIs();
    int tree_length = tree.LengthIs();

    if (list_length != tree_length)
        return false;
    else{
        ItemType item;
        bool found;

        list.ResetList();
        for (int i = 0; i < list_length; i++){
            list.GetNextItem(item);
            tree.RetrieveItem(item, found);
            if (!found) // 일치하지 않음
                return false;
        }

        return true;
    }
}