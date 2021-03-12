#include <fstream>
using namespace std;

int main(int argc, char* argv[]){

	ifstream input_file(argv[1]);
	ofstream output_file(argv[2]);
	
	char ch;
	
	while (!input_file.eof()){
		input_file.get(ch);				// Reaching the EOF sets eofbit and failbit.
		if (input_file.fail())			// Check EOF and error through failbit
			break;
		if (ch == '\n') 				// if ch == '\n', add '\r\n' to text file
			output_file << '\r' << ch;
		else
			output_file << ch;
	}

	input_file.close();
	output_file.close();

	return 0;
}