#pragma once

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <QString>

using namespace std;

vector<string> parseString(string);
void enterRecord(string, int);
bool searchEx(string);
int searchRecord(string);

//class that represents the user
//creates a profile for user

//TODO: Add a user profile tab to see progression
class Lifter {
	int age;
	double weight; //lbs
	int height; //inch
	string name;


public:
	//default constructor
	Lifter() { age = 0; weight = 0; height = 0; name = " "; };

	Lifter(int, double, const int, const string);

	int setAge(int lAge) { age = lAge; }
	double setWeight(double lWeight) { weight = lWeight; }
	int setHeight(int lHeight) { height = lHeight; }
	string setName(string lName) { name = lName; }

	int getAge() const { return age; }
	double getWeight() const { return weight; }
	int getHeight() const { return height; }
	string getName() const { return name; }

    void createProfile(int,double,int,string) const;

    void enterRecord(string, string);
    void enterExercise(string,string);
    string searchEx(string);
    int searchRecord(string);
};
