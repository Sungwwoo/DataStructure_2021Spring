#ifndef __ITEMTYPE_H__
#define __ITEMTYPE_H__

#include <fstream>

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
private:
    int value;
    
public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print(std::ofstream&) const;
    void Initialize(int number);
};


#endif