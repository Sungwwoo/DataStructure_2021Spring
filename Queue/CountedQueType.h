#ifndef __COUNTEDQUETYPE_H__
#define __COUNTEDQUETYPE_H__

#include "QueType.h"
template<class ItemType>
class CountedQueType: public QueType{
public:
    CountedQueType(int max);
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    int LengthIs() const;
private:
    int length;
};

#endif