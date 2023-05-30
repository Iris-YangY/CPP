//
//  main.cpp
//  rec03
//
//  Created by Iris Yang on 2/14/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//
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
class AccountC{
    
    friend ostream& operator<<(ostream& os, const AccountC& anAccount) {
        os << "Account Name: " << anAccount.Name << ", Account Number: " << anAccount.Balance;
        return os;
    }
    
private:
    string Name;
    int Balance;
    
public:
    AccountC(const string& aName, const int aBalance) : Name(aName), Balance(aBalance) {
    }
    
    const string& getName(const AccountC& anAccount) const {
        return anAccount.Name;
    }
    
    const int& getBalance(const AccountC& anAccount) const {
        return anAccount.Balance;
    }
    
};

// 2.b: AccountC output operator, not a friend.
//ostream& operator<<(ostream& os, AccountC& anAccount) {
//    os << "Account Name: " << anAccount.getName(anAccount) << ", Account Balance: " << anAccount.getBalance(anAccount);
//    return os;
//}



// 2.2: AccountC output operator, reimplemented as a friend.



//
// Task 3
//
// Transaction class definition


// Account class definition
class Account {
    friend ostream& operator << (ostream& os, const Account& anAccount) {
        
        for(const Transactions& oneTrans : anAccount.History) {
            os << oneTrans << endl;
        }
        return os;
    }
private:
    class Transactions {
        friend ostream& operator << (ostream& os, const Transactions& aTrans) {
            os << aTrans.Command << aTrans.Amount << endl;
            os << "The balance now is: " << aTrans.Balance << endl;
            return os;
        }
    private:
        int AccountNumber;
        string Command;
        int Amount;
        int Balance;
    public:
        Transactions(const string& theCommand, const int& theAmount, int& theBalance) : Command(theCommand), Amount(theAmount), Balance(theBalance) {
        }
        const int& getAccount (const Transactions& aTrans) const {
            return aTrans.AccountNumber;
        }
        const string& getCommand (const Transactions& aTrans) const {
            return aTrans.Command;
        }
        const int& getAmount (const Transactions& aTrans) const {
            return aTrans.Amount;
        }
        const int& getBalance(const Transactions& aTrans) const {
            return aTrans.Balance;
        }
        
    };
    
    string Name;
    int Number;
    int Balance=0;
    vector<Transactions> History;
    
public:
    Account(const string& aName, const int& aNumber) : Name(aName), Number(aNumber) {
    }
    
    const string& getName (const Account& anAccount) const {
        return anAccount.Name;
    }
    
    const int& getNumber (const Account& anAccount) const {
        return anAccount.Number;
    }
    
    const int& getBalance (const Account& anAccount) const {
        return anAccount.Balance;
    }
    
    void deposit(Account& anAccount, int amount){
        anAccount.Balance+=amount;
    }
    
    void withdraw(Account& anAccount, int amount){
        anAccount.Balance-=amount;
    }
    
    void createvector(Account& anAccount, string Command, int amount, int Balance){
        Transactions aTrans(Command, amount, Balance);
        History.push_back(aTrans);
    }
    
    void displayvector(Account& anAccount, vector<Transactions> History) {
        for(size_t i=0; (i=History.size()); ++i){
            cout << anAccount.Name << " has " << History[i].getCommand(History[i]) <<
            History[i].getAmount(History[i]) << " from the account." << endl;
            cout << "The balance now is " << History[i].getBalance(History[i]) << endl;
        }
    }
};

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
    
    vector<AccountS> AccountSummary;
    string name;
    int balance;
    ifstream file("accounts.txt");
    if(!file){
        cout<<"File does not exist."<<endl;
        exit(0);
    }
    while(file>>name>>balance){
        AccountS aPerson;
        aPerson.name = name;
        aPerson.balance = balance;
        AccountSummary.push_back(aPerson);
    }
    file.close();
    for(const AccountS& aPerson : AccountSummary){
        cout<< "Account Name: " << aPerson.name << ", Account Number: " << aPerson.balance << endl;
    }
    cout<<endl;
    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    
    AccountSummary.clear();
    file.open("accounts.txt");
    if(!file){
        cout<<"File does not exist."<<endl;
        exit(0);
    }
    while(file>>name>>balance){
        AccountS aPerson {name, balance};
        AccountSummary.push_back(aPerson);
    }
    file.close();
    for(const AccountS& aPerson : AccountSummary){
        cout<< "Account Name: " << aPerson.name << ", Account Number: " << aPerson.balance << endl;
    }

    //==================================
    //
    // Task 2: account as class
    //

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    
    file.open("accounts.txt");
    if(!file){
        cout<<"File does not exist."<<endl;
        exit(0);
    }
    vector<AccountC> AccountCSummary;
    
    while(file>>name>>balance){
        AccountC aPerson(name, balance);
        AccountCSummary.push_back(aPerson);
    }
    
    cout << "---\n";
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";

    for(AccountC& anAccount : AccountCSummary){
        cout << anAccount << endl;
    }
    file.close();
//    "Account Name: " << anAccount.getName(anAccount) <<
//    ", Account Balance: " << anAccount.getBalance(anAccount)
    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    // Note code here will be same as above.

    for(AccountC& anAccount : AccountCSummary){
        cout << anAccount << endl;
    }

    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    
    file.open("accounts.txt");
    if(!file){
        cout<<"File does not exist."<<endl;
        exit(0);
    }
    AccountCSummary.clear();
    while(file>>name>>balance){
        AccountCSummary.push_back(AccountC(name, balance));
    }
    file.close();
    
    for(AccountC& anAccount : AccountCSummary){
        cout << anAccount << endl;
    }
    
    
    cout << "\nTask2e:\n";
    cout << "\nFilling vector of class objects, using emplace_back:\n";
    
    file.open("accounts.txt");
    if(!file){
        cout<<"File does not exist."<<endl;
        exit(0);
    }
    AccountCSummary.clear();
    while(file>>name>>balance){
        AccountCSummary.emplace_back(AccountC(name, balance));
    }
    file.close();
    
    for(AccountC& anAccount : AccountCSummary){
        cout << anAccount << endl;
    }
    
    // Task 3
    cout << "==============\n";
    cout << "\nTask 3:\n\nAccounts and Transaction:\n";
    
    // Task 4
    cout << "==============\n";
    cout << "\nTask 4:\n\nAccounts and Transaction:\n"
         << "Account class is nested inside Transaction class.\n";
    ifstream ifs("transactions.txt");
    if (!ifs){
        cout<<"File does not exist."<<endl;
        exit(0);
    }
    
    string command;
    string accountname;
    int accountnumber;
    int amount;
    int balance_s;
    vector<Account> AccountVector;
    
    while(ifs>>command){
        if(command=="Account"){
            ifs>>accountname>>accountnumber;
            Account aPerson(accountname, accountnumber);
            for(Account& aPerson : AccountVector){
                if(aPerson.getNumber(aPerson)==accountnumber){
                    cout<< aPerson << endl;
                    break;
                }
            }
            cout<<"New Account Added!"<<endl;
            AccountVector.push_back(aPerson);
            
        cout<<"Account Name: "<<accountname<<", Account Number: "<<accountnumber<<endl;
        }
        else if(command=="Deposit"){
            ifs>>accountnumber>>amount;
            for(Account& aPerson : AccountVector){
                if(aPerson.getNumber(aPerson)==accountnumber){
                    aPerson.deposit(aPerson, amount);
                    balance_s=aPerson.getBalance(aPerson);
                    cout << aPerson.getName(aPerson) << " has deposit " << amount <<
                    " to the account. The new balance now is " << balance_s << endl;
                    aPerson.createvector(aPerson, "Deposit", amount, balance_s);
                }
            }
            
            
        }
        else if(command=="Withdraw"){
            ifs>>accountnumber>>amount;
            for(Account& aPerson : AccountVector){
                if(aPerson.getNumber(aPerson)==accountnumber){
                    if(aPerson.getBalance(aPerson)<amount){
                        cout<<"Insufficient Fund!"<<endl;
                    }
                    else{
                        aPerson.withdraw(aPerson, amount);
                        balance_s=aPerson.getBalance(aPerson);
                        cout << aPerson.getName(aPerson) << " has withdraw " << amount <<
                        " to the account. The new balance now is " << balance_s << endl;
                        aPerson.createvector(aPerson, "Withdraw", amount, balance_s);
                    }
                }
            }
            
        }
    }
}

