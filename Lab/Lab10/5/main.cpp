#include <iostream>
#include "SortedType.h"
#include "TreeType.h"
using namespace std;

void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int> &list);

int main(){
    SortedType<int> sList;
    for (int i = 1; i <= 7; i++){
        sList.InsertItem(i);
    }

    TreeType tree;
    MakeTree(tree, sList);
    
    return 0;
}


void AddElement(TreeType& tree, int Array[], int from, int to){
    int mid;
    if (from <= to){
        mid = (from + to) / 2;
        tree.InsertItem(Array[mid]);
        AddElement(tree, Array, from, mid - 1);
        AddElement(tree, Array, mid + 1, to);
    }
}

void MakeTree(TreeType& tree, SortedType<int> &list){
    
    int length = list.LengthIs();
    int* array = new int [length];
    int item_info;
    int i;

    list.ResetList();

    for (i = 0; i < length; i++){
        list.GetNextItem(item_info);
        array[i] = item_info;
    }

    AddElement(tree, array, 0, length - 1);

    delete[] array;
}