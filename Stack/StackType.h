#ifndef __STACKTYPE_H__
#define __STACKTYPE_H__

const int MAX_ITEMS = 5;

template<class ItemType>
class StackType{
public:
	StackType();
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(ItemType item);
	void Pop();
	ItemType Top() const;
private:
	int top;	// Stack Pointer
	ItemType items[MAX_ITEMS];
};

class FullStack{};
class EmptyStack{};

#endif