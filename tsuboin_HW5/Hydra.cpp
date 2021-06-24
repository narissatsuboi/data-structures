// Narissa Tsuboi
// File: Hydra.cpp
// Date: April 11, 2018
// Purpose: This program is used to run time trials and gather data for a Big
// O analysis on the Hydra challenge presented in Data Abstraction and
// Problem Solving #10.6.
// Input: String inputted from the user.
// Process: Hydra prints the runtime of the hydraSlayer function for
//          Big O analysis. Note: The Random String generator was used
//          for testing purposes, however, the final program gets a string from
//          the user.
// Output: Displays the runtime of the function and the number of "heads"
//         removed.

#include "LinkedList.h"
#include "Timer.h"

#include <iostream>
#include <string>
#include <cstdlib> // for rand and srand
#include <sstream> // for random string generator

using namespace std;

string getRandomString(const int&);
// Random string generator returns strings of length "len"
// IN: len, desired length of string
// OUT: sso.str(), string

int main() {
    string str, headStr, tempStr;
    int count = 1; // accumulator for number of "heads" removed

    cout << "HYDRA SLAYER" << endl;
    cout << "Slice a head when the string is one character, \nelse, slice a "
            "head and replace it with two \ncopies with one less character!"
            << endl << endl;
    cout << "Enter a string: ";
    cin >> str;

    // generate random string (for time trials only)
    // adjust len of string for each trial
//    str = getRandomString(20);
    cout << "Seed String: " << str << endl;

    // initialize linked list and seed with first string
    LinkedList<string> *hydra = new LinkedList<string>();
    hydra->insert(1, str);

    { // start Timer
        Timer x = Timer("Hydra Slaying Runtime");
        while (!hydra->isEmpty()) {
            cout << hydra->toString() << endl; // optional
            headStr = hydra->getEntry(hydra->getLength());
            tempStr = headStr; // create replacement node
            tempStr.erase(tempStr.begin());
            hydra->remove(hydra->getLength());
            count++;
            if (headStr.size() > 1) {
                hydra->insert(hydra->getLength() + 1, tempStr);
                hydra->insert(hydra->getLength() + 1, tempStr);
            }
        }
        cout << "Heads chopped: " << count << endl;
    } // end Timer

    delete hydra; // deallocate pointer memory
    hydra = nullptr;

    return 0;
}

string getRandomString(const int& len) {
    stringstream sso;                   // holds random string
    char c;                             // holds random character
    srand (time(nullptr));  // seed the random generator

    for (int i = 0; i < len; i++) {
        c = 'A' + rand()%26;
        sso << c; //
    }
    return sso.str();
} // end getRandomString
