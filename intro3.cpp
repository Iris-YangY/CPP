#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void helloFunc() {
	cout << "hello world";
}

int countFunc() {
	return 10;
}

string getName() {
	cout << "What is your name? ";
	string name;
	cin >> name;
	return name;
}
double getWeight() {
	double weight;
	cout << "What is your weight? ";
	cin >> weight;
	return weight;
}

int add(int a, int b) {
	return a + b;
}

int addone(int a, int b = 1) {
	return a + b;
}

void valueExample(int x) {
	cout << "Memory location of x  : " << &x << endl;
	cout << x << endl;
	x += 1;
}
void referenceExample(int& x) {
	cout << "Memory location of x  : " << &x << endl;
	cout << x << endl;
	x += 1;
}
void printVec(const vector<int>& v) {
	//v[0] = 100; //illegal because of const
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}

const double MATH_PI = 3.1415927; //all caps with underscores

int main() {
	cout << MATH_PI << endl;
	//const double pi = 3.1415927;
	//pi = 400;
	helloFunc();
	countFunc();
	int val;
	val = countFunc();
	val = addone(100);
	val = addone(100, 200);
	val = 10;
	cout << endl;
	cout << "Memory location of val: " << &val << endl;
	valueExample(val);
	cout << "Val after valueExample: " << val << endl;

	val = 10;
	cout << "Memory location of val: " << &val << endl;
	referenceExample(val);
	cout << "Val after referenceExample: " << val << endl;

	//val = addone(b = 200, a = 100); //positional parameters ONLY in C++
	/*

	int numLoops = 0;
	cout << "How many? ";
	cin >> numLoops;
	int count = 0;
	vector<int> v;
	while (count < numLoops) {
		int hiddenVar;
		cout << "Hello world!" << endl;
		count++;
		v.push_back(count);
		hiddenVar = count;
	}
	//cout << hiddenVar << endl; //hiddenVar doesn't exist out here!

	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	for (int count = 0; count < numLoops; count++)
		cout << "Hello world!" << endl;

	for (int count=0, j=100; count < numLoops; count++, j *= 10)
		cout << "Hello world" << j << endl;
	//cout << j << endl; //j doesn't exist here!
	*/
}