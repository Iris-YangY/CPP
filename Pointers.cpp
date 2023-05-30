#include <iostream>

using namespace std;
void func() {
	int* ptr = new int(10);
	delete ptr;
	ptr = nullptr;
}

int* func2() {
	int* x = new int(100);
	//delete &x;
	return x;
}
void func3(int* ptr) {
	delete ptr;
}
class Thing {
public:
	int x;
};
class ThingWithPtr {
public:
	int* x;
};

int main() {
	Thing one;
	one.x = 100;
	Thing* thingPtr = new Thing;
	(*thingPtr).x = 100;
	thingPtr->x = 100; //whatever is to the left of -> MUST be a pointer!

	ThingWithPtr twp;
	//twp->x = new int(100); //INCORRECT
	twp.x = new int(100);
	cout << *twp.x << endl;
	delete twp.x;

	delete thingPtr;

	ThingWithPtr* twpPtr = new ThingWithPtr;
	twpPtr->x = new int(200);
	delete twpPtr->x;
	delete twpPtr;

/*	int capacity = 100;
	int* arr=new int[capacity]; //An array of 100 integers, on the heap
	arr[0] = 100;
	cout << *arr << endl; //prints 100
	int* second = (arr + 1); //pointer arithmetic, C++ worries about the size of an int
	*second = 200;
	cout << arr[1] << endl;
	int num_items = 1;
	for (int i = 0; i < 100; i++) {
		int* ptr = arr + i;
		*ptr = (i + 1) * 100;
	}
*/	/*
	for (int i = 0; i < 1000000000; i++) {
		int* ptr = func2();
		func3(ptr);
	}*/
	/*	int* ptr = new int(10);
	int* otherptr=ptr;
	cout << "Ptr: "<<ptr << endl;
	cout << "Otherptr: " << otherptr << endl;
	delete ptr;

	//delete otherptr; //double delete
	cout << "Deleted PTR"<<endl;
	cout << "Ptr: " << ptr << endl;
	cout << "Otherptr: " << otherptr << endl; //Dangling Pointer
	cout << "Otherptr's value: " << *otherptr << endl;
	ptr = otherptr = nullptr; //could also be NULL; protects the system
	cout << "Ptr: " << ptr << endl;
	cout << "Otherptr: " << otherptr << endl;
	//if (otherptr !=nullptr)
		cout << "Otherptr's value: " << *otherptr << endl; //possibly deref null

	cout << "Finished successfully." << endl;
*/	/*for (int i = 0; i < 1000000000; i++)
		func();
		*/
	/*int x = 5;
	cout << x << endl; //5
	cout << &x << endl; //prints out the address-of x
	int* ptr = &x;
	//int test = &x;
	//double* test = &x;
	cout << ptr << endl;
	cout << &ptr << endl;
	int** intPtrPtr = &ptr;

	cout << "Dereference ptr: "<< * ptr << endl;
	cout << "Dereference intPtrPtr: " << **intPtrPtr << endl;
	cout << "X: " << x << endl;

	ptr = new int; //A new variable is created on the heap and referenced by ptr;
	*ptr = 10;
	cout << *ptr << endl; //prints 10
	delete ptr; //prevents Garbage on the heap (Memory leak)
	ptr = new int;
	cout << *ptr << endl;
	*/

}