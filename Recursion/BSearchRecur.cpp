#include <iostream>
using namespace std;

int BSearchRecur(int ar[], int first, int last, int target);

int main(){
    int arr[] = { 1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) - 1, 7);
    if (idx == -1){
        cout << "Search Failed" << endl;
    }
    else{
        cout << "Target index: " << idx << endl;
    }

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) - 1, 4);
    if (idx == -1){
        cout << "Search Failed" << endl;
    }
    else{
        cout << "Target index: " << idx << endl;
    }
    return 0;
}

int BSearchRecur(int ar[], int first, int last, int target){
    int mid;
    if (first > last) return -1;

    mid = (first + last) / 2;

    if (ar[mid] == target) 
        return mid;
    else if (target < ar[mid])
        return BSearchRecur(ar, first, mid - 1, target);
    else
        return BSearchRecur(ar, mid + 1, last, target);
}