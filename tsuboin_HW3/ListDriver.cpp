//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "LinkedList.h"
#include <iostream>
#include <string>

const int ITEM_COUNT = 6;
const int INTARR_ITEM_COUNT = 3;

int main() {
    /**
    std::cout <<"Lecture Sample Code" << std::endl;
    LinkedList<std::string>* listPtr = new LinkedList<std::string>();
    std::string data[] = {"one", "two", "three", "four", "five", "six"};
    std::cout << "isEmpty: returns " << listPtr->isEmpty()
            << "; should be 1 (true)" << std::endl;
    for (int i = 0; i < ITEM_COUNT; i++)
    {
        if (listPtr->insert(i + 1, data[i]))
        {
            try
            {
                std::cout << "Inserted " << listPtr->getEntry(i + 1)
                        << " at position " << (i + 1) << std::endl;
            }
            catch (std::invalid_argument& except)
            {
                std::cout << "Failed to get entry at position "
                          << (i + 1) << std::endl;
            }
        }
        else
        std::cout << "Cannot insert " << data[i] << " at position " << (i + 1)
                  << std::endl;
    }  // end for

    std::string removed = listPtr->replace(3, "foobar");
    std::cout << "replaced position 3 which had " << removed << " with " << listPtr->getEntry(3) << std::endl;
*/
    //TODO: Call copy constructor test?
    int intArr[] = {1, 2, 3};
    LinkedList<int>* srcPtr = new LinkedList<int>();

    std::cout << "Copy Constructor Test" << std::endl;
    std::cout << "LinkedList<int> newList = new LinkedList<int>(sourceList)\n";
    std::cout
    <<"-----------------------------------------------------------------"
    <<std::endl;
    std::cout << "Source List: ";
    for (int i = 0; i < INTARR_ITEM_COUNT; i++)
    {
        srcPtr->insert(i + 1, intArr[i]);
        std::cout << srcPtr->getEntry(i + 1) << " ";
    }

    LinkedList<int>* newListPtr = new LinkedList<int>(*srcPtr);

    std::cout << "\nNew List:    ";
    for (int i = 0; i < newListPtr->getLength(); i++)
    {
        std::cout << newListPtr->getEntry(i + 1) << " ";
    }  // end for
    std::cout
    <<"\n-----------------------------------------------------------------"
    <<std::endl;
    srcPtr->insert(srcPtr->getLength()+1, 100);

    std::cout << "Source List after insert: ";
    for (int i = 0; i < srcPtr->getLength(); i++)
    {
        std::cout << srcPtr->getEntry(i + 1) << " ";
    }
    std::cout << "\nNew List:                 ";
    for (int i = 0; i < newListPtr->getLength(); i++)
    {
        std::cout << newListPtr->getEntry(i + 1) << " ";
    }  // end for
    std::cout
    <<"\n-----------------------------------------------------------------"
    <<std::endl;

    newListPtr->insert(newListPtr->getLength()+1, 999);

    std::cout << "Source List:           ";
    for (int i = 0; i < srcPtr->getLength(); i++)
    {
        std::cout << srcPtr->getEntry(i + 1) << " ";
    }
    std::cout << "\nNew List after insert: ";
    for (int i = 0; i < newListPtr->getLength(); i++)
    {
        std::cout << newListPtr->getEntry(i + 1) << " ";
    }  // end for
    std::cout
    <<"\n-----------------------------------------------------------------"
    <<std::endl;

    std::cout << "Source addresses: ";
    for (int i = 0; i < srcPtr->getLength(); i++)
    {
        std::cout << &srcPtr[i + 1] << " ";
    }
    std::cout << "\nNew addresses:    ";
    for (int i = 0; i < newListPtr->getLength(); i++)
    {
        std::cout << &newListPtr[i + 1] << " ";
    }
    // TODO: Demonstrate assignment operator here.
    std::cout
    <<"\n-----------------------------------------------------------------"
    <<std::endl;
    std::cout << "Assignment Operator Test" << std::endl;
    std::cout << "Before assignment operator:" << std::endl;
    std::cout << "RHS List: ";
    for (int i = 0; i < srcPtr->getLength(); i++)
    {
        std::cout << srcPtr->getEntry(i + 1) << " ";
    } // end for
    std::cout << "RHS Address: " << &srcPtr << std::endl;
    std::cout << "LHS List: ";
    for (int i = 0; i < newListPtr->getLength(); i++)
    {
        std::cout << newListPtr->getEntry(i + 1) << " ";
    }  // end for

    LinkedList<int>* copyPtr = new LinkedList<int>();
    std::cout << "LHS Address: " << &copyPtr << std::endl;
    std::cout << "\nLHS = RHS\n" << std::endl;

    copyPtr->operator=(*srcPtr);

    std::cout << "After assignment operator:" << std::endl;
    std::cout << "RHS List: ";
    for (int i = 0; i < srcPtr->getLength(); i++)
    {
        std::cout << srcPtr->getEntry(i + 1) << " ";
    } // end for
    std::cout << "RHS Address: " << &srcPtr << std::endl;
    std::cout << "LHS List: ";
    for (int i = 0; i < copyPtr->getLength(); i++)
    {
        std::cout << copyPtr->getEntry(i + 1) << " ";
    }  // end for
    std::cout << "LHS Address: " << copyPtr << std::endl;

    delete srcPtr;
    srcPtr = nullptr;
    delete newListPtr;
    newListPtr = nullptr;
    delete copyPtr;
    copyPtr = nullptr;

    return 0;
      // end main
}