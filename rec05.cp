//
//  main.cpp
//  rec05
//
//  Created by Iris Yang on 2/28/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Section{
    friend ostream& operator<<(ostream&os, const Section& aSection) {
        os << "Section: " << aSection.getNumber() << ", Time slot: " <<
        aSection.atime << ", Student: ";
        if(aSection.Students.size()==0){
            os << "None" << endl;
        }
        else{
            for (size_t i=0; i<aSection.Students.size(); ++i){
                os << *aSection.Students[i] << endl;
            }
        }
        return os;
    }
public:
    Section(const string& anumber, const string& aday, int atime) : number(anumber), atime(aday, atime) {}
    const string& getNumber() const {
        return number;
    }
    void addStudent(const string& stuname){
        Student* aStudent = new Student(stuname);
        Students.push_back(aStudent);
    }
    void addGrade(const string& name, const int& grade, const int& week) {
        for(size_t i=0; i<Students.size(); ++i){
            if(Students[i]->getName()==name){
                Students[i]->modify(grade, week);
                break;
            }
        }
    }
    ~Section() {
        cout << "Section " << number << " is being deleted" << endl;
        for(size_t i=0; i<Students.size(); ++i){
            cout << "Deleting " << Students[i]->getName() << endl;
            delete Students[i];
            Students[i] = nullptr;
        }
    }
    Section(const Section& sec) : number(sec.number), atime(sec.atime){
        for(size_t i=0; i< sec.Students.size();++i){
            Student* copy = new Student(*sec.Students[i]);
            Students.push_back(copy);
        }
    }
private:
    class Time_slot{
        friend ostream& operator<<(ostream& os, const Time_slot& aTime) {
            os << "[Day: " << aTime.day << ", Start time: ";
            if(aTime.time<12&&aTime.time!=0){
                os << aTime.time << "AM" <<  "]" << endl;
            }
            else if(aTime.time==0){
                os << " 12 AM " <<  "]" << endl;
            }
            else{
                os << aTime.time -12 << "PM" <<  "]" << endl;
            }
            return os;
        }
    public:
        Time_slot (const string& aday, const int& atime) : day(aday), time(atime){}
    private:
        string day;
        int time;
        string exp;
    };
    class Student{
        friend ostream& operator << (ostream& os, const Student& aStudent) {
            os << "Name: " << aStudent.StudentName <<", Grade: " << " ";
                for (size_t j=0; j<aStudent.Grades.size(); ++j){
                    os << aStudent.Grades[j] << " ";
                }
                os << endl;
            return os;
        }
    public:
        Student(const string& aName) : StudentName(aName), Grades(14,-1) {}
        const string& getName() const {
            return StudentName;
        }
        vector<int> getGrades() const {
            return Grades;
        }
        void modify(const int& grade, const int& week) {
            Grades[week-1] = grade;
        }
    private:
        string StudentName;
        vector<int> Grades;
    };
    string number;
    vector<Student*> Students;
    Time_slot atime;
};

class LabWorker{
    friend ostream& operator<<(ostream& os, const LabWorker& aWorker) {
        if(aWorker.getSection()==nullptr){
            os << aWorker.getName() << " does not have a section" << endl;
        }
        else{
            os << aWorker.getName() << " has Section: " << *aWorker.linkedSection;
        }
        return os;
    }
public:
    LabWorker(const string& aWorker) : Workername(aWorker) {}
    const string& getName() const {
        return Workername;
    }
    const Section* getSection() const {
        return linkedSection;
    }
    void addSection(Section& SecNum) {
        if(linkedSection==nullptr){
            linkedSection = &SecNum;
        }
        else{
            cout<< "This worker has already got a section." << endl;
        }
    }
    void addGrade(const string& name, const int& grade, const int& week){
        linkedSection->addGrade(name, grade, week);
    }
private:
    string Workername;
    Section* linkedSection = nullptr;
};

// Test code
void doNothing(Section sec) {
    cout << sec << endl;
}



int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe("Moe");
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection(secA2);
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection(secB3);
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works properly, i.e. no memory leaks\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
