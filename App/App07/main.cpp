#include <iostream>
using namespace std;

void unzip(char* str, int& length);

int main(){
    int length = 0;
    char s[50] = "33(562(71(9)))";
    unzip(s, length);
    cout << endl;
    cout << length << endl;

    return 0;
}

void unzip(char* str, int& length){
    if (str[0] == ')' || str[0] =='\0')
        return;
    else if (str[1] == '('){
        int max = str[0] -'0';
        for (int i = 0; i < max; i ++)
            unzip(str + 2, length);
        return;
    }
    else{
        cout << str[0];
        length++;
        unzip(str + 1, length);
    }
}