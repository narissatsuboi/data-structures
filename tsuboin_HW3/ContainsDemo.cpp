/**LinkedList Contains demo
 * @file ContainsDemo.cpp
 * @author Narissa T*/
#include <iostream>
#include "LinkedList.h"
#include <iostream>
#include <string>

const int ITEM_COUNT = 5;
const int TEST_ITEM_COUNT = 10;

// tests the LinkedList::contains() and LinkedList::containsRecursive() function
// from the LinkedList class
int main() {
    // set up test conditions
    std::cout << "ContainsDemo" << std::endl;
    int vals[] = {1, 2, 3, 4, 5};
    int testVals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedList<int>* listPtr = new LinkedList<int>();
    for (int i = 0; i < ITEM_COUNT; i++)
       listPtr->insert(i + 1, vals[i]);
    std::cout << "List contains: ";
    for (int i = 0; i < ITEM_COUNT; i++)
        std::cout << vals[i] << " ";
    std::cout << "Test contains: ";
    for (int i = 0; i < TEST_ITEM_COUNT; i++)
        std::cout << testVals[i] << " ";

    // test LinkedList::contains() with testVal array
    std::cout << "\n\ncontains() test "<< std::endl;
    for (int i = 0; i < TEST_ITEM_COUNT; i++)
    {
        if(listPtr->contains(testVals[i]))
        {
            std::cout << "True - contains " << listPtr->getEntry(i+1)
                      <<std::endl;
        }
        else
            std::cout << "False - does not contain " << testVals[i]  <<
                      std::endl;
    }

    // test LinkedList::containsRecursive() with testVal array
    std::cout << "\ncontainsRecursive() test" << std::endl;
    for (int i = 0; i < TEST_ITEM_COUNT; i++)
    {
        if(listPtr->containsRecursive(testVals[i]))
        {
            std::cout << "True -  contains " << listPtr->getEntry(i + 1)
            <<std::endl;
        }
        else
            std::cout << "False - does not contain " << testVals[i] <<
                      std::endl;
    }
    return 0;
}
