#include <iostream>
#include <ctime>

using namespace std;

class Date {
private: //items that are ONLY accessible from within the class; not necessary because its the default
	int day;
	int month;
	int year;
public: //items that are accessible to everyone
	//Date(); //Constructor, like __init__
	//Date() : day(1), month(1), year(1970) {} //Another option for default constructor
	Date(int unixTime=0); //One argument AND default constructor
	Date(int newDay, int newMonth, int newYear) : day(newDay), month(newMonth), year(newYear) {}
	int getDay() const { return day; } //const here means we will not change the object!
	int getMonth() const { return month; }
	int getYear() const{ return year; }//Accessor function (getter)
	void setYear(int newYear) { year = newYear; } //Mutator function (setter)
	void setMonth(int newMonth); //defined ouside of the class
	void setDay(int newDay);
	void printUSDate()const { cout << month << '/' << day << '/' << year; }
};

class Student {
	Date dob;
public:
	Student(Date newDob); //DOB is REQUIRED to create a student
};
class Thing {};

Student::Student(Date newDob) {
	dob = newDob;
}


Date::Date(int unixTime) { //Do not put DEFAULT value here!
	if (unixTime == 0) {
		day = month = 1;
		year = 1970;
		return;
	}
	year = unixTime;
	month = 1;
	day = 1;
	/*tm* timeinfo;
	time_t val = (time_t)unixTime;
	timeinfo = localtime(&val);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon+1;
	year = timeinfo->tm_year;
*/
}

/*Date::Date() {
	day = month = 1;
	year = 1970;
}*/

void Date::setMonth(int newMonth) { //Member function, defined outside
	if (newMonth > 0 && newMonth <= 12)
		month = newMonth;
}
void Date::setDay(int newDay) {
	if (newDay > 0 && newDay <= 31) {
		day = newDay;
	}
}

class Person {
private:
	Date dob;
public:
	int getAge() { return 2022 - dob.getYear(); }
};
void printMonth(const Date& d) {
	cout << d.getMonth() << endl;
}

int main() {
	int x(100); // same as "int x=100;"
	Date myDate; //Default constructor invoked here
	myDate.printUSDate();
	myDate.setYear(2022);
	Date anotherDate(31, 5, 2022); //Three argument constructor invoked here

	Date currentDate(time(nullptr));

	currentDate.printUSDate();

	Student a(currentDate); //Parameter MUST be provided, no default constructor exists!
	//Student b; //NOT ALLOWED!
}