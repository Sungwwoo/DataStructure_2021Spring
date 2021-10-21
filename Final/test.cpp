#include <iostream>
#include "RadixTreeType.h"

using namespace std;

int	main()
{
	int	data[] = { 95, 7, 15, 65, 984, 8, 4, 111, 2, 88, 985, 13 };
	RadixTreeType	tree;

	for (int i = 0; i < sizeof(data) / sizeof(int); i++)
		tree.InsertItem(data[i]);
	tree.print();
	cout << '\n';
	cout << "Retrieval Test:\n";
	cout << "\t " << 983 << ": " << tree.RetrieveItem(983) << endl;
	cout << "\t " << 777 << ": " << tree.RetrieveItem(777) << endl;
	cout << "\t " << 985 << ": " << tree.RetrieveItem(985) << endl;
	cout << "\t " << 12 << ": " << tree.RetrieveItem(12) << endl;
	cout << "\t " << 15 << ": " << tree.RetrieveItem(15) << endl;
	cout << "\t " << 13 << ": " << tree.RetrieveItem(13) << endl;
	cout << "\t " << 6 << ": " << tree.RetrieveItem(6) << endl;
	cout << "\t " << 111 << ": " << tree.RetrieveItem(111) << endl;

	tree.DeleteItem(4);
	tree.DeleteItem(7);
	cout << "After deleting 4 and 7:\n";
	tree.print();
	cout << '\n';
	cout << "Retrieval Test Again:\n";
	cout << "\t " << 983 << ": " << tree.RetrieveItem(983) << endl;
	cout << "\t " << 777 << ": " << tree.RetrieveItem(777) << endl;
	cout << "\t " << 985 << ": " << tree.RetrieveItem(985) << endl;
	cout << "\t " << 12 << ": " << tree.RetrieveItem(12) << endl;
	cout << "\t " << 15 << ": " << tree.RetrieveItem(15) << endl;
	cout << "\t " << 13 << ": " << tree.RetrieveItem(13) << endl;
	cout << "\t " << 6 << ": " << tree.RetrieveItem(6) << endl;
	cout << "\t " << 111 << ": " << tree.RetrieveItem(111) << endl;

	cout << "Delete 95\n";
	tree.DeleteItem(95);
	tree.print();

	return 0;
}
