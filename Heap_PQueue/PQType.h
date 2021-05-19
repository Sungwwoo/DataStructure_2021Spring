#pragma once
#include <new>
#include "HeapType.h"

class FullQP{};
class EmptyQP{};

template <class ItemType>
class PQType{
public:
    PQType(int);
    ~PQType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
private:
    int length;
    HeapType<ItemType> items;
    int maxItems;
};

template <class ItemType>
PQType<ItemType>::PQType(int max){
    maxItems = max;
    items.elements = new ItemType[max];
    length = 0;
}

template <class ItemType>
PQType<ItemType>::~PQType(){
    delete[] items.elements;
}

template <class ItemType>
void PQType<ItemType>::MakeEmpty(){
    length = 0;
}

template <class ItemType>
bool PQType<ItemType>::IsEmpty() const{
    return length == 0;
}

template <class ItemType>
bool PQType<ItemType>::IsFull() const{
    return length == maxItems;
}

template <class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item){
    if (IsEmpty())
        throw EmptyQP();
    else{
        item = items.elements[0];
        items.elements[0] = items.elements[length - 1];
        length--;
        ReheapDown(0, length - 1);
    }
}

template <class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem){
    if (IsFull())
        throw FullQP();
    else{
        length++;
        items.elements[length - 1] = newItem;
        items.ReheapUp(0, length - 1);
    }
}