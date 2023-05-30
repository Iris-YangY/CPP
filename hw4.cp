//
//  main.cpp
//  hw4
//
//  Created by Iris Yang on 2/26/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//
// This program still focuses on the medieval game but added a noble to own the warriors. Additionally, using the pointer to create the vector and saves the warriors' infomation.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Create Warrior class
class Warrior{
    
    friend ostream& operator<<(ostream& os, const Warrior& aWarrior) {
        os << aWarrior.name << ": " << aWarrior.strength;
        return os;
    }

public:
    Warrior (const string& aName, double aStrength) : name(aName), strength(aStrength), hired(false) {
    }
    
    const string& getName() const {
        return name;
    }
    
    const double& getStrength() const {
        return strength;
    }
    
    const bool& isHired() const {
        return hired;
    }
    
    void getDamage(double percentage) {
        strength = strength * (1 - percentage);
    }
    
    void getHired() {
        hired = true;
    }
    
    void getFired() {
        hired = false;
    }

private:
    string name;
    double strength;
    bool hired;
};

// Create Noble class
class Noble{
    
    friend ostream& operator<<(ostream& os, const Noble& theNoble) {
        os << theNoble.name << " has an army of " << theNoble.army.size() << endl;
        for (size_t i = 0; i < theNoble.army.size(); ++i) {
            cout << "          " << *(theNoble.army[i]) << endl;
        }
        return os;
    }

public:
    Noble (const string& theName) : name(theName), alive(true) {
    }

    bool hire (Warrior& aWarrior) {
        // If the Noble is alive
        if (alive) {
            // If the warrior is already hired, then attempt fails
            if (aWarrior.isHired()) {
                cout << "Warrior is already hired" << endl;
                return false;
            }
            // Else, the Noble could hire the warrior
            else {
                aWarrior.getHired();
                army.push_back(&aWarrior);
                return true;
            }
        }
        // If the Noble is dead, then he could not hire any warriors
        else {
            cout << "Hiring Failed: Noble is dead" << endl;
            return false;
        }
    }

    bool fire(Warrior& aWarrior){
        if(alive){
            // Fire action could only be taken if the Noble is alive
            for (size_t i = 0; i < army.size(); ++i){
                // If this warrior is hired by this Noble, then fire attempt success
                if(&aWarrior == army[i]){
                    Warrior* backup = army[i];
                    army[i] = army[army.size()-1];
                    army[army.size()-1] = backup;
                    cout << "You don't work for me anymore "
                    << army[army.size() -1]->getName()
                    << "! -- " << name << "." << endl;
                    army[army.size() - 1] = nullptr;
                    army.pop_back();
                    return true;
                }
            }
            // If this warrior is not hired by this Noble, then fire attempt fails
            cout << "Warrior is not hired by this Noble" << endl;
            return false;
        }
        // If the Noble is dead, then this warrior is dead by the Noble, then fire attempt fails
        else {
            cout << "Firing Failed: Noble is dead" << endl;
            return false;
        }
    }

    void reduceStrength(double percentage) {
        for (size_t i = 0; i < army.size(); ++i) {
            army[i]->getDamage(percentage);
        }
    }

    void battle(Noble& someNoble) {
        // Display the status of the battle
        cout << name << " battles " << someNoble.name << endl;
        // If they are both dead
        if ((!alive) && (!someNoble.alive)) {
            cout << "Oh, NO! They're both dead!  Yuck!" << endl;
        }
        // If enemy is dead
        else if (alive && (!someNoble.alive)) {
            cout << "He's dead, " << name << endl;
        }
        // If the Noble is dead
        else if ((!alive) && someNoble.alive) {
            cout << "He's dead, " << someNoble.name << endl;
        }
        // Do the battle and reduce strength from the army
        else {
            for (size_t i = 0; i < army.size(); ++i) {
                aStrength += army[i]->getStrength();
            }
            for (size_t i = 0; i < someNoble.army.size(); ++i) {
                bStrength += someNoble.army[i]->getStrength();
            }
            // If they have the same strength, then both are dead
            if (aStrength == bStrength) {
                this->reduceStrength(1);
                someNoble.reduceStrength(1);
                alive = false;
                someNoble.alive = false;
                cout << "Mutual Annihalation: " << name
                    << " and " << someNoble.name
                    << " die at each other's hands" << endl;
            }
            // If one's strength is greater than the other
            else if (aStrength > bStrength) {
                double percentage = bStrength / aStrength;
                this->reduceStrength(percentage);
                someNoble.reduceStrength(1);
                someNoble.alive = false;
                cout << name << " defeats " << someNoble.name << endl;
            }
            else {
                double percentage = aStrength / bStrength;
                someNoble.reduceStrength(percentage);
                this->reduceStrength(1);
                alive = false;
                cout << someNoble.name << " defeats " << name << endl;
            }
        }
    }

private:
    string name;
    vector<Warrior*> army;
    bool alive;
    double aStrength = 0;
    double bStrength = 0;
};

int main()
{
    //test code from additional resources for assignment
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);

    cout << "==========\n"
        << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

    art.fire(cheetah);
    cout << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n"
        << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

}
