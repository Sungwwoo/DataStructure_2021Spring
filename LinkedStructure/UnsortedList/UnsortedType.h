#pragma once

template <class ItemType>
struct NodeType;

template <class ItemType>
class UnsortedType{
public:
    UnsortedType();
    ~UnsortedType();

    bool IsFull() const;
    int LengthIs() const;

    void MakeEmpty();

    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);

private:
    NodeType<ItemType>* listData;
    int length;
    NodeType<ItemType>* currentPos;
};
