#include "CountedQueType.h"

template<class ItemType>
CountedQueType<ItemType>::CountedQueType(int max): QueType(max){
    length = 0;
}

template<class ItemType>
void CountedQueType<ItemType>::Enqueue(ItemType newItem){
    try{
        QueType::Enqueue(newItem);
        length ++;
    }
    catch(FullQueue)
        throw FullQueue();
}

template<class ItemType>
void CountedQueType<ItemType>::Dequeue(ItemType& item){
    try{
        QueType::Dequeue(item);
        length --;
    }
    catch(EmptyQueue)
        throw EmptyQueue();
}

template<class ItemType>
int CountedQueType<ItemType>::LengthIs() const{
    return length;
}