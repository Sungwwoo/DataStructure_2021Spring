#ifndef __QUETYPE_H__
#define __QUETYPE_H__

class FullQueue{};
class EmptyQueue{};

template<class ItemType>
class QueType{
public:
    QueType();
    QueType(int max);
    ~QueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem); // Add item
    void Dequeue(ItemType& item);   // Remove and return item
private:
    int front;  // where items are removed
    int rear;   // where items are added
    ItemType* items;
    int maxQue; 
};

#endif