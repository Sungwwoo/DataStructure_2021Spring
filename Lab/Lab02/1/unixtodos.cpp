#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

	ifstream input_file(argv[1]);
	ofstream output_file(argv[2]);
	

	char ch;

	while (!input_file.eof()){			// Repeat the loop until it is not t he EOF
		input_file.get(ch);
		if (input_file.fail())
			break;
		if (ch == 0x0D) 				// if ch == '\r', add '\n' 
			output_file << '\n';
		else
			output_file << ch;
	}

	input_file.close();
	output_file.close();

	return 0;
}