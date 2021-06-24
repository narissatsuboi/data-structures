/**String class demo
 * @file StringDemo.cpp
 * @author Narissa T*/
#include <iostream>
#include "String.h"
#include <string>

int main() {
    std::cout << "StringDemo" << std::endl;

    std::string test = "";
    std::string testStr[] = {"abc", "efg"};
    char testChar[] = {'1', '2'};

    // initialize a new String object with String constructor
    String *myString = new String(test);

    // demonstrate append with a toString after each append
    // append strings
    std::cout << "Input: \""  << testStr[0]
    << "\" and \"" << testStr[1] << "\"" << std::endl;
    myString->Append(testStr[0]);
    myString->Append(testStr[1]);
    // append chars
    std::cout << "Output:" << myString->toString() << std::endl;
    std::cout << "Input:\'" << testChar[0]
              << "\' and \'" << testChar[1] << "\'" << std::endl;
    myString->Append(testChar[0]);
    myString->Append(testChar[1]);
    std::cout << "Output:" << myString->toString() << std::endl;

    // reverse the String and print it
    myString->Reverse();
    std::cout << "Reversed: " << myString->toString() << std::endl;

    //safe delete pointer
    delete myString;
    myString = nullptr;
    return 0;
}
