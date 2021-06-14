#include "Student.h"

const int MAX_ITEMS = 2000;

template <class ItemType>
class HashTable{
    public:
        HashTable();
        HashTable(ItemType emptyKey);
        int Hash(int key) const;
        void RetrieveItem(ItemType& item, bool& found);
        void InsertItem(ItemType item);
        void PrintTable();
    private:
        ItemType info[MAX_ITEMS];
        ItemType emptyItem;
        int length;
};
template <class ItemType>
HashTable<ItemType>::HashTable(){
    ItemType temp;
    emptyItem = temp.EmptyKey();
    for (int i = 0; i <MAX_ITEMS; i++){
        info[i] = emptyItem;
    }
    length = 0;
}

template <class ItemType>
HashTable<ItemType>::HashTable(ItemType emptyKey){
    emptyItem = emptyKey;
    for (int i = 0; i <MAX_ITEMS; i++){
        info[i] = emptyItem;
    }
    length = 0;
}

template <class ItemType>
int HashTable<ItemType>::Hash(int key) const{
    if (key >= 95)
        return 0;
    else if (key >= 80)
        return 1;
    else if (key >= 65)
        return 2;
    else if (key >= 50)
        return 3;
    else
        return 4;
}

template <class ItemType>
void HashTable<ItemType>::RetrieveItem(ItemType& item, bool& found){
    int location;
    int startLoc;
    bool moreToSearch = true;

    startLoc = Hash(item.Key());
    location = startLoc;
    do {
        if (info[location] == item || info[location] == emptyItem)
            moreToSearch = false;
        else
            location = (location + 1) % MAX_ITEMS;

    } while (location < length);

    found = (info[location] == item);
    if (found)
        item = info[location];

}

template <class ItemType>
void HashTable<ItemType>::InsertItem(ItemType item){

	int location;
	location = Hash(item.Key());
	while(!(info[location] == emptyItem)) {
		location = (location + 1) % MAX_ITEMS;
	}
	info[location] = item;
	length++;
}

template <class ItemType>
void HashTable<ItemType>::PrintTable(){
    Student* temp;
    int location, count;
    for (int i = 0; i < 5; i++){
        location = i;
        count = 0;
        temp = new Student[MAX_ITEMS];
        while (!(info[location] == emptyItem)){
            if (Hash(info[location].Key()) == i){
                temp[count] = info[location];
                count ++;
            }
            location = (location + 1) % MAX_ITEMS;
        }
        if (count != 0){
            QuickSort(temp, 0, count - 1);
            for (int j = 0; j < count; j++){
                switch(i){
                    case 0: cout << "A: "; break;
                    case 1: cout << "B: "; break;
                    case 2: cout << "C: "; break;
                    case 3: cout << "D: "; break;
                    case 4: cout << "F: "; break;
                }
                cout << temp[j].getName() << " " << temp[j].Key() << endl;
            }
        }
        delete[] temp;
    }

    
}