#define MAX_SIZE 50
// Structure: N by N square integer matrix
class SquareMatrix{
private:
	int matrix[50][50];
	int matrixSize;
public:
	void MakeEmpty(int n);
	// Function : Initializes the size of matrix to n by n, and set the values to zero
	// Pre		: n must be less than, or equal to 50
	// Post		: n by n matrix containing zeros
	void StoreValue(int i, int j, int value);
	// Function	: Stores value into ith row, jth column
	// Pre		: Initialized matrix must exist, and i and j's value must be between 0 to 49
	// Post		: Value stored in ith row, jth column
	void Add(SquareMatrix mat1, SquareMatrix mat2);
	// Function	: Adds matrix mat2 to self
	// Pre		: All operands has been initialized
	// Post		: self = mat1 + mat2
	void Subtract(SquareMatrix mat1, SquareMatrix mat2);
	// Function	: Subtracts matrix mat2 from self
	// Pre		: All operands has been initialized
	// Post		: self = mat1 - mat2
	void Copy(SquareMatrix mat2);
	// Function	: Copies self to mat2
	// Pre		: mat2 has been initialized
	// Post		: self = mat2

	void Print() const;
	// Function	: Prints self
	// Pre		: Matrix has been initialized
	// Post		: matrix printed
};