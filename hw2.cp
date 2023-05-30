//
//  main.cpp
//  hw2
//
//  Created by Iris Yang on 2/12/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//
// This code is objective to create a medieval game that simulates war game.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Structure of Warrior object with corresponding name and strength
struct Warrior {
    string name;
    int strength;
};

// Declare used function
void battle(Warrior& aWarrior, Warrior& bWarrior);
void status(const vector<Warrior>& warriors);
void createWarriorvector(vector<Warrior>& warriors, const string& name, int strength);
void readfile(ifstream& file);

// Open the file and operate the run process
int main(){
    ifstream file("warriors.txt");
    if(!file){
        cout << "File does not exist." << endl;
        exit(0);
    }
    readfile(file);
}

// Function for Battle command
void battle(Warrior& aWarrior, Warrior& bWarrior){
    cout<< aWarrior.name << " battles " << bWarrior.name << endl;
    //if they are all dead
    if(aWarrior.strength == 0 && bWarrior.strength == 0){
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    //two warriors battle
    else if(aWarrior.strength > bWarrior.strength){
        //if one is dead
        if(bWarrior.strength == 0){
            cout << "He's dead, " << aWarrior.name << endl;
        }
        //if not dead, then fight
        else{
            aWarrior.strength -= bWarrior.strength;
            bWarrior.strength = 0;
            cout<< aWarrior.name << " defeats " << bWarrior.name << endl;
        }
    }
    else if(bWarrior.strength > aWarrior.strength){
        if(aWarrior.strength == 0){
            cout << "He's dead, " << bWarrior.name << endl;
        }
        else{
            bWarrior.strength -= aWarrior.strength;
            aWarrior.strength = 0;
            cout<< bWarrior.name << " defeats " << aWarrior.name << endl;
        }
    }
    //if they have the same strength, then both are dead at the same time
    else{
        aWarrior.strength = 0;
        bWarrior.strength = 0;
        cout << "Mutual Annihilation: " << aWarrior.name << " and " << bWarrior.name << " die at each other's hands" << endl;
    }
}

// Operate the Status command and display all warriors' information
void status(const vector<Warrior>& warriors){
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for(const Warrior& warrior:warriors){
        cout << "Warriors: " << warrior.name << ", strength: "
        << warrior.strength << endl;
    }
}

// Create the Warrior Vector at the very beginning of opening the file
void createWarriorvector(vector<Warrior>& warriors, const string& name, int strength){
    Warrior aWarrior {name, strength};
    warriors.push_back(aWarrior);
}

// Read the file and operate the commands
void readfile(ifstream& file){
    vector<Warrior> warriors;
    string command;
    string warriorname;
    string name1;
    string name2;
    int strength;
    
    //operates the corresponding commands
    while(file>>command){
        if(command=="Battle"){
            file >> name1;
            file >> name2;
            for(Warrior& aWarrior:warriors){
                if(aWarrior.name==name1){
                    for(Warrior& bWarrior:warriors){
                        if(bWarrior.name==name2){
                            battle(aWarrior, bWarrior);
                        }
                    }
                }
            }
        }
        else if(command=="Status"){
            status(warriors);
        }
        else if(command=="Warrior"){
            file >> warriorname;
            file >> strength;
            createWarriorvector(warriors, warriorname, strength);
        }
    }
    
}


