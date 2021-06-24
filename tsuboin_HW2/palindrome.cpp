/**
 * Palindrome program reads an input file and prints whether each line of the
 * file is a palindrome or not.
 *
 * Grader note, I tried reading in the file with ifstream and getline,
 * followed the book and online and no matter what I do neither input method
 * captures the orignal string correctly. However when tested adhoc, the
 * recursive method and the supporting method processStr work.
 *
 * @author Narissa T
 * @version 1.0
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

/**
 * Recursive solution to determine if string is a palindrome.
 * @param str Input to be analyzed.
 * @return bool True or false.
 */
bool palindromeR(string &str);

/**
 * RecursiveR helper function to change all chars to lowercase and remove
 * spaces.
 * @param str Input to be analyzed.
 */
void processStr(string &str);

int main() {
    string filename;
    string welcome = "Welcome to the Palindrome program!";
    string prompt = "Enter filename: ";
    string line;
    bool isPalindrome;
    string str; //Used to hold each line from getline, to try and avoid
                //read in error I was experiencing

    //Get the filename.
    cout << welcome << endl;
    cout << prompt;
    cin >> filename;
    ifstream inFile(filename);

    //Open and read file
    while(getline(inFile, line))
    {
        str = line;
        //Format the string and pass into the recursive solution
        processStr(str);
        isPalindrome = palindromeR(str);
        if (isPalindrome)
            cout << str << " is a palindrome" << endl;
        else
            cout << str << " is not a palindrome" << endl;
    }
    inFile.close();
    return 0;
}

void processStr(string &str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    transform(str.begin(), str.end(), str.begin(),::tolower);
}
bool palindromeR(string &str)
{
    char front = str.front();
    char end = str.back();

    if (str.size() <= 2 && front == end)
        return true;
    else if (front == end)
    {
        str = str.substr(1, str.size() - 2);
        return palindromeR(str);
    }
    else
        return false;
}





