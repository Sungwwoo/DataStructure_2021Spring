#include <fstream>
using namespace std;

int main(){

	ofstream output_file1("unix_LF.txt");
	output_file1 << "Hello\nWorld\nby Sungwoo.";
	output_file1.close();

	ofstream output_file2("mac_CR.txt");
	output_file2 << "Hello\rWorld\rby Sungwoo.";
	output_file2.close();

	ofstream output_file3("windows_CRLF.txt");
	output_file3 << "Hello\r\nWorld\r\nby Sungwoo.";
	output_file3.close();
	return 0;
}