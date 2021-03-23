// The following declarations and definitions go into file 
// ItemType.h. 
#ifndef __ITEMTYPE_H__
#define __ITEMTYPE_H__

#include <fstream>
const int MAX_ITEMS = 10;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void PrintItem() const;
  void Initialize(int number);
private:
  int value;
};
 
#endif