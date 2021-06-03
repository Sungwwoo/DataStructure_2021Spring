#include "HeapSort.h"
void Swap(int& item1, int& item2)
// Post: Contents of item1 and item2 have been swapped.
{
  int tempItem;

  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}
void ReheapDown(int values[], int root, int bottom)
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

void HeapSort(int values[], int numValues){
    int index;


    for (index = numValues / 2 - 1; index >= 0; index --)
        ReheapDown(values, index, numValues - 1);


    for (index = numValues - 1; index >= 1; index--){
      Swap (values[0], values[index]);
      ReheapDown(values, 0, index - 1);


    }
}

int GetHeight(int values[], int start, int numValues){
  if(start > numValues / 2 - 1 || numValues == 1)
    return 0;
  
  int l_height = GetHeight(values, start * 2 + 1, numValues);
  int r_height = GetHeight(values, start * 2 + 2, numValues);
  return (l_height > r_height)? l_height + 1: r_height + 1;
}

void GetHeightSum(int values[], int numValues){
  int index, sum = 0;
  for (index = 0; index < numValues; index++){
    sum += GetHeight(values, index, numValues - 1);
  }
  std::cout << "Sum of Heights = " << sum << std::endl;
}

