#include <iostream>
#include "SquareMatrix.h"
using namespace std;

void SquareMatrix::MakeEmpty(int n){
	if (n > MAX_SIZE){
		cout << "Integer n must be smaller than 50." << endl;
		return;
	}
	matrixSize = n;
	int i = 0;
	int j = 0;
	for (i=0; i<matrixSize; i++)
		for(j=0; j<matrixSize; j++)
			matrix[i][j] = 0;
	cout << "MakeEmpty completed." << endl;
}
void SquareMatrix::StoreValue(int i, int j, int value){
	matrix[i - 1][j - 1] = value;
	cout << "StoreValue completed." << endl;
}
void SquareMatrix::Add(SquareMatrix mat1, SquareMatrix mat2){
	int i = 0;
	int j = 0;
	for (i=0; i<matrixSize; i++)
		for(j=0; j<matrixSize; j++)
			matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];
	cout << "Add completed." << endl;
}
void SquareMatrix::Subtract(SquareMatrix mat1, SquareMatrix mat2){
	int i = 0;
	int j = 0;
	for (i=0; i<matrixSize; i++)
		for(j=0; j<matrixSize; j++)
			matrix[i][j] = mat1.matrix[i][j] - mat2.matrix[i][j];
	cout << "Subtract completed." << endl;
}
void SquareMatrix::Copy(SquareMatrix mat2){
	int i = 0;
	int j = 0;
	for (i=0; i<matrixSize; i++)
		for(j=0; j<matrixSize; j++)
			matrix[i][j] = mat2.matrix[i][j];
	cout << "Copy completed." << endl;
}

void SquareMatrix::Print() const{
	int i = 0;
	int j = 0;
	for (i=0; i<matrixSize; i++){
		cout << "| ";
		for(j=0; j<matrixSize; j++){
			cout << matrix[i][j] << " ";
		}
		cout << "|" <<endl;
	}
	cout << endl;
}