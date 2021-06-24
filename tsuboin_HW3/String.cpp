/**String class implementation
 * @file String.cpp
 * @author Narissa T
 */
#ifndef STRING_
#define STRING_
#include "String.h"
#include <string>

String::String(std::string str)
{
    listPtr = new LinkedList<char>();
    Append(str);
} // end constructor

String::~String()
{
    listPtr->clear();
} // end destructor

void String::Append(std::string str) {
    int itemLength = str.length();
    int listLength;
    char currCh;
    for (int i = 0; i < itemLength; i++)
    {
        listLength = listPtr->getLength();
        currCh = str.at(i);
        listPtr->insert(listLength + 1, currCh);
    }
} // end Append(str)

void String::Append(char ch) {
        int listLength = listPtr->getLength();
        listPtr->insert(listLength + 1, ch);
} // end Append(ch)

std::string String::toString() {
    std::string str = "";
    int listLength = listPtr->getLength();
    for (int pos = 1; pos <= listLength; pos++)
        str += listPtr->getEntry(pos);
    return str;
} // end toString()

void String::Reverse() {
    listPtr->reverse();
} // end Reverse

#include "String.cpp"
#endif


