#include <iostream>
#include "unsorted.h"
#include "sorted.h"
using namespace std;

int main(){
	int listLength;
	int number;

	ItemType item;
	UnsortedType A;
	UnsortedType B;
	SortedType C;

	A.ResetList();
	B.ResetList();
	C.ResetList();
	cin >> listLength;
	for (int i = 0; i < listLength; i ++){
		cin >> number;
		item.Initialize(number);
		A.InsertItem(item);
	}

	for (int i = 0; i < listLength; i ++){
		cin >> number;
		item.Initialize(number);
		B.InsertItem(item);
	}
	
	ItemType fromA, fromB;
	for (int i = 0; i < listLength; i ++){
		A.GetNextItem(fromA);
		B.GetNextItem(fromB);
		C.InsertItem(fromA + fromB);
	}

	ItemType data;
	for (int i = 0; i < listLength; i ++){
		C.GetNextItem(data);
		data.Print();
	}

	return 0;
}