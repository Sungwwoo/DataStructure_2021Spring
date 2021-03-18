#ifndef __SORTEDTYPE_H__
#define __SORTEDTYPE_H__

#include "ItemType.h"

class SortedType{
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
    
public:
    SortedType();
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);
};

#endif