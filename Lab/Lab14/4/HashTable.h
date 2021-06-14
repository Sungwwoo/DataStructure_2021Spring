#include "Student.h"

const int MAX_ITEMS = 2000;

template <class ItemType>
class HashTable{
    public:
        HashTable();
        HashTable(ItemType emptyKey);
        int Hash(char* key) const;
        void RetrieveItem(ItemType& item, bool& found);
        void InsertItem(ItemType item);
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


int getIntFromString(char* key){
    int sum = 0;
    int len = strlen(key);
    if (len & 2 == 1)
        len ++;
    for (int j = 0; j < len; j +=2)
        sum = (sum + 100 * key[j] + key[j+1]) % 19937;
    return sum;
}
template <class ItemType>
int HashTable<ItemType>::Hash(char* key) const{
    return (getIntFromString(key) % MAX_ITEMS);
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
    while (!(info[location] == emptyItem))
        location = (location + 1) % MAX_ITEMS;

    info[location] = item;
    length++;
}