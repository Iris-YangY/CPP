//
//  main.cpp
//  rec2
//
//  Created by Yadi Yang on 2/7/20.
//  Copyright © 2020 Iris Yang. All rights reserved.
//

#include <iostream>//iostream is needed
#include <vector>//vector is needed
#include <fstream>
#include <string>
using namespace std;

struct molecular {
    vector<string> name;
    int carbon;
    int hydrogen;
};
void fillinfo (ifstream& ifs, vector<molecular>& info);
void sorting (vector<molecular>& info);
void display(const vector<molecular>& info);
void openfile(ifstream& file);
int main() {
    ifstream file;
    vector<molecular> info;
    openfile(file);
    fillinfo(file, info);
    sorting(info);
    display(info);
    file.close();
}

void fillinfo (ifstream& ifs, vector<molecular>& info) {
    molecular infos;
    string aname;
    char ch;
    int acarbon;
    int ahydrogen;
    bool conti;
    while (ifs>>aname>>ch>>acarbon>>ch>>ahydrogen) {
        conti=true;
        for (size_t i=0; i<info.size(); i++) {
            if((info[i].carbon==acarbon)&&(info[i].hydrogen==ahydrogen)) {
                info[i].name.push_back(aname);
                conti=false;
                break;
            }
        }
        if (conti){
            molecular store;
            store.carbon=acarbon;
            store.hydrogen=ahydrogen;
            store.name.push_back(aname);
            info.push_back(store);
        }
    }
}

void sorting (vector<molecular>& info) {
    for (size_t i=0; i<info.size(); i++){
        for (size_t j=0; j<info.size()-1; j++){
            if (info[j+1].carbon<info[j].carbon){
                molecular store = info[j];
                info[j] = info[j+1];
                info[j+1] = store;
            }
            if ((info[j+1].carbon==info[j].carbon)&&
                info[j+1].hydrogen<info[j].hydrogen){
                molecular store = info[j];
                info[j] = info[j+1];
                info[j+1] = store;
            }
        }
    }
}

void display(const vector<molecular>& info){
    for (size_t i=0; i<info.size(); i++) {
        cout<<'C'<<info[i].carbon<<'H'<<info[i].hydrogen<<' ';
        for (const string& name:info[i].name){
            cout<<name<<' ';
        }
        cout<<endl;
    }
}

void openfile(ifstream& file){
    string aname;
    do{
        file.clear();
        cout<<"Please enter the file name: "<<endl;
        cin >> aname;
        file.open(aname);
    }
    while(!file);
}

