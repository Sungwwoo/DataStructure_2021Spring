#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main(){
	UnsortedType<int> list1, list2, list3;
	int item1[7] = {1, 3, 5, 7, 9, 11, 13};
    int item2[7] = {2, 4, 6, 8, 10, 12, 14};
	
    for (int i = 0; i < 7; i ++){
        list1.InsertItem(item1[i]);
        list2.InsertItem(item2[i]);
    }
	list1.ResetList();
	list2.ResetList();
	
	int data;
	for (int i = 0; i < list1.LengthIs(); i ++){
		list1.GetNextItem(data);
		cout << data << " ";
	}
	cout << endl;
	for (int i = 0; i < list2.LengthIs(); i ++){
		list2.GetNextItem(data);
		cout << data << " ";
	}
	cout << endl;
	list1.MergeLists(list2, list3);
	list3.ResetList();
	for (int i = 0; i < list3.LengthIs(); i ++){
		list3.GetNextItem(data);
		cout << data << " ";
	}
	return 0;
}