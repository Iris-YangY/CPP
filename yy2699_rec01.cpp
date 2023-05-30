//
//  main.cpp
//  yy2699_hw1
//
//  Created by Iris Yang on 2/5/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//

#include <iostream>//iostream is needed
#include <vector>//vector is needed
#include <fstream>
using namespace std;

//Question 13
void printInt(const vector<int>& avector){
    for (size_t i=0; i<avector.size(); ++i) {
        cout << avector[i] << " ";
    }
}

//Question 14
void DoubleVec(vector<int>& avector){
    for (size_t i=0; i<avector.size(); ++i) {
        avector[i]=2*avector[i];
    }
}

//Question 15
void DoubleRange(vector<int>& avector){
    for (int i : avector){
        i=2*i;
    }
}

int main() {//main returns type int, but will not return anything on screen.
    //Question 1
    //Not using namespace but standard output
    std::cout << "Hello world!" << endl;

    //Question 2
    //Using namespace will simplify the function by omitting the standard format indication
    cout << "Hello World!" << endl;

    //Question 3
    int x;//The x value is undefined
    //Based on the inital basis of the computer, the output will be some random number
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;

    //Question 4
    cout << "size of x is: " << sizeof(x) << endl;
    cout << "size of y is: " << sizeof(y) << endl;
    cout << "size of z is: " << sizeof(z) << endl;
    cout << "size of pie is: " << sizeof(pie) << endl;
    //pie takes more memory space, all int values take 4 space memories, and double values take 8 space memories

    //Question 5
    //x = "felix";
    //There will be a compilation error

    //Question 6
    if(y>=10 && y<=20) {
        cout << "y is between 10 to 20" << endl;
    }
    else {
        cout << "y is not between 10 to 20" << endl;
    }

    //Question 7
    //Using for loop to print out 10 to 20
    cout<<"Print out 10 to 20 using for loop: "<<endl;
    for (size_t i = 10; i < 21; ++i) {
        cout << i << " ";
    }
    cout<<endl;
    //Using while loop to print out 10 to 20
    cout<<"Print out 10 to 20 using while loop: "<<endl;
    int i = 10;
    while (i<=20) {
        cout << i << " ";
        ++i;
    }
    cout<<endl;
    //Using do-while loop
    cout<<"Print out 10 to 20 using do-while loop: "<<endl;
    int start = 10;
    do{
        cout << start << " ";
        start++;
    }
    while (start<=20);
    cout<<endl;
    //Question 8
    //do-while loop will continuously checking the condition until it is not satisfied, since a test will be neede to check
    //whether the condition will be satisfied or not, do-while loop will be a good choice
    ifstream ifs;
    do{
        string file;
        cin>>file;
        ifs.open(file);
    }
    while(!(ifs));

    //Question 9
    //Read the file
    string something;
    while (ifs>>something) {
        cout << something << " ";
    }
    ifs.close();

    //Question 10
    //Create a vector includes all even number from 10 to 100
    vector<int> Ints;
    for (int s=10; s<=100; ++s) {
        if(s%2==0){
            Ints.push_back(s);
        }
    }
    
    //Question 11
    //Print out using indices
    cout<<"Print out using indices: "<<endl;
    for (size_t i=0; i<Ints.size(); ++i){
        cout<<Ints[i]<<" ";
    }
    cout<<endl;
    //Print out using range for
    cout<<"Print out using range for: "<<endl;
    for (int i : Ints){
        cout<<i<<" ";
    }
    cout<<endl;
    //Print out in reverse order
    cout<<"Print out in reverse order: "<<endl;
    for (size_t k=Ints.size(); k>0; --k){
        cout<<Ints[k-1]<<" ";
    }
    cout<<endl;
    
    //Question 12
    //Initialize the prime vector
    vector<int> prime{2,3,5,7,11,13,17,19};
    //Display the vector
    for (int i : prime) {
        cout<<i<<" ";
    }
    cout<<endl;

    //Question 13 cont.
    //Display the result
    cout<<"Display the values of the int vector: "<<endl;
    printInt(Ints);
    cout<<endl;
    //Question 14 cont.
    //Display the result
    cout<<"Double the value of the vector: "<<endl;
    DoubleVec(Ints);
    printInt(Ints);
    cout<<endl;

    //Question 15 cont.
    //Display the result
    cout<<"Double the value using range for: "<<endl;
    DoubleRange(Ints);
    printInt(Ints);
    cout<<endl;

}
