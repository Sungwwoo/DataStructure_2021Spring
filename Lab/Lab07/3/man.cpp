#include <iostream>
#include "TextEditor.h"
using namespace std;

int main(){
    TextEditor text;
    text.GoToTop();
    ItemType line1[80] = "line1";
    ItemType line2[80] = "line2";
    ItemType line3[80] = "line3";
    ItemType line4[80] = "line4";
    text.InsertItem(line1);
    text.InsertItem(line2);
    text.GoToTop();
    text.InsertItem(line3);
    text.GoToBottom();
    text.InsertItem(line4);
    ItemType* output;
    text.ResetList();
    text.GetNextItem(output);
    for (int i = 0; output[i] != '\0'; i++){
        cout << output[i];
    }
    cout << endl;
    text.GetNextItem(output);
    for (int i = 0; output[i] != '\0'; i++){
        cout << output[i];
    }
    cout << endl;
    text.GetNextItem(output);
    for (int i = 0; output[i] != '\0'; i++){
        cout << output[i];
    }
    cout << endl;
    text.GetNextItem(output);
    for (int i = 0; output[i] != '\0'; i++){
        cout << output[i];
    }
    cout << endl;
    return 0;
}