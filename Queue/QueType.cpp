#include "QueType.h"

template<class ItemType>
QueType<ItemType>::QueType(){
    maxQue = 4;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType [maxQue];
}

template<class ItemType>
QueType<ItemType>::QueType(int max){
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType [maxQue];
}

template<class ItemType>
QueType<ItemType>::~QueType(){
    delete[] items;
}

template<class ItemType>
void QueType<ItemType>::MakeEmpty(){
    front = maxQue - 1;
    rear = maxQue - 1;
}

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const{
    return rear == front;
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const{
    return (rear + 1) % maxQue == front;
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem){
    if (IsFull)
        throw FullQueue();
    rear = (rear + 1) % maxQue;
    item[rear] = newItem;
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item){
    if (IsEmpty)
        throw EmptyQueue();
    front = (front + 1) % maxQue;
    item = items[front];
}