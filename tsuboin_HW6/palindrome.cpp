// Narissa Tsuboi
// palindrome.cpp R1
// Purpose: Palindrome program reads an input file and displays whether each
//          line of the file is a palindrome or not
// Input: An input file containing a line or lines of phrases or words
// Process: Recursively check for palindrome with checkPalindrome
// Output: True or false printed to screen with the corresponding input

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

const char* lineSeparators = " \r\n";

bool checkPalindrome(string str, int start, int end);
// Recursively compare starting and ending character of work, moving inward
// on each iteration until starting position is greater than ending position
// (true) or characters do not match (false)
// pre: string must be formatted with spaces removed and all lowercase or all
//      uppercase

string rtrim(std::string, const char* t = lineSeparators);
// Trim line separators from right end of string
// pre: a string reference
// post: string formatted to specifications above


string formatStr(string);
// checkPalindrome's helper function removes spaces and changes string to
// lowercase to prepare it for processing
// note: since string is not reused later in program, reference is used
// pre: a string reference
// post: string formatted to specifications above

int main() {

    string inputFileName, outputFileName;
    string line, formattedLine;

    cout << "\nWelcome to the Palindrome program!\n\n";
    // Get filename from user and open file
    cout << "Enter the input file path: ";
    getline(cin, inputFileName);
    ifstream inFile("words.txt");

    // Read and parse input file
    cout << "\nResults from " << inputFileName << "..." << endl << endl;
    while(getline(inFile, line))
    {
        line = formatStr(line);

        // check line and print results
        if (checkPalindrome(line, 0, line.length() - 1)) {
            cout << "\"" << line << "\"" << " - palindrome." <<
                 endl;
        }
        else {
            cout << "\"" << line << "\"" << " - NOT a palindrome." <<
                 endl;
        }
    }
    cout << "\nPalindrome check complete." << endl;
    inFile.close();
    return 0;
}

string rtrim(std::string str, const char* t) {
// trim line separators from right end of string
// in: string reference

    str.erase(str.find_last_not_of(t) + 1);
    return str;
}

string formatStr(string str) {
// removes spaces and changes string to lowercase
// in: string reference

    // trim rhs line separators
    str = rtrim(str);
    // remove lineSeparators w/i string
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    // to lowercase
    transform(str.begin(), str.end(), str.begin(),::tolower);

    return str;
}
bool checkPalindrome(string str, int start, int end)
{
// recursively compare starting and ending character of work, moving inward
// in: string, start and end indices
// out: Return true when start >= end.

    //base case - only one character left to compare
    if (start >= end)
        return true;
    //start and end aren't the same
    if (str[start]!= str[end])
        return false;
    // more than 2 characters, check the substring from in to out
    return checkPalindrome(str, start + 1, end - 1);
}





