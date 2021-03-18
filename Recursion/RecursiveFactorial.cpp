#include <iostream>
using namespace std;

int Factorial (int n){
    if (n == 0) 
        return 1;
    else 
        return n * Factorial(n - 1);
}

int main(){
    cout << "1! = "; cout << Factorial(1) << endl;
    cout << "2! = "; cout << Factorial(2) << endl;
    cout << "3! = "; cout << Factorial(3) << endl;
    cout << "4! = "; cout << Factorial(4) << endl;
    cout << "9! = "; cout << Factorial(9) << endl;

    return 0;
}