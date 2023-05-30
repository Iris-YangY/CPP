//
//  main.cpp
//  yy2699_hw1
//
//  Created by Iris Yang on 2/5/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//
//This file is intended to decrypt the encrypted code.

#include <iostream>//iostream is needed
#include <vector>//vector is needed
#include <fstream>
#include <string>
using namespace std;

//decrypt characters in a line
char decrypt(char ch, int step){
    if (!isalpha(ch) || isupper(ch)) {
        return ch;
    }
    else {
        if (ch - step < 'a') {
            return char('z'-(step-(ch-'a'))+1);
        }
        else {
            return ch - step;
        }
    }
}

//decrypt lines by lines by calling the decrypt function that decrypt single character
string readlines(const string& something, int step) {
    string newline;
    for (size_t i = 0; i<something.size(); ++i) {
        if (something[i]!=' '){
            newline+=decrypt(something[i], step);
        }
        else{
            newline+=' ';
        }
    }
    return newline;
}

int main() {
    ifstream ifs("encrypted.txt");
    if (!ifs) {
        cout << "File does not exist."<<endl;
        exit(0);
    }
    int step;
    ifs >> step;
    string something;
    vector<string> reverse;
    while (getline(ifs, something)) {
        reverse.push_back(something);
    }
    ifs.close();
    for (size_t i = reverse.size(); i > 0; --i) {
        cout << readlines(reverse[i - 1], step) << endl;
    }
}

