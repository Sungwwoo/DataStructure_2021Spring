#include <iostream>
#include "matrix.h"
using namespace std;

Matrix compute(Matrix& A, Matrix& B, Matrix& C){
	// TODO
	Matrix result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.matrix[i][j] = 3 * A.matrix[i][j] + 2 * B.matrix[i][j] - 5 * C.matrix[i][j];
		}
	}
	return result;
}

int main(){
	int a, b, c, d;
	int e, f, g, h;
	int i, j, k, l;

	cout << "A: ";
	cin >> a >> b >> c >> d;
	cout << "B: ";
	cin >> e >> f >> g >> h;
	cout << "C: ";
	cin >> i >> j >> k >> l;

	Matrix A(a, b, c, d);
	Matrix B(e, f, g, h);
	Matrix C(i, j, k, l);

	Matrix D;

	D = compute(A, B, C);

	int result = D.sum();

	cout << result;

	return 0;
}