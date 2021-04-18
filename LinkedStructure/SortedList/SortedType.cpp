#include <new>
#include "SortedType.h"

template <class ItemType>
struct NodeType{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
SortedType<ItemType>::SortedType(){
    length = 0;
    listData = NULL;
}
template <class ItemType>
bool SortedType<ItemType>::IsFull() const{
    NodeType<ItemType>* location;
    try{
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}

template <class ItemType>
int SortedType<ItemType>::LengthIs() const{
    return length;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty(){
    NodeType<ItemType>* tempPtr;

    while(listData != NULL){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found){
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    
    while((location != NULL) && !found){
        if (item > location->info;){
            location = location->next;
        }
        else if (item == location->info){
            found = true;
            item = location->info;
        }
    }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item){
  NodeType<ItemType>* newNode;  // pointer to node being inserted
  NodeType<ItemType>* predLoc;  // trailing pointer
  NodeType<ItemType>* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if (location->info < item)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType<ItemType>;
  newNode->info = item;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
          location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void SortedType<ItemType>::ResetList(){
    currentPos = NULL;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item){
  if (currentPos == NULL)
    currentPos = listData;
  item = currentPos->info; 
  currentPos = currentPos->next;
}

template <class ItemType>
SortedType<ItemType>::~SortedType(){
    MakeEmpty();
}