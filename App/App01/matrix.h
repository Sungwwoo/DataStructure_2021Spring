#pragma once
using namespace std;  // ostream?? ????? ?????


class Matrix {

public:

	Matrix() {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				matrix[i][j] = 0;
			}
		}

	}

	Matrix(int ff, int fs, int sf, int ss) {

		matrix[0][0] = ff;
		matrix[0][1] = fs;
		matrix[1][0] = sf;
		matrix[1][1] = ss;
	}

	int sum(){
		return matrix[0][0] + matrix[0][1] + matrix[1][0] + matrix[1][1];
	}

	friend Matrix operator+(const Matrix& A, const Matrix& B){
		Matrix result;
		for (int i = 0; i < 2; i ++){
			for (int j = 0; j < 2; j ++){
				result.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
			}
		}		
		return result;
	}

	friend Matrix operator-(const Matrix& A, const Matrix& B){
		Matrix result;
		for (int i = 0; i < 2; i ++){
			for (int j = 0; j < 2; j ++){
				result.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
			}
		}		
		return result;
	}

	friend Matrix operator*(const int A, const Matrix& B){
		Matrix result;
		for (int i = 0; i < 2; i ++){
			for (int j = 0; j < 2; j ++){
				result.matrix[i][j] = A * B.matrix[i][j];
			}
		}		
		return result;
	}

private:

	int matrix[2][2];

};