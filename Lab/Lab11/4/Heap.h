#pragma once

template<class ItemType>
struct NodeType{
  int timeStamp;
  ItemType info;
};

template <class ItemType>
void Swap(NodeType<ItemType>& one, NodeType<ItemType>& two);


template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
  NodeType<ItemType>* elements;   // Array to be allocated dynamically
  int numElements;
};



template <class ItemType>
void Swap(NodeType<ItemType>& one, NodeType<ItemType>& two)
{
  NodeType<ItemType> temp;
  temp.info = one.info;
  temp.timeStamp = one.timeStamp;
  one.info = two.info;
  one.timeStamp = two.timeStamp;
  two.info = temp.info;
  two.timeStamp = temp.timeStamp;
}  

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;
  
  if (bottom > root)
  {
    parent = (bottom-1) / 2;
    if (elements[parent].timeStamp < elements[bottom].timeStamp)
    {
      Swap(elements[parent], elements[bottom]);
      ReheapUp(root, parent);
    }
  }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild].timeStamp <= elements[rightChild].timeStamp)
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root].timeStamp < elements[maxChild].timeStamp)
    {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(maxChild, bottom);
    }
  }
}

