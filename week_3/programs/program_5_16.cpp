// This program writes data to a file
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	ofstream outPutFile;

	// open output file
	outPutFile.open("demofile.txt");

	cout << "Now writing data to the file.\n";

	// Write four names to the file
	outPutFile << "Bach\n";
	outPutFile << "Beethoven\n";
	outPutFile << "Mozart\n";
	outPutFile << "Schubert\n";

	// Close the file
	outPutFile.close();

	cout << "Done.\n";
	
	return 0;
}