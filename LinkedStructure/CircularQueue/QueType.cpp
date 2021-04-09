#include <new>
#include "QueType.h"

template <class ItemType>
struct NodeType{
    ItemType info;  // Stores information
    NodeType* next; // Stores an address of next node
};

template <class ItemType>
QueType<ItemType>::QueType(){
    qRear = NULL;
}
template <class ItemType>
QueType<ItemType>::~QueType(){
    NodeType<ItemType>* tempPtr;
}
template <class ItemType>
bool QueType<ItemType>::IsEmpty() const{
    return (qFront == NULL);
}
template <class ItemType>
bool QueType<ItemType>::IsFull() const{
    NodeType<ItemType>* location;
    try{
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
        return true;
}
template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem){
    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>;
    newNode->info = newItem;
     // qRear->next == front of queue
    // 첫 번째 Enqueue일 경우 front를 newNode에 연결
    if (qRear == NULL){
        newNode->next = newNode;
        qRear = newNode;
    }
    // 원래 있던 노드의 next에 새 노드 연결
    else{
        newNode->next = qRear->next;
        qRear->next = newNode;
    }
    qRear = newNode;
}
template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item){
    NodeType<ItemType>* tempPtr;
    tempPtr = qRear->next;
    item = tempPtr->info;
    qRear->next = tempPtr->next;
    delete tempPtr;
}
template <class ItemType>
void QueType<ItemType>::MakeEmpty(){
    NodeType<ItemType>* tempPtr;
    while(qFront != NULL){
        tempPtr = qFront;
        qFront = tempPtr->next;
        delete tempPtr;
    }
    qRear = NULL;
}