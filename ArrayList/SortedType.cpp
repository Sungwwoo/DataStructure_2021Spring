#include "SortedType.h"

SortedType::SortedType(){
    length = 0;
}

bool SortedType::IsFull() const{
    return (length == MAX_ITEMS);
}

int SortedType::LengthIs() const{
    return length;
}

void SortedType::RetrieveItem(ItemType& item, bool& found){
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

void SortedType::InsertItem(ItemType item){
    bool moreToSearch;
    int location = 0;

    moreToSearch = (location < length);
    while (moreToSearch){
        switch(item.ComparedTo(info[location])){
            case LESS:
                moreToSearch = false;
                break;
            case GREATER:
                location ++;
                moreToSearch = (location < length);
                break;
        }
    }

    for (int index = length; index > location; index --){
        info[index] = info[index - 1];
    }

    info[location] = item;
    length ++;
}

void SortedType::DeleteItem(ItemType item){
    
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL){
        location ++;   
    }

    for (int index = location + 1; index > location; index ++){
        info[index - 1] = info[index];
    }

    length --;
}

void SortedType::ResetList(){
    currentPos = -1;
}

void SortedType::GetNextItem(ItemType& item){
    currentPos ++;
    item = info[currentPos];
}