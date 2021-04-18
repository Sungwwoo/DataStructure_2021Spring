// Implementation file for StackType.h

#include <cstddef>
#include <new>
#include "StackType.h"
void StackType::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
  if (IsFull())
    throw FullStack();
  else
  {
    NodeType* location;
    location = new NodeType;
    location->info = newItem;
    location->next = topPtr;
    topPtr = location;
  }
}
void StackType::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
  if (IsEmpty())
    throw EmptyStack();
  else
  {  
    NodeType* tempPtr;
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}
ItemType StackType::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
  if (IsEmpty())
    throw EmptyStack();
  else
    return topPtr->info;  
}
bool StackType::IsEmpty() const
// Returns true if there are no elements on the stack; false otherwise.
{
    return (topPtr == NULL);
}
bool StackType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc)
  {
    return true;
  }
}

StackType::~StackType()
// Post: stack is empty; all items have been deallocated.
{
    NodeType* tempPtr;

    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

StackType::StackType()	// Class constructor.
{
    topPtr = NULL;
}

void StackType::Copy(StackType& anotherStack){
  NodeType* ptr1;
  NodeType* ptr2;

  
  if (topPtr == NULL){  // 빈 stack일 경우
    anotherStack.topPtr = NULL;
  }
  else{                 // 빈 stack 아닐 경우
    // topPtr에 새 노드 생성, 값 복사
    anotherStack.topPtr = new NodeType;
    anotherStack.topPtr->info = topPtr->info;
    // ptr1: host stack 위치
    ptr1 = topPtr->next;
    // ptr2: anotherStack 위치
    ptr2 = anotherStack.topPtr;
    while (ptr1 != NULL){
      // ptr2 다음에 노드 생성, 노드 연결, 값 복사
      ptr2->next = new NodeType;
      ptr2 = ptr2->next;
      ptr2->info = ptr1->info;
      // ptr1 다음 노드로 이동
      ptr1 = ptr1->next;
    }
    // anotherStack 마지막 노드 처리
    ptr2->next = NULL;
  }
}
