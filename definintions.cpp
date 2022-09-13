#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <QTextStream>

#include "lifter.h"

using namespace std;

Lifter::Lifter(int lAge, double lWeight, int lHeight, string lName)
	:age(lAge), weight(lWeight), height(lHeight), name(lName) {

}

void Lifter::enterExercise(string ex, string rep){

    ofstream fout;

    fout.open("testRoutine.txt",ios::app);

    if (fout.good()){
        fout << ex << " ";
        fout << rep <<"\n";
    }

    fout.close();
}

string Lifter::searchEx(string search) {
    string data;
    ifstream fin;
    fin.open("testRoutine.txt");
    vector<string> parseEx = parseString(search);

    string userSets;

    if (fin.good()) {
        while (getline(fin, data)) {
            vector<string> tokens = parseString(data);

            for (string::size_type i = 0; i < tokens.size(); i++) {

                if ((tokens[i] == search) && (tokens.size() > 1)) {  //search for any 1 token name (ex. bench)
                    string data = tokens[i];


                    userSets = tokens[i + 1];

                }

                else if (tokens.size() > 2) {  //search for any token above 1 token (ex. tricep extensions)
                    for (string::size_type h = 0; i < parseEx.size(); i++) { //nested loop to compare search ex and actual exs
                        if ((tokens[i] == parseEx[h]) && (tokens[i + 1] == parseEx[h + 1]) && (tokens.size() > 2)) {
                            string data = tokens[i];


                            userSets = tokens[i + 2];
                        }
                    }
                }

            }
        }
    }

    return userSets;
}

void Lifter::createProfile(int ages, double weights, int heights, string names) const{
    //string names;
    //int ages;
    //double weights;
    //int heights;

    ifstream fin;
    ofstream fout;

    fin.open("testRoutine.txt", ios::binary);
    fout.open("testRoutine.txt", ios::app);
    fin.seekg(0, ios::end);
    int file_size = fin.tellg();

    if (fin.good()) {
        if (fout.good()) {
            if (file_size == 0) {

                //cout << "Your name does not appear as a profile. Continue creating profile..." << endl;
                //cout << "Enter your Age: "; cin >> age;
                //cout << "Enter your weight: "; cin >> weight;
                //cout << "Enter your height in inches: "; cin >> height;

                Lifter profile(ages, weights, heights, names);

                fout << profile.getName() << " ";
                fout << "Age: " << profile.getAge() << " ";
                fout << "Weight: " << profile.getWeight() << " ";
                fout << "Height: " << profile.getHeight() << " " << endl;

            }
        }
    }

}

void Lifter::enterRecord(string ex, string rec) {
	ifstream fin;
	ofstream fout;
	string data;


	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
  localtime_s(&timeinfo, &rawtime);
	

	fin.open("liftrecords.txt");
	fout.open("liftrecords.txt", ios::app);

	if (fin.good()) {
		if (fout.good()) {
				//if no line displaying PR section, make one
				vector<string> tokens = parseString(data);

				//if "PR:" doesnt exist, add it and add "ex" as the PR.
				//if "PR:" does exist for said "ex" append new pr.
				//search vector for occurence of "PR:" and "ex" parameter

                fout << ex << " PR: " << rec << " LBS" << " | " << asctime(&timeinfo) << endl;
                cout << ex << " PR: " << rec << " LBS" << " | " << asctime(&timeinfo) << endl;
		}
	}

}

int Lifter::searchRecord(string ex) {
	ifstream fin;
	string data;
	int prReturn = 0;
	int largestRec = 0;
	fin.open("liftrecords.txt");
	vector<string> parseEx = parseString(ex); //parsing the users search incase it is larger than 1 word

	if (fin.good()) {

		while (getline(fin, data)) {  //iterating through the entire .txt file
			vector<string> tokens = parseString(data);  //parsing text block seperated by whitespace

            for (string::size_type i = 0; i < tokens.size(); i++) {

				if ((tokens[i] == ex) && (tokens.size() > 1)) {  //search for any 1 token name (ex. bench)
					string data = tokens[i];
					prReturn = stoi(tokens[i + 2]);

					if (prReturn > largestRec) {
						largestRec = prReturn;
					}
				}



				else if (tokens.size() > 2) {  //search for any token above 1 token (ex. tricep extensions)
                    for (string::size_type h = 0; i < parseEx.size(); i++) { //nested loop to compare search ex and actual exs
						if ((tokens[i] == parseEx[h]) && (tokens[i + 1] == parseEx[h + 1]) && (tokens.size() > 2)) { //if user search is > 1 word and matches txt
							string data = tokens[i];
							prReturn = stoi(tokens[i + 3]);
							
							if (prReturn > largestRec) {
								largestRec = prReturn;
							}
						}

						  
					}
                }
			}
		}

        if (largestRec == 0) {
			cout << "PR not found for " << ex << "." << " Try entering a new PR.\n";
		}
		else {
			cout << "PR for " << ex << " is " << largestRec << ".\n";
		}

	}

	return prReturn;  //return the integer user was looking for

}

//parsing through data
vector<string> parseString(string str) {
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}
