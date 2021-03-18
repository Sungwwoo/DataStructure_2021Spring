#include "UnsortedType.h"

UnsortedType::UnsortedType(){
    length = 0;
}

bool UnsortedType::IsFull() const{
    return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const{
    return length;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found){
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while (moreToSearch && !found){
        switch (item.ComparedTo(info[location])){
            case LESS:

            case GREATER:   
                location ++;
                moreToSearch = (location < length);
                break;

            case EQUAL:     
                found = true;
                item = info[location];
                break;
        }
    }
}

void UnsortedType::InsertItem(ItemType item){
    info[length] = item;
    length ++;
}

void UnsortedType::DeleteItem(ItemType item){
    /*  In array-based implementation, we do not actually remove the element.
    *   Instead, we cover it up with the element that previously followed it
    *   in case of the unsorted list.
    */  
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL){
        location ++;   
    }
    info[location] = info[length - 1];
    length --;
}

void UnsortedType::ResetList(){
    currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item){
    currentPos ++;
    item = info[currentPos];
}