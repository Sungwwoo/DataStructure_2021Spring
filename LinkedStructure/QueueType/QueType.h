// DINAMICALLY LINKED Que
#ifndef __QUETYPE_H__
#define __QUETYPE_H__

class FullQue{};
class EmptyQue{};

template <class ItemType>
struct NodeType;

template <class ItemType>
class QueType{
public:
    QueType();    // Constructor
    ~QueType();   // Destructor
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    void MakeEmpty();
private:
    NodeType<ItemType>* qFront;
    NodeType<ItemType>* qRear;
};



#endif