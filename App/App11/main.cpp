#include <iostream>
#include "QuickSort.h"
#include "HashTable.h"
using namespace std;

int main(){
    int N;
    cin >> N;

    Student emptyItem;
    emptyItem.InitValue(0, (char*)"EMPTY", -1);
    HashTable<Student> hs(emptyItem);
    int id, score;
    char name[50];
    Student item;
    for (int i = 0; i < N; i ++){
        cin >> id >> name >> score;
        item.InitValue(id, (char*)name, score);
        hs.InsertItem(item);
    }
    
    hs.PrintTable();

    return 0;
}