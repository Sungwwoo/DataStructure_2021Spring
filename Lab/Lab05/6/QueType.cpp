#include "QueType.h"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max;
  minimum_pos = 0;
  length = 0;
  front = 0;
  rear = -1;
  items = new ItemType[maxQue];
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 500;
  minimum_pos = 0;
  length = 0;
  front = 0;
  rear = -1;
  items = new ItemType[maxQue];
  
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  length = 0;
  front = 0;
  rear = -1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (length == 0);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return (length == maxQue);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{ 

  int count = 0;
  int currentPos = front;
  while (count <= length){
    // check -1
    if (items[currentPos] != -1){
      count++;
      currentPos = (currentPos + 1) % maxQue;
    }
    else{
      items[currentPos] = newItem;
      currentPos = front;

      // find minimum_pos and return
      ItemType tempItem = items[currentPos];
      int count2 = 0;
      while (count2 < length){
        if (items[currentPos] == -1 || items[currentPos] > tempItem){
          currentPos = (currentPos + 1) % maxQue;
        }
        else if (items[currentPos] <= tempItem){
          tempItem = items[currentPos];
          minimum_pos = currentPos;
          currentPos = (currentPos + 1) % maxQue;
        }
        count2++;
      }
      return;
    }
  }
  
  // if there is no -1, enqueue normally
  if (IsFull())
    throw FullQueue();
  
  length++;
  if (length == 1){
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
    minimum_pos = rear;
  }
  else{
    if (newItem < items[minimum_pos]){
      rear = (rear + 1) % maxQue;
      items[rear] = newItem;
      minimum_pos = rear;
    }
    else{
      rear = (rear + 1) % maxQue;
      items[rear] = newItem;
    }
  }
  // find minimum_pos
  currentPos = front;
  for (int i = 0; i < length; i++){
    if (items[currentPos] == -1)
      continue;
    else if (items[currentPos] < items[minimum_pos])
      minimum_pos = currentPos;
    currentPos++;
  }
  
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
    else
  {
    length--;
    item = items[front];
    front = (front + 1) % maxQue;
  }
}

void QueType::MinDequeue(ItemType& item){
  item = items[minimum_pos];
  items[minimum_pos] = -1;
  
  // find minimum_pos
  int currentPos = front;
  ItemType tempItem = items[currentPos];
  int count = 0;
  while (count < length){
    if (items[currentPos] == -1 | items[currentPos] > tempItem){
      currentPos = (currentPos + 1) % maxQue;
      if (tempItem == -1){
        tempItem = items[currentPos];
      }
    }
    else if (items[currentPos] <= tempItem){
      tempItem = items[currentPos];
      minimum_pos = currentPos;
      currentPos = (currentPos + 1) % maxQue;
    }
    count++;
  }
}