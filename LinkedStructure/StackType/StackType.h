// DINAMICALLY LINKED STACK
#ifndef __STACKTYPE_H__
#define __STACKTYPE_H__

class FullStack{};
class EmptyStack{};

template <class ItemType>
struct NodeType;

template <class ItemType>
class StackType{
public:
    StackType();    // Constructor
    ~StackType();   // Destructor
    void Push(ItemType newItem);
    void Pop();
    ItemType Top();
    bool IsEmpty() const;
    bool IsFull() const;
private:
    NodeType<ItemType>* topPtr;
};

#endif