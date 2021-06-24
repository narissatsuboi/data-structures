/**String class
 * @file String.h
 * @author Narissa T
 */
#ifndef LECTURECODE_STRING_H
#define LECTURECODE_STRING_H
#include "LinkedList.h" // for LinkedList ADT capabilities
#include <string>

class String
{
private:
    LinkedList<char>* listPtr;
public:
    // String class overloaded constructor
    // precondition: str is a std::string
    // postcondition: a String object is created
    String(std::string str);

    // deconstructs a String object
    // precondition: is applied to a String object
    // postcondition: the String object is deleted
    virtual ~String();

    // adds the input to the end of the String
    // precondition: str is a std::string
    // postcondition: str is at the end of the String
    void Append(std::string str);

    // adds the input to the end of the String
    // precondition: ch is a char
    // postcondition: ch is at the end of the String
    void Append(char ch);

    // returns a concatenated string of all elements in String
    std::string toString();

    // reverses the order of the elements in the String
    void Reverse();
};
#endif //LECTURECODE_STRING_H
