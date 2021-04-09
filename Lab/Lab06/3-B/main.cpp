#include <iostream>
#include "SortedType.h"
using namespace std;

int main(){
	SortedType<int> s_list1, s_list2, s_list3;
	int item1[7] = {1, 3, 5, 7, 9, 11, 13};
    int item2[4] = {4, 8, 10, 14};
	
    for (int i = 0; i < 7; i ++){
        s_list1.InsertItem(item1[i]);
    }
	for (int i = 0; i < 4; i ++){
        s_list2.InsertItem(item2[i]);
    }
	
	s_list1.MergeLists(s_list2, s_list3);
	s_list3.ResetList();
	int data;
	for (int i = 0; i < s_list3.LengthIs(); i ++){
		s_list3.GetNextItem(data);
		cout << data << " ";
	}
	return 0;
}