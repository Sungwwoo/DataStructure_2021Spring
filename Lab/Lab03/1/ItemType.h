// The following declarations and definitions go into file 
// ItemType.h. 
#pragma once
#include <fstream>
const int MAX_ITEMS = 10;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print() const;
  void Initialize(int number);
private:
  int value;
};
 
