#include <new>
#include "QueType.h"

template <class ItemType>
struct NodeType{
    ItemType info;  // Stores information
    NodeType* next; // Stores an address of next node
};

template <class ItemType>
QueType<ItemType>::QueType(){
    qFront = NULL;
    qRear = NULL;
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
    if (IsFull())
        throw FullQueue();
    else{
        NodeType<ItemType>* newNode;
        newNode = new NodeType<ItemType>;
        newNode->info = newItem;
        newNode->next = NULL;
        // 첫 번째 Enqueue일 경우 front를 newNode에 연결
        if (qRear == NULL)  
            qFront = newNode;
        // 원래 있던 노드의 next에 새 노드 연결
        else    
            qRear->next = newNode;
        qRear = newNode;
    } 
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item){
    if (IsFull())
        throw FullQueue();
    else{
        NodeType<ItemType>* tempPtr;
        tempPtr = qFront;
        item = tempPtr->info;
        qFront = tempPtr->next;
        // 남은 item 없을 경우
        if (qFront == NULL)
            qRear = NULL;
        delete tempPtr;
    }
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

template <class ItemType>
QueType<ItemType>::~QueType(){
    MakeEmpty();
}