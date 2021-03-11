#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	cout << "Number of parameters: " << argc << endl;

	for (int i = 0; i < argc; i ++){
		cout << i << "-th argument: " << argv[i] << endl;
	}
	
	return 0;
}