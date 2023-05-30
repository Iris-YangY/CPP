int main() {
	ifstream jab("jabberwocky");
	if (!jab){
		cerr << "failed to open jabberwocky";
		exit(1);
	}

	string something;
	//jab >> something;
	//getline(jab, something);
	'''getline only reads one line of the file'''
	//cout << something << endl;
	
	//loop to get the string
	while (jab >> something){
		cout << something << endl;
	}
	'''while there are some tokens to be read, the loop will run until there\'s nothing to be read'''

	vector<string> lines;
	while (getline(jab, line)){
		lines.push_back(line);
	}
	jab.close();

	for (size_t i = 0; i < lines.size(); ++i) {
		for (size_t j = 0; j < lines[i].size(), ++j) {
			cout << lines[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	coust int ROWS = 10;
	coust int COLS = 10;
	vector<vector<int>> mat;

	for (int r=0; r<ROWS, ++r) {
		mat.push_back(vector<int>(COLS));
		for (int c=0, c<COLS; ++c) {
			mat[r][c] = r*ROWS+c;
		}
	}

	for (int r=0; r<ROWS, ++r) {
		for (int c=0, c<COLS, ++c) {
			cout <<mat[r][c] << " ";
		}
		cout << endl;
	}
}

void addOne(int value){
	//value+=1;
	++value;
}

int addOneV2(int value) {
	++value;
	return value;
}

void addOneRef(int& value) {
	++value;
}

void printString(string aString){
	string aString = "some string";
	for (size_t i = 0; i < aString.size(); ++i) {
		cout << aString[i] << " ";
	}
	cout << endl;
}

void printString(const string& aString){
	string aString = "some string";
	for (size_t i = 0; i < aString.size(); ++i) {
		cout << aString[i] << " ";
		aString[i] = 'x';
	}
	cout << endl;
}

int main() {
	int x=17;

	addOne(x);
	cout<<x<<endl;

	x=addOneV2(x)
	cout << x <<endl;

	addOneRef(x);
	cout << x << endl;

	string s = "some string";
	for (size_t i = 0; i < s.size(); ++i) {
		cout<<s[i]<<" ";
	}
	cout <<endl;
}

struct Person {
	string name;
	int age;
};

void printPerson(const Person& somebody) {
	cout << somebody.name << ' ' << somebody.age << endl;
}
int main() {
	Person aPerson;
	aPerson.name = "Fred";
	aPerson.age = 19;

	//cout<<aPerson<<endl;
	cout << aPerson.name << ' ' << aPerson.age << endl;
	printPerson(aPerson);
	ifstream personStream('people');
	vector<Person> people;
	string name;
	int age;
	while(personStream >> name >>age) {
		Person somePerson{name, age};
		'''
		Person somePerson;
		somePerson.name = name;
		somePerson.age = age;
		'''
		people.push_back(somePerson);
	}
}