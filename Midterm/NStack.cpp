#include <iostream>
#include "NStack.h"

using namespace std;

NStack::NStack(void)
{
	data = NULL;
}

NStack::NStack(NStack& another)
{
	ItemType* ptr1;
	ItemType* ptr2;
	if (another.data == NULL)
		data = NULL;
	else {
		data = new ItemType;
		data->item = another.data->item;
		data->next = NULL;
		data->back = NULL;
		ptr1 = another.data->next;
		ptr2 = data;
		while (ptr1 != NULL) {
			ptr2->next = new ItemType;
			ptr2->next->back = ptr2;
			ptr2 = ptr2->next;
			ptr2->item = ptr1->item;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
	}
}

NStack::~NStack()
{
	ItemType* t, * s;
	t = data;
	while (t != NULL) {
		s = t;
		t = t->next;
		delete s;
	}
}

void	NStack::print(string title)
{
	ItemType* t;

	cout << title << ": ";
	t = data;
	while (t != NULL) {
		cout << t->item << ' ';
		t = t->next;
	}
	cout << endl;
}

bool	NStack::nmPush(int f, int b, string it)
{
	ItemType* location;
	ItemType* newItem = new ItemType;
	ItemType* tail = new ItemType;
	tail->next = NULL;
	tail->back = newItem;
	newItem->item = it;
	if (f == 0 && b == 0) {
		if (data == NULL) {
			data = newItem;
			newItem->back = NULL;
			newItem->next = tail;
			return true;
		}
		else {
			newItem->back = NULL;
			newItem->next = data;
			data->back = newItem;
			data = newItem;
			return true;
		}
	}
	else {
		location = data;
		if (data == NULL)
			return false;
		for (int i = 0; i < f; i++) {
			if (location->next == NULL)
				return false;
			else
				location = location->next;
		}
		for (int i = 0; i < b; i++) {
			if (location->back == NULL)
				return false;
			else
				location = location->back;
		}
		if (location->back == NULL) {
			data = newItem;
			location->back = newItem;
			newItem->back = NULL;
			newItem->next = location;
			return true;
		}
		else {
			newItem->back = location->back;
			newItem->next = location;
			location->back->next = newItem;
			location->back = newItem;
			return true;
		}
		
	}
}

bool	NStack::nmPop(int f, int b, string& it)
{
	ItemType* location;
	ItemType* tempItem;
	if (data == NULL)
		return false;
	if (f == 0 && b == 0) {
		tempItem = data;
		it = data->item;
		data = data->next;
		data->back = NULL;
		delete tempItem;
		return true;
	}
	else {
		location = data;
		for (int i = 0; i < f; i++) {
			if (location->next == NULL)
				return false;
			else
				location = location->next;
		}
		for (int i = 0; i < b; i++) {
			if (location->back == NULL)
				return false;
			else
				location = location->back;
		}
		if (location->back == NULL) {
			tempItem = location;
			it = location->item;
			data = location->next;
			location->next->back = NULL;
			delete tempItem;
			return true;
		}
		else {
			tempItem = location;
			it = location->item;
			location->back->next = location->next;
			location->next->back = location->back;
			delete tempItem;
			return true;
		}
	}
}