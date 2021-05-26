// Linked Stack ADT
#pragma once
#include <new>
#include "PQType.h"


class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};

template <class ItemType>
class StackType
{
public:

  StackType();
  // Class constructor.
  ~StackType();
  bool IsFull() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)
  bool IsEmpty() const;
  // Function: Determines whether the stack is empty.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)
  void Push(ItemType item);
  // Function: Adds newItem to the top of the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is full), FullStack exception is thrown;
  //     otherwise, newItem is at the top of the stack.
  void Pop();
  // Function: Removes top item from the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.
  ItemType Top();
  // Function: Returns a copy of top item on the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.


private:
  PQType<ItemType> pqueue;
  int timeStamp;
};


template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
  if (IsFull())
    throw FullStack();
  else
  {
    timeStamp++;
    NodeType<ItemType> newNode;
    newNode.info = newItem;
    newNode.timeStamp = timeStamp;
    pqueue.Enqueue(newNode);
    
  }
}
template <class ItemType>
void StackType<ItemType>::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
  if (IsEmpty())
    throw EmptyStack();
  else
  { 
    NodeType<ItemType> node;
    pqueue.Dequeue(node);
    timeStamp--;
  }
}
template <class ItemType>
ItemType StackType<ItemType>::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
  if (IsEmpty())
    throw EmptyStack();
  else{
    NodeType<ItemType> node;
    pqueue.Dequeue(node);
    pqueue.Enqueue(node);
    return node.info; 
  }
}
template <class ItemType>
bool StackType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the stack; false otherwise.
{
    return pqueue.IsEmpty();
}
template <class ItemType>
bool StackType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  return pqueue.IsFull();
}

template <class ItemType>
StackType<ItemType>::~StackType()
// Post: stack is empty; all pqueue have been deallocated.
{
    pqueue.MakeEmpty();
    timeStamp = 0;
}

template <class ItemType>
StackType<ItemType>::StackType()	// Class constructor.
{
    timeStamp = 0;
}

