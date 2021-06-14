#include "BubbleSort.h"

void BubbleDown(Student values[], int startIndex, int endIndex){
    for (int index = startIndex; index < endIndex; index++)
        if (strcmp(values[index].getName(), values[index + 1].getName()) > 0)
            Swap(values[index], values[index+1]);
}

void BubbleSort(Student values[], int numValues){
    int current = 0;

    while (current < numValues - 1){
        BubbleDown(values, current, numValues -1);
        current++;
    }
}