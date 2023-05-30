//
//  main.cpp
//  2016Midterm
//
//  Created by Iris on 6/14/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
// pass by value (does not change the original value)
void func1(int var){
    cout << "inside func1"<< endl;
    var = 100;
}
// pass by reference (change the original value)
void func2(int& var){
    cout<<"inside func2"<<endl;
    var = 100;
}
// pass by value of pointer
void func3(int* var){
    cout<<"inside func3"<<endl;
    *var = 100;
    //*var = new int(100); // Incidental memory leak
}
// pass by reference of pointer
void func4(int*& var){
    cout<<"inside func4"<<endl;
    *var = 200;
    //*var = new int(200);
}
struct SomeStruct {
         int data;
};
void q8(int arr[], int size, int capacity){
    int *temparr = new int[capacity];
    int iter;
    for(int i=0; i<capacity; i++){
        if (i<size){
            for (int j=i+1; j<size; j++){
                if (arr[i]>arr[j]){
                    iter = arr[i];
                    arr[i]=arr[j];
                    arr[j]= iter;
                }
            }
            temparr[i]=arr[i];
        }
        else{temparr[i]=0;}
    }
    for (int i=0;i<capacity;i++){
        cout<<temparr[i]<<" ";
    }
    cout<<endl;
}
void q9(ifstream& ifs){
    string filename;
    cout<<"Enter the filename: "<<endl;
    cin>>filename;
    ifs.open(filename);
    while(!ifs){
        cout<<"Bad Filename!"<<endl;
        cout<<"Enter the filename: "<<endl;
        cin>>filename;
        ifs.clear();
        ifs.open(filename);
    }
    int count = 0;
    string line;
    int arr[]={};
    while(ifs>>line){
        stringstream ss;
        int temp;
        ss<<line;
        ss>>temp;
        arr[count]=temp;
        cout<<count<<" "<<arr[count]<<endl;
        count+=1;
    }
    q8(arr, count, count);
    /*cout<<"count="<<count<<endl;
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<endl;*/
    
}
int main() {
    /*int x = 3;
    int* p = &x;
    //int*& p;
    cout << p << endl;
    cout << &p << endl;*/
    
    /*int * p=new int(0);
    int * q=NULL;
    delete p;
    p = new int(0);
    cout<<*q<<endl;*/
    
    /*int x = 5;
    cout<<"X="<<x<<endl;
    func1(x);
    cout<<"X="<<x<<endl;
    func2(x);
    cout<<"X="<<x<<endl;
    int* ptr = &x;
    //int* ptr = nullptr;
    x=5;
    func3(ptr);
    cout<<"X="<<x<<endl;
    cout<<"*ptr="<<*ptr<<endl;
    func4(ptr);
    cout<<"X="<<x<<endl;
    cout<<"*ptr="<<*ptr<<endl;*/
    
    /*int* ptr = new int(10);
    int* otherptr=ptr;
    cout << "Ptr: "<<ptr << endl;
    cout << "Otherptr: " << otherptr << endl;
    delete ptr;
    //delete otherptr; //double delete
    cout << "Deleted PTR"<<endl;
    cout << "Ptr: " << ptr << endl;
    cout << "Otherptr: " << otherptr << endl; //Dangling Pointer*/
    
    /*int arr[3];
    for (int i=0; i<3; i++){
        arr[i] = i;
    }
    int* ptr0 = &arr[0];
    cout<<ptr0<<endl;
    int* ptr1 = &arr[1];
    cout<<ptr1<<endl;
    int* ptr2 = &arr[2];
    cout<<ptr2<<endl;*/
    
    /*int capacity = 100;
    int* arr=new int[capacity]; //An array of 100 integers, on the heap
    // int* arr = new int[m];
    delete [] arr;*/
    
    /*SomeStruct *ptr;
    ptr = new SomeStruct;
    //(*ptr).data=17; // is the same as:
    ptr->data = 17;
    delete ptr;
    ptr = nullptr;*/
    
    /*int x = 2;
    int y = 4;
    int arr[] = {1, 2, 3, 5, 8, 13, 21, 34, 55};
    int* p = arr + 3;
    int* q = p + x;//2
    cout << "A: " << *q << endl;
    p = &y;//4
    *q = *p + 2;
    *p = q[3];
    cout  << "B: " << *q++ << endl;
    cout  << "C: " << *q << endl;
    cout  << "D: " << y << endl;*/
    
    int a[] = { 22, 91, 35, 78, 100, 8, 75, 99, 1, 67 };
    int sizea=10;
    int newcap=15;
    cout<<"Given array is:"<<endl;
    for (int i = 0; i < sizea; i++){
        cout<< a[i] <<" ";
    }
    cout<<endl;
    printf("\nSorted array is: \n");
    q8(a, sizea, newcap);
    ifstream ifs;
    q9(ifs);
}

