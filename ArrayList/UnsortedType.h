// Array-Based Unsorted List
#ifndef __UNSORTEDTYPE_H__
#define __UNSORTEDTYPE_H__

#include "ItemType.h"

class UnsortedType{
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
    
public:
    UnsortedType();
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);
};

#endif