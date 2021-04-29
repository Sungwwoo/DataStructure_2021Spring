// 재귀 버전의 경우 같은 계산을 여러 번 반복될 수 있고 함수 콜이 추가로 발생하기 때문에 성능 향상 측면에서는 불리하다.

#include <iostream>
using namespace std;

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main(){
    cout << Fibonacci_recursive(10) << endl;
    cout << Fibonacci_non_recursive(10) << endl;

    return 0;
}


int Fibonacci_recursive(int n){
    if (n <= 1)
        return n;
    else
        return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}

int Fibonacci_non_recursive(int n){
    int current;
    int prev;
    int temp;

    if (n <= 1)
        return n;
    else{
        prev = 0;
        current = 1;
        for (int i = 2; i <= n; i++){
            temp = prev + current;
            prev = current;
            current = temp;
        }
        return temp;
    }
}