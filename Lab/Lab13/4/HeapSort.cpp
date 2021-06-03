
#include "HeapSort.h"

void ReheapDown(Student values[], int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;
  bool reheaped = false;

  leftChild = root * 2 + 1;
  
  while (leftChild <= bottom && !reheaped){
    if (leftChild == bottom)
      maxChild = leftChild;
    else{
      rightChild = root * 2 + 2;
      maxChild = (values[leftChild] <= values[rightChild])? rightChild : leftChild;
    }

    if (values[root] < values[maxChild]){
      Swap(values[root], values[maxChild]);
      root = maxChild;
      leftChild = root * 2 + 1;
    }
    else
      reheaped = true;
  }
}

void HeapSort(Student values[], int numValues){
    int index;

    for (index = numValues / 2 - 1; index >= 0; index --)
        ReheapDown(values, index, numValues - 1);

    for (index = numValues - 1; index >= 1; index--){
        Swap (values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
}