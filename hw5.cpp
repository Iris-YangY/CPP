//
//  main.cpp
//  hw5
//
//  Created by Iris on 6/19/22.
//

#include <iostream>
#include <string>
using namespace std;
class Time{
private:
    int day;
    int hour;
    int minute;
public:
    // Default constructor, takes 0 or 3 input parameter
    Time(): day(0), hour(0), minute(0) {}
    Time(int newday, int newhour, int newminute): day(newday), hour(newhour), minute(newminute) {}
    // Accessor (getter)
    int getDay() const { return day;}
    int getHour() const { return hour;}
    int getMinute() const { return minute;}
    // Mutator (setter)
    void setDay(int newday) { day = newday;}
    void setHour(int newhour) { hour = newhour; checking();}
    void setMinute(int newminute) { minute = newminute; checking();}
    // Checking function to adjust day, hour, minute accordingly to fit in the range
    void checking() {
        if (minute >= 60){ hour += minute / 60; minute %= 60;}
        while (minute < 0){ hour--; minute += 60;}
        if (hour >= 24){ day += hour / 24; hour %= 24;}
        while (hour < 0){ day--; hour += 24;}
    }
    // Addition operator
    Time operator+(const Time& rhs) const;
    // Subtraction operator
    Time operator-(const Time& rhs) const;
    // Pre-increment
    Time& operator++();
    // Post-increment
    Time operator++(int);
    // Pre-decrement
    Time& operator--();
    // Post-decrement
    Time operator--(int);
    // Output operator
    friend ostream& operator<<(ostream & output, const Time& T);
};
Time Time::operator+(const Time &rhs) const{
    Time temp;
    temp.minute = minute + rhs.minute;
    temp.hour = hour + rhs.hour;
    temp.day = day + rhs.day;
    temp.checking();
    return temp;
}
Time Time::operator-(const Time &rhs) const{
    Time temp;
    temp.minute = minute - rhs.minute;
    temp.hour = hour - rhs.hour;
    temp.day = day - rhs.day;
    temp.checking();
    return temp;
}
Time& Time::operator++(){
    minute++;
    checking();
    return *this;
}
Time Time::operator++(int){
    Time temp = *this;
    minute++;
    checking();
    return temp;
}
Time& Time::operator--(){
    minute--;
    checking();
    return *this;
}
Time Time::operator--(int){
    Time temp = *this;
    minute--;
    checking();
    return temp;
}
ostream& operator<<(ostream & output, const Time& T){
    if (T.minute<10){
        output << T.hour << ":0" << T.minute << " (" << T.day <<")" << endl;
    }
    else{
        output << T.hour << ":" << T.minute << " (" << T.day <<")" << endl;
    }
    return output;
}
int main() {
//    Time a(0,0,1);
//    Time b(-2,23,59);
//    Time c(3,3,3);
//    cout<<a;
//    cout<<b;
//    cout<<c;
//    /*Time d;
//    d=a++;
//    cout<<a;
//    cout<<d;
//    d=++a;
//    cout<<a;
//    cout<<d;*/
//    Time e;
//    e=a+b;
//    cout<<e;
}
