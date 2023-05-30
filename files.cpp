#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
void printHello(ostream& output) {
	output << "hello world!" << endl;
}

void openInputFile(ifstream& inFile) {
	string filename;
	cout << "What input filename? ";
	cin >> filename;
	inFile.open(filename);
	while (!inFile) { //inFile is tested for failure
		cout << "BAD FILENAME!" << endl;
		cout << "What input filename? ";
		cin >> filename;
		inFile.clear(); //not, strictly, necessary since C++ 11
		inFile.open(filename);
	}
}

int main() {
	ifstream inFile;
	openInputFile(inFile);
	int num;
	int sum = 0;
	while (inFile >> num) //read in one integer and then check to see if the inFile failed
		sum += num;
	cout << "The sum of the numbers in the file is: " << sum << endl;

	cout << "What filename? ";
	string filename;
	cin >> filename;

	ofstream outFile;
	outFile.open(filename);

	printHello(outFile);
	printHello(cout);
	cout << "Done!" << endl;
}