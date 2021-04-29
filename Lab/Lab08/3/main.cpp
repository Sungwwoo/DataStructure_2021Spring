#include <iostream>
#include <cmath>
using namespace std;

float SqrRoot_recursion(float number, float approx, float tol);
float SqrRoot_non_recursion(float number, float approx, float tol);

int main() {
    float number = 10.0;
    float tol = 1e-3;
    float approx = number / 2;
    cout << sqrt(number) << endl;
    cout << SqrRoot_recursion(number, approx, tol) << endl;;
    cout << SqrRoot_non_recursion(number, approx, tol) << endl;;

    return 0;
}

float SqrRoot_recursion(float number, float approx, float tol){
    if (fabs(approx * approx - number) <= tol)
        return approx;
    else
        return SqrRoot_recursion(number, (approx * approx + number)/ (2 * approx), tol);
}

float SqrRoot_non_recursion(float number, float approx, float tol){
    while (fabs(approx * approx - number) > tol){
        approx = (approx * approx + number)/ (2 * approx);
    }
    return approx;
}