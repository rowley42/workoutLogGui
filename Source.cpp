/* 
-Creating a program to record workout progress and add training programs
-First, allow the user to enter a workout program with exercises, reps, and sets.


-Add exercise class to allow user to modify sets and reps, and enter current best weight.
*/

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "lifter.h"

using std::cout;
using std::cin;

int main() {

	ifstream fin;
	ofstream fout;
	
	cout << "~~ Workout Progress Tracker ~~" << endl;

	Lifter u;

	u.createProfile();

	fin.open("testRoutine.txt");
	fout.open("testRoutine.txt", ios::app);
	
	int enterChoice;

	string buf;
	int userAmount;
	string inputEx;
	string getSearch;
	string userExercise;
	int recordNum;
	string endLoop;
	bool eL = true;

	if (fin.good()) {
		if (fout.good()) {

			cout << "[1] Add New Exercises \n";
			cout << "[2] Enter New Personal Record \n";
			cout << "[3] Search For An Exercise \n";
			cout << "[4] Search For A Previous Record \n";

			cin >> enterChoice;

			switch (enterChoice) {
			case 1:
				cout << "How many exercises would you like to add?" << endl;
				cin >> userAmount;
				cin.ignore(INT_MAX, '\n');

				for (int i = 0; i < userAmount; i++) {
					cout << "Enter your exercise: " << endl;
					getline(cin, inputEx);
					fout << inputEx << " ";
					cout << "Enter your sets by reps: " << endl;
					getline(cin, inputEx);
					fout << inputEx << endl;


				}
				break;

			case 2:
				cout << "Would you like to enter a new PR?\n";
				cin >> getSearch;
				if (getSearch == "Y") {
					cout << "Enter the exercise: \n";
					cin.ignore();
					getline(cin, userExercise);
					cout << "Now enter your PR: \n";
					cin >> recordNum;
					enterRecord(userExercise, recordNum);

				}
				break;

			case 3:
				cout << "Would you like to search for an exercise?\n";
				cin >> getSearch;
				if (getSearch == "Y") {
					cout << "Ok, please enter the exerise to search: " << endl;
					cin.ignore();
					getline(cin, userExercise);
					searchEx(userExercise);

				}
				break;

			case 4:
				cout << "Would you like to search for a PR?\n";
				cin >> getSearch;
				if (getSearch == "Y") {
					cout << "Ok, please enter the exerise to search: " << endl;
					cin.ignore();
					getline(cin, userExercise);
					searchRecord(userExercise);

				}
				break;

			default:
				cout << "No valid selection. Please try again. \n";
				break;
			}

			


		}

	}

	fout.close();
	fin.close();
	


	return 0;
}

