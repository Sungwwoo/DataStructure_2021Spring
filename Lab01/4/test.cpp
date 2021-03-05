#include <iostream>
#include "SquareMatrix.h"
using namespace std;

int main(){
	SquareMatrix matrix1;
	SquareMatrix matrix2;
	SquareMatrix matrix3;
	SquareMatrix matrix4;

	// Testing MakeEmpty
	matrix1.MakeEmpty(0); 
	matrix2.MakeEmpty(2); 
	matrix3.MakeEmpty(2); 	
	matrix4.MakeEmpty(51);
	matrix4.MakeEmpty(50);

	matrix1.Print();	// No output
	matrix2.Print();
	matrix4.Print();
	
	// Testing StoreValue
	matrix2.StoreValue(1, 1, 5);
	matrix2.StoreValue(1, 2, 5);
	matrix2.StoreValue(2, 1, 5);
	matrix2.StoreValue(2, 2, 5);
	matrix3.StoreValue(1, 1, 2);
	matrix3.StoreValue(1, 2, 2);
	matrix3.StoreValue(2, 1, 2);
	matrix3.StoreValue(2, 2, 2);

	matrix1.Print();	// No output
	matrix2.Print();
	matrix3.Print();

	// Testing Add
	matrix4.MakeEmpty(2);
	matrix4.Add(matrix2, matrix3);
	matrix4.Print();

	// Testing Subtract
	matrix4.MakeEmpty(2);
	matrix4.Subtract(matrix3, matrix2);
	matrix4.Print();

	// Testing Copy
	matrix4.MakeEmpty(2);
	matrix4.Copy(matrix2);
	matrix4.Print();

	return 0;
			
}