#include <iostream>
#include "sorted.h"
using namespace std;

void MergeList(SortedType list1, SortedType list2, SortedType& result);

int main(){
	SortedType s_list1, s_list2, s_list3;
	ItemType item1, item2, item3, item4, item5, item6, item7;

	item1.Initialize(11);
	item2.Initialize(5);
	item3.Initialize(3);
	item4.Initialize(4);
	item5.Initialize(12);
	item6.Initialize(2);
	item7.Initialize(1);

	s_list1.InsertItem(item1);
	s_list1.InsertItem(item2);
	s_list1.InsertItem(item3);
	s_list2.InsertItem(item4);
	s_list2.InsertItem(item5);
	s_list2.InsertItem(item6);
	s_list2.InsertItem(item7);
	MergeList(s_list1, s_list2, s_list3);

	ItemType data;
	for (int i = 0; i < s_list3.LengthIs(); i ++){
		s_list3.GetNextItem(data);
		data.Print();
	}
	return 0;
}

void MergeList(SortedType list1, SortedType list2, SortedType& result){
	// 리스트 current position 초기화
	list1.ResetList();
	list2.ResetList();
	result.ResetList();

	// result에 item 넣기
	ItemType item;
	for (int i = 0; i < list1.LengthIs(); i++){
		list1.GetNextItem(item);
		result.InsertItem(item);
	}

	for (int i = 0; i < list2.LengthIs(); i++){
		list2.GetNextItem(item);
		result.InsertItem(item);
	}
}