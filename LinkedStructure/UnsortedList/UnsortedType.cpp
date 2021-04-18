#include <new>
#include "UnsortedType.h"

template <class ItemType>
struct NodeType{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType(){
    length = 0;
    listData = NULL;
}
template <class ItemType>
bool UnsortedType<ItemType>::IsFull() const{
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
int UnsortedType<ItemType>::LengthIs() const{
    return length;
}

template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty(){
    NodeType<ItemType>* tempPtr;

    while(listData != NULL){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found){
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    
    while((location != NULL) && !found){
        if (item == location->info;){
            found = true;
            item = location->info;
        }
        else{
            location = location->next;
        }
    }
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item){
    NodeType<ItemType>* location;
    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    if (item == listData->info){
        tempLocation = location;
        listData = listData->next;
    }
    else{
        while(item != location->next->info){
            location = location->next;
        }
        tempLocation = location->next;
        location->next = location->next->next;
    }

    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList(){
    currentPos = NULL;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item){
    if (currentPos == NULL){
        currentPos = listData;
    }
    else{
        currentPos = currentPos->next;
    }

    item = currentPos->info;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType(){
    MakeEmpty();
}