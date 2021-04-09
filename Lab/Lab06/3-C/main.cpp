#include <iostream>
#include "UnsortedType.h"
using namespace std;

void MergeLists(UnsortedType<int>& l_a, UnsortedType<int>& l_b, UnsortedType<int>& result);

int main(){
	UnsortedType<int> s_list1, s_list2, s_list3;
	int item1[7] = {1, 3, 5, 7, 9, 11, 13};
    int item2[7] = {2, 4, 6, 8, 10, 12, 14};
	
    for (int i = 0; i < 7; i ++){
        s_list1.InsertItem(item1[i]);
        s_list2.InsertItem(item2[i]);
    }
	
	int data;
	s_list1.ResetList();
	s_list2.ResetList();
	s_list3.ResetList();
	
	for (int i = 0; i < s_list1.LengthIs(); i ++){
		s_list1.GetNextItem(data);
		cout << data << " ";
	}
	cout << endl;
	for (int i = 0; i < s_list2.LengthIs(); i ++){
		s_list2.GetNextItem(data);
		cout << data << " ";
	}
	cout << endl;
	
	MergeLists(s_list1, s_list2, s_list3);

	for (int i = 0; i < s_list3.LengthIs(); i ++){
		s_list3.GetNextItem(data);
		cout << data << " ";
	}
	return 0;
}

void MergeLists(UnsortedType<int>& l_a, UnsortedType<int>& l_b, UnsortedType<int>& result){
	// 리스트 current position 초기화
	l_a.ResetList();
	l_b.ResetList();

	// result에 item 넣기
	int item;
	for (int i = 0; i < l_a.LengthIs(); i++){
		l_a.GetNextItem(item);
		result.InsertItem(item);
	}

	for (int i = 0; i < l_b.LengthIs(); i++){
		l_b.GetNextItem(item);
		result.InsertItem(item);
	}
}