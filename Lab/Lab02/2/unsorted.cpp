// Implementation file for Unsorted.h

#include "unsorted.h"
UnsortedType::UnsortedType()
{
  length = 0;
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}

void UnsortedType::DeleteItem_a(ItemType item){
  bool deleted = false;
  for (int i = 0; i < length && !deleted; i++){
    if (item.ComparedTo(info[i]) == EQUAL){
      // Delete the item
      info[i] = info[length - 1];
      length--;
      // Change the value of deleted
      deleted = true;
    }
  }
}
void UnsortedType::DeleteItem_c(ItemType item){
  int i = 0;
  while (i < length){
    if (item.ComparedTo(info[i]) == EQUAL){
      // Delete the item
      info[i] = info[length - 1];
      // After deleting, check the value of position i again (do not change the value of i)
      // Decrease the value of length
      length--;
    }
    else{
      // Increase the value of i to see next item
      i++;
    }
  }
}