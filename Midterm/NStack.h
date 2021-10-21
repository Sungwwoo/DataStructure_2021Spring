#pragma once
#include <string>

using namespace std;

struct ItemType {
	string	item;
	ItemType* next;
	ItemType* back;
};

class NStack {

	ItemType* data;
public:
	NStack();
	NStack(NStack&);
	~NStack();
	bool	nmPush(int, int, string);
	bool	nmPop(int, int, string&);
	void	print(string);
};
