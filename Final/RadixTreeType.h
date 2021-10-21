#pragma once
struct	Node {
	int	info;
	Node* left;
	Node* right;
};

class	RadixTreeType {
	Node* root;
public:
	RadixTreeType();
	~RadixTreeType();
	bool	RetrieveItem(int);
	void	InsertItem(int);
	void	DeleteItem(int);
	void	print();
};
