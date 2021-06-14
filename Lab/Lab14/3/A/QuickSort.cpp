#include "QuickSort.h"


void Split(Student* values[], int first, int last, int& splitPoint){
    Student splitVal =  *values[first];
    int saveFirst = first;
    bool onCorrectSide;

    first++;
    do{
        onCorrectSide = true;

        while (onCorrectSide){
            if (strcmp(values[saveFirst]->getName(),values[first]->getName()) < 0){
                onCorrectSide = false;
            }
            else{
                first++;
                onCorrectSide = (first <= last);
            }
        }

        onCorrectSide = (first <= last);

        while (onCorrectSide){
            if (strcmp(values[saveFirst]->getName(),values[first]->getName()) > 0){
                onCorrectSide = false;
            }
            else{
                last--;
                onCorrectSide = (first <= last);
            }
        }

        if (first < last){
            Swap(values[first], values[last]);
            first++;
            last--;
        }

    }while (first <= last);

    splitPoint = last;
    Swap(*values[saveFirst], *values[splitPoint]);
}


void QuickSort(Student* ary[], int first, int last){
    if (first < last){
        int splitPoint;

        Split(ary, first, last, splitPoint);

        QuickSort(ary, first, splitPoint - 1);
        QuickSort(ary, splitPoint + 1, last);
    }
}