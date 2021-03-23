#include <iostream>
#include "sorted.h"
using namespace std;

int main(){
	SortedType list1;

	int N;
	cout << "Input N: "; cin >> N;

	cout << "Input list Item: ";
	ItemType item;
	int value;
	for (int i = 0; i < N; i ++){
		// insert item to list 1
		cin >> value;
		item.Initialize(value);
		list1.InsertItem(item);
	}
	cout << endl;
	
	while(1){
		int X;
		cout << "Input X: "; cin >> X;

		if (X == 0){
			// TODO
			list1.PrintAll();
			break;
		}

		int Y;
		cout << "Input Y: "; cin >> Y;

		// list1에 X가 존재하는지 찾고 존재하면 Y로 바꿈
		ItemType itemX;
		ItemType itemY;
		itemX.Initialize(X);
		itemY.Initialize(Y);

		bool found = false;
		list1.RetrieveItem(itemX, found);

		if (found){
			list1.DeleteItem(itemX);
			list1.InsertItem(itemY);
		}

		cout << "Operation completed." << endl << endl; 
	}

	return 0;
}