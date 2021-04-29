#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

#define MAX 20

int mat[MAX][MAX];

int NumPaths_A(int row, int col, int n){
    if ((row == n) || (col == n))
        return 1;
    else
        return NumPaths_A(row + 1, col, n) + NumPaths_A(row, col + 1, n);
}

int NumPaths_B(int row, int col, int n){
    if (mat[row-1][col-1] == -1){
        if ((row == n) || (col == n))
            return 1;
        else
            mat[row-1][col-1] = NumPaths_B(row + 1, col, n) + NumPaths_B(row, col + 1, n);
            return mat[row-1][col-1];
    }
    return mat[row-1][col-1];
}

int main(){

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j] = -1;
        }
    }
    steady_clock::time_point startTime;
	steady_clock::time_point endTime;
    startTime = steady_clock::now();
    cout << NumPaths_A(1, 1, MAX) << endl;
    endTime = steady_clock::now();
    cout << duration_cast<milliseconds>(endTime - startTime).count() << " ms" << endl;

    startTime = steady_clock::now();
    cout << NumPaths_B(1, 1, MAX) << endl;
    endTime = steady_clock::now();
    cout << duration_cast<nanoseconds>(endTime - startTime).count() << " ns" << endl;

    return 0;
}