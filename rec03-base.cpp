/*
  rec03-base.cpp
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//
// Task 1: The Account struct. Call it AccountS
//
struct AccountS{
    string name;
    int balance;
};


//
// Task 2: The Account class. Call it AccountC
//


// 2.b: AccountC output operator, not a friend.

// 2.2: AccountC output operator, reimplemented as a friend.



//
// Task 3
//
// Transaction class definition


// Account class definition


//
// Task 4
//
// Transaction class definition with embedded Account class



int main() {

    //
    // Task 1: account as struct
    //
    //      1a. Fill vector of account structs from file

    cout << "Task1a:\n";
    cout << "Filling vector of struct objects, define a local struct instance "
         << " and set fields explicitly:\n";

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";

    //==================================
    //
    // Task 2: account as class
    //

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";



    cout << "---\n";
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";

    
    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    // Note code here will be same as above.


    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    ifs.open("accounts.txt");


    
    cout << "\nTask2e:\n";
    cout << "\nFilling vector of class objects, using emplace_back:\n";

    
    // Task 3
    cout << "==============\n";
    cout << "\nTask 3:\n\nAccounts and Transaction:\n";


    // Task 4
    cout << "==============\n";
    cout << "\nTask 4:\n\nAccounts and Transaction:\n"
         << "Account class is nested inside Transaction class.\n";

}


