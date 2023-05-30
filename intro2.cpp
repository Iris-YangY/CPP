#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Hello world!" << endl;
	cout << "What is your name? ";
	string name;
	getline(cin,name);

	int age;
	cout << "What is your age?";
	cin >> age;

	string place;
	cout << "Where do you live?";
	cin.ignore(9999, '\n'); //skip 9999 characters or the first newline character
	getline(cin,place);

	int years=100;
	cout << "How many years have you lived there?";
	cin >> years; // years changes to user's input

	cout << "Name: " << name << endl
		<< "Age: " << age << endl
		<< "Residence: " << place << endl
		<< "Years: " << years << endl;
	cout << "First initial: " << name[0] << endl;
	//cout << "First three letters: " << name[0:3] << endl; //CANNOT DO THIS!!!!!!
	cout << "First three letters: " << name[0]<<name[1]<<name[2] << endl;
	cout << "First three letters: " << name.substr(0,3) << endl;

	if (age > 21)
		cout << 'A';
	else if (age > 18)
		cout << 'B';
	else
		cout << 'C';

	if (age > 21) cout << 'A'; else if (age > 18) cout << 'B'; else cout << 'C';

	if (age > 21) 
		cout << 'A'; 
	else 
		if (age > 18) 
			cout << 'B'; 
		else 
			cout << 'C';
	switch (age) {
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 21: cout << "Have a drink." << endl;
	case 18: cout << "Buy a lotto ticket." << endl;
		break;
	default: cout << "Happy Birthday!" << endl;
	}

	int grade;
	cout << "What is your numeric grade? ";
	cin >> grade;
	char letterGrade;
	switch (grade) {
	case 100:
	case 99:
	case 98:
	case 97:
	case 96:
	case 95:
	case 94:
	case 93:
	case 92:
	case 91:
	case 90:letterGrade = 'A';
		break;
	case 89:
	case 88:
	case 87:
	case 86:
	case 85:
	case 84:
	case 83:
	case 82:
	case 81:
	case 80:letterGrade = 'B';
		break;
	case 79:
	case 78:
	case 77:
	case 76:
	case 75:
	case 74:
	case 73:
	case 72:
	case 71:
	case 70:letterGrade = 'C';
		break;
	default:letterGrade = 'F';
	}

}
