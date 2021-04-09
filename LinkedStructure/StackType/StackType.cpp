#include <new>
#include "StackType.h"

template <class ItemType>
struct NodeType{
    ItemType info;  // Stores information
    NodeType* next; // Stores an address of next node
};

template <class ItemType>
StackType<ItemType>::StackType(){     // Constructor
    topPtr = NULL;
}

template <class ItemType>
StackType<ItemType>::~StackType(){    // Destructor
    NodeType<ItemType>* tempPtr;
    while (topPtr != NULL){
        tempPtr = topPtr;
        topPtr = tempPtr->next;
        delete tempPtr;
    }
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem){
    if (IsFull())
        throw FullStack();
    else{
        // 새로운 노드 메모리 할당
        NodeType<ItemType>* location;
        location = new NodeType<ItemType>;
        // 노드의 info에 데이터 저장
        location->info = newItem;
        // 원래 top을 새 노드의 next에 저장
        location->next = topPtr;
        // 새 노드를 topPtr이 가리키도록 재설정
        topPtr = location;
    }
}

template <class ItemType>
void StackType<ItemType>::Pop(){
    if (IsEmpty())
        throw EmptyStack();
    else{
        NodeType<ItemType>* tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template <class ItemType>
ItemType StackType<ItemType>::Top(){
    if (IsEmpty())
        throw EmptyStack();
    else{
        return topPtr->info;
    }
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const{
    return (topPtr == NULL);
}

template <class ItemType>
bool StackType<ItemType>::IsFull() const{
    NodeType<ItemType>* location;
    try{
        // 새 노드가 정상적으로 할당되고 삭제되면 false
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        // 새 노드 할당 과정에서 bad_alloc 발생하면 true (메모리 가득 참)
        return true;
    }
}

