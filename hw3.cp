//
//  main.cpp
//  hw3
//
//  Created by Iris Yang on 2/19/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//
// This program is objective to simulate the warriors' wars by using the class method.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Creating the Warriors class
class Warriors {
    friend ostream& operator << (ostream& os, const Warriors& aPerson);
private:
    // Nesting the Weapon class inside the Warriors class
    class Weapon{
        friend ostream& operator << (ostream& os, const Warriors& aPerson);
    private:
        string WeaponName;
        int Strength;
    public:
        Weapon(const string& aWeapon, int& aStrength) : WeaponName(aWeapon), Strength(aStrength){
        }
        const string& getWeaponName(const Weapon& aWeapon) const {
            return aWeapon.WeaponName;
        }
        const int& getStrength(const Weapon& aWeapon) const {
            return aWeapon.Strength;
        }
        void changeStrength(int newStrength){
            Strength = newStrength;
        }
    };
    string Name;
    Weapon aWeapon;
public:
    Warriors(const string& aName, const string& aWeaponName, int& aStrength) : Name(aName), aWeapon(aWeaponName, aStrength){}
    const string& getName(const Warriors& aPerson) const {
        return aPerson.Name;
    }
    const string& getWeaponName(const Warriors& aPerson) const {
        return aWeapon.getWeaponName(aWeapon);
    }
    const int& getStrength(const Warriors& aPerson) const {
        return aWeapon.getStrength(aWeapon);
    }
    void changeStrength(int newStrength){
        aWeapon.changeStrength(newStrength);
    }
};

// Creating the Battle class for Battle command
class Battle{
private:
    Warriors& aWarrior;
    Warriors& bWarrior;
public:
    Battle(Warriors& warr1, Warriors& warr2) : aWarrior(warr1), bWarrior(warr2){}
    void display(){
        cout << aWarrior.getName(aWarrior) << " battles " << bWarrior.getName(bWarrior) << endl;
        // If they are both dead
        if(aWarrior.getStrength(aWarrior) == 0 && bWarrior.getStrength(bWarrior) == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else if(aWarrior.getStrength(aWarrior) > bWarrior.getStrength(bWarrior)){
            // If one is dead
            if(bWarrior.getStrength(bWarrior) == 0){
                cout << "He's dead, " << aWarrior.getName(aWarrior) << endl;
            }
            else{
                int newStrength = aWarrior.getStrength(aWarrior) - bWarrior.getStrength(bWarrior);
                aWarrior.changeStrength(newStrength);
                bWarrior.changeStrength(0);
                cout << aWarrior.getName(aWarrior) << " defeats " << bWarrior.getName(bWarrior) << endl;
            }
        }
        else if(aWarrior.getStrength(aWarrior) < bWarrior.getStrength(bWarrior)){
            // If the other one is dead
            if(aWarrior.getStrength(aWarrior) == 0){
                cout << "He's dead, " << bWarrior.getName(bWarrior) << endl;
            }
            else{
                int newStrength = bWarrior.getStrength(bWarrior) - aWarrior.getStrength(aWarrior);
                bWarrior.changeStrength(newStrength);
                aWarrior.changeStrength(0);
                cout << bWarrior.getName(bWarrior) << " defeats " << aWarrior.getName(aWarrior) << endl;
            }
        }
        else{
            // If they have the same strength, so die at the same time
            aWarrior.changeStrength(0);
            bWarrior.changeStrength(0);
            cout << "Mutual Annihilation: " << aWarrior.getName(aWarrior) << " and " <<
            bWarrior.getName(bWarrior) << " die at each other's hands" << endl;
        }
    }
};

// Display the Status report
class Status{
private:
    vector<Warriors>& warriors;
public:
    Status(vector<Warriors>& warrs) : warriors(warrs){
    }
    void show() const {
        cout << "There are: " << warriors.size() << " warriors " << endl;
        for(const Warriors& aWarr : warriors){
            cout << aWarr << endl;
        }
    }
};

// Find the warrior in the Warriors vector
Warriors& findWarr(vector<Warriors>& warriors, string& name){
//find warriors by the name and return it
    for(Warriors& warrior : warriors){
        if(name == warrior.getName(warrior)){
            return warrior;
            break;
            }
        }
    cout << "Not exist." << endl;
    exit(1);
    }

// Display the warrior and his weapon, as well as strength
ostream& operator<<(ostream& os, const Warriors& aWarrior){
    os << "Warrior: " << aWarrior.getName(aWarrior);
    os << ", weapon: " << aWarrior.getWeaponName(aWarrior) << ", " << aWarrior.getStrength(aWarrior);
    return os;
}

// Operating command in the txt file
void readfile(ifstream& file){
    vector<Warriors> warriors;
    string Command;
    string WarriorName;
    string WeaponName;
    int Strength;
    string warr1;
    string warr2;
    while(file >> Command){
        if(Command=="Warrior"){
            file >> WarriorName >> WeaponName >> Strength;
            Warriors aWarrior {WarriorName, WeaponName, Strength};
            warriors.push_back(aWarrior);
        }
        else if(Command=="Status"){
            Status current = Status(warriors);
            current.show();
        }
        else if(Command=="Battle"){
            file >> warr1 >> warr2;
            Warriors& aWarr = findWarr(warriors, warr1);
            Warriors& bWarr = findWarr(warriors, warr2);
            Battle aBattle = Battle(aWarr, bWarr);
            aBattle.display();
        }
    }
    file.close();
}

int main(){
    ifstream file("warriors.txt");
    if(!file){
        cout << "File does not exist." << endl;
        exit(0);
    }
    readfile(file);
}
