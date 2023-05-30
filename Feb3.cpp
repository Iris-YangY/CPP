#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
	string name;
	int age;
};

// fillPersonVector(personStream, people);
void fillPersonVector(ifstream personStream, vector<Person>& people) {
	string name;
	int age;
	while (personStream >> name >> age) {
		// Person someone;
		// someone.name = name;
		// someone.age = age;
		Person someone {name, age};
		people.push_back(someone);
	}
}

// display Person(name);
void displayPerson(const Person& aPerson) {
	cout << "Person name: " << aPerson.name << ", Person age: " << aPerson.age<<endl;
}

void displayPeople(const vector<Person>& somePeople){
	for (const Person& aPerson : somePeople) {
		displayPerson(aPerson);
	}
}

int main() {

	Person fred;

	// No default difinition for printing out a Person
	//cout << fred << endl;
	fred.name = "Fred";
	fred.age = 19;
	cout << "Person name: " << fred.name << ", Person age: " << fred.age<<endl;

	Person mary("Mary", 20);
	cout << "Person name: " << mary.name << ", Person age: " << mary.age<<endl;

	//if (fred == mary) {cout << "equal\n";}

	ifstream personStream("people.txt");
	if(!personstream) {
		cerr << "Failed to open people.txt\n";
		exit(1);
	}

	vector<Person> people;

	string name;
	int age;
	while (personStream >> name >> age) {
		// Person someone;
		// someone.name = name;
		// someone.age = age;
		Person someone {name, age};
		people.push_back(someone);
	}
	fillPersonVector(people)

	personStream.close();

	for (const Person& aPerson: people) {
		cout << "Person name: " << aPerson.name << ", Person age: " << aPerson.age<<endl;
		displayPerson(name);
	}

	displayPeople(people);

}

struct Word {
	string token;
	vector<int> positions;
};

int main() {
	vector<Word> words;

	ifstream ifs("jabberwocky");

	// Fill the vector
	int position = 0-;
	string token;
	while (ifs >> token) {
		//words.push_back(token);
		// find if token is already seen
		size_t where = findTokenInVector(words, token);

		// if not seen, then create a Word for this new token with its position
		Word aWord;

		// otherwise if seen
	}

	// Do something with the vector
}