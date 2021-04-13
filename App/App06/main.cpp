#include <iostream>
#include "StackType.h"
using namespace std;

int main(){
    StackType left_stack;   // 커서 왼쪽 문자
    StackType right_stack;  // 커서 오른쪽 문자

    char* input = new char[100];
    cin >> input;
    ItemType item;
    for (int i = 0; i < 100; i++){
        char c = input[i];
        
        if (c == NULL)
            break;
        switch (c) {
        case '<':
            if (!left_stack.IsEmpty()){
                // 커서 기준 왼쪽에 있는 문자를 right_stack으로 옮김
                item = left_stack.Top();
                right_stack.Push(item);
                // 커서가 왼쪽으로 한 칸 이동
                left_stack.Pop();
            }
            break;
        case '>':
            if(!right_stack.IsEmpty()){
                // 커서 기준 오른쪽에 있는 문자를 left_stack으로 옮김
                item = right_stack.Top();
                left_stack.Push(item);
                // 커서가 오른쪽으로 한 칸 이동
                right_stack.Pop();
            }
            break;
        case '-':
            if (!left_stack.IsEmpty()){
                // 커서 왼쪽에 있는 문자 삭제
                left_stack.Pop();
            }
            break;
        default: 
            left_stack.Push(c);
            break;
        }
    }

    while (!left_stack.IsEmpty()){
        // 커서 왼쪽에 있는 문자와 오른쪽에 있는 문자를 합침
        // left_stack에 있는 문자를 right_stack으로 이동
        item = left_stack.Top();
        left_stack.Pop();
        right_stack.Push(item);
    }

    while (!right_stack.IsEmpty()){
        // 문자 출력
        item = right_stack.Top();
        cout << item;
        right_stack.Pop();
    }

    cout << endl;

    return 0;
}