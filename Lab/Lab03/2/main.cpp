#include <iostream>
using namespace std;

int BinarySearch(int [], int, int);

int main(){
	int list[10] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
	int result = BinarySearch(list, sizeof(list)/sizeof(list[0]), 11);
	cout << list[result] << endl;
	result = BinarySearch(list, sizeof(list)/sizeof(list[0]), 7);
	cout << list[result] << endl;
	result = BinarySearch(list, sizeof(list)/sizeof(list[0]), 3);
	cout << list[result] << endl;

	return 0;
}

int BinarySearch(int list[], int len, int value){
	int first = 0;
    int last = len - 1;
    int mid;

    while (first <= last){
        mid = (first + last) / 2;

        if (value == list[mid])
            return mid;
        else{
            if (value < list[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
    }

	// return -1; 		// A
	return first;	// 크거나 같은 값
	// return last;		// 작거나 같은 값
}