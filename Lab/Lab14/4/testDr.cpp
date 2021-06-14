#include <iostream>
#include "Student.h"
#include "HashTable.h"
using namespace std;

int main(){
    Student stu[100];
    stu[0].InitValue(2003200111, (char*)"Lee", 3.0);
    stu[1].InitValue(2004200121, (char*)"Yang", 3.2);
    stu[2].InitValue(2005200132, (char*)"Kim", 2.7);

    HashTable<Student> ht(stu->EmptyKey());
    ht.InsertItem(stu[0]);
    ht.InsertItem(stu[1]);
    ht.InsertItem(stu[2]);

    char name[50];
    cin >> name;
    bool found;
    Student target;
    target.InitValue(0, name, 0);
    ht.RetrieveItem(target, found);
    target.Print(cout);

    return 0;
}