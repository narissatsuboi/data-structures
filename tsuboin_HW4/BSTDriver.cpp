/* @file BSTDriver.cpp
 * @author Narissa Tsuboi */
#include "BST.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/* Prototypes */

// prints size, leaves, height, and empty
template<class ItemType>
void printStats(const BST<ItemType> *);

// prints major heading
void printHeading(const string& );

// prints minor heading
void printSubHeading(const string& );

// prints pre, in, and postorder traversals
template<class ItemType>
void printTraversals(BST<ItemType> *);

// tests level and ancestors match expected values
template<class ItemType>
void levelAndAncestorsTest (const BST<ItemType>*, const vector<ItemType>&);

// tests if keys of a vector in are the bst
template<class ItemType>
void containsTest(BST<ItemType>*&, vector<ItemType>&);

// tests if two bsts are the same (deep copy)
template<class ItemType>
bool BSTMatch(BST<ItemType> *, BST<ItemType> *);

/* Driver Methods */

template<class ItemType>
void printStats(const BST<ItemType> * bst) {
    printf("# of nodes: %d\n", bst->size());
    printf("# of leaves: %d\n", bst->getLeafCount());
    printf("tree height: %d\n", bst->getHeight());
    cout << "tree empty: " << boolalpha << bst->empty() << endl;
}

void printHeading(const string& title)
{
   for (unsigned long i = 0; i < title.length() + 4; i++)
       cout <<"*";
   cout << endl;
   cout <<"* " << title << " *" <<endl;
    for (unsigned long i = 0; i < title.length() + 4; i++)
        cout <<"*";
    cout << endl;
}

void printSubHeading(const string& title)
{
    cout << endl;
    cout << "** " << title << " **" << endl;
}

template <class ItemType>
void printTraversals( BST<ItemType> *bst)
{
    cout << "pre-order:  " << bst->getpreorderTransversal() << endl;
    cout << "in-order:   " << bst->getinorderTransversal() << endl;
    cout << "post-order: " << bst->getpostOrderTransversal() << endl;
}

template <class ItemType>
void levelAndAncestorsTest (const BST<ItemType>* bst, const vector<ItemType>&
        v) {
    int level;
    string ancestors;
    for (size_t i = 0; i < v.size(); i++) {
        level = bst->getLevel(v.at(i));
        ancestors = bst->getAncestors(v.at(i));
        cout << "level(" << v.at(i) << "): " << level;
        cout << ", ancestors(" << v.at(i) << "): " << ancestors << endl;
    }
}

template<class ItemType>
void containsTest(BST<ItemType> *& bst, vector<ItemType>& v) {
    bool doesContain;
    for (size_t i = 0; i < v.size(); i++) {
        doesContain = bst->contains(v.at(i));
        cout << "contains(" << v.at(i) << "): " << doesContain << endl;

        // test contains
        if (!doesContain && (v.at(i) == 10 || v.at(i) == 20 || v.at(i) == 40
        ||v.at(i) == 70)) {
            printf("** FAIL - %d IS in the tree **\n", v.at(i));
        }
        else
            printf("** PASS - found %d in the tree **\n", v.at(i));
    }
}

template<class ItemType>
bool BSTMatch(BST<ItemType> *bst, BST<ItemType> *bstCopy) {
    string transversal, transversalCopy;
    transversal = bst->getpreorderTransversal();
    transversalCopy = bstCopy->getpreorderTransversal();
    if (transversal == transversalCopy)
        return true;
    else
        return false;
}

int main() {
    // pre-defined headings and messages
    string welcome = "Welcome to the Binary Search Tree program!";
    string descr = "This program demonstrates a custom BST class on integers "
                   "and strings.";
    string create = "CREATE BST";
    string insert = "TEST INSERT";
    string traversals = "TEST TRAVERSALS";
    string level = "TEST LEVEL AND ANCESTORS";
    string contains = "TEST CONTAINS";
    string remove = "TEST REMOVE";
    string insertAgain = "TEST INSERT (again)";
    string copyTest = "TEST COPY CONSTRUCTOR";
    string assignmentTest = "TEST ASSIGNMENT OPERATOR";
    string intBSTHeader = "INTEGER BINARY SEARCH TREE";
    string strBSTHeader = "STRING BINARY SEARCH TREE";

    string filename;
    string line; // holds line of file, LF termination sequence
    int tempInt; // holds converted string-> int value during file read

    vector<int> ints;
    vector<int> intListPASS = {20, 40, 10, 70};
    vector<int> testIntsFAIL = {99, -2, 59, 43};

    vector<string> strs;
    vector<string> strListpass = {"yan", "amy", "ron", "opal"};
    vector<string> strListFAIL = {"gene", "mary", "bea", "uma"};

    BST<int>*  intBST = new BST<int>();
    BST<string>* strBST = new BST<string>();

    //-------------------------------------------------------------------------
    // INTEGER BST SECTION
    //-------------------------------------------------------------------------

    // print welcome message and section header
    cout << endl << welcome << endl;
    cout << descr << endl << endl;
    printHeading(intBSTHeader);

    // print empty BST stats
    printSubHeading(create);
    printStats(intBST); // print current BST stats

    cout <<"Insert integer file: "; // get input file from user
    cin >> filename;

    // TEST INSERT -----------------------------------------------------------
    // read the file, print contents, push to reference vector, insert, reprint
    printSubHeading(insert);
    cout << "Inserting in this order: ";
    ifstream intFile(filename);
    if (intFile.is_open()) {
        while (getline(intFile, line)) {
            cout << line << " ";
            tempInt = stoi(line);
            ints.push_back(tempInt);
            intBST->insert(tempInt);
            line.clear();
        }
    }
    else
        cout << "\nUnable to open file provided, only test values will be "
                "incorporated" <<endl;
    cout << endl;
    intFile.close();
    printStats(intBST); // print current BST stats

    // TEST TRAVERSALS --------------------------------------------------------
    printSubHeading(traversals); // print current BST stats
    printTraversals(intBST); // print all three traversal types

    // TEST LEVEL & ANCESTORS -------------------------------------------------
    // level and ancestor testing within function
    printSubHeading(level);
    levelAndAncestorsTest(intBST, ints);
    levelAndAncestorsTest(intBST, testIntsFAIL);

    // TEST CONTAINS ----------------------------------------------------------
    // contains testing within function
    printSubHeading(contains);
    containsTest(intBST, ints);

    // TEST REMOVE ------------------------------------------------------------
    printSubHeading(remove);
    cout << "Removing in this order: ";
    for (size_t i = 0; i < ints.size(); i++)
        cout << ints.at(i) << " ";
    cout << endl;
    for (size_t i = 0; i < ints.size(); i++) {
        int key = ints.at(i);
        if (intBST->remove(key)) {
            cout << "** PASS - Removal of " << key << " was successful **" <<
                 endl;
        }
        else {
            cout << "** FAIL - Removal of " << key << " was unsuccessful **" <<
                 endl;
        }
    }
    printStats(intBST); // print current BST stats
    printTraversals(intBST); // print all three traversal types

    // TEST INSERT (AGAIN) ----------------------------------------------------
    printSubHeading(insertAgain);
    cout << "Inserting in this order: ";
    for (size_t i = 0; i < ints.size(); i++) {
        cout << ints.at(i) << " ";
        intBST->insert(ints.at(i));
    }
    cout <<endl;

    // ensure inserted nodes are in the BST
//    containsTestBool(intBST, ints);
    printStats(intBST); // print current BST stats
    printTraversals(intBST); // print all three traversal types

    // TEST COPY CONSTRUCTOR  -------------------------------------------------
    printSubHeading(copyTest);
    BST<int>* intBST1(intBST); // make copy of bst
    BST<int>* intBST2(intBST1); // make copy of bst
    cout << "BST2(BST1)" << endl;
    cout << "BST1: " << intBST1->getpreorderTransversal() << endl;
    cout << "BST2: " << intBST2->getpreorderTransversal() << endl;
    if (BSTMatch(intBST1, intBST2))
        cout << "** PASS: copy constructor **" << endl;

    // TEST ASSIGNMENT OPERATOR -----------------------------------------------
    printSubHeading(assignmentTest);
    cout << "Before assignment..." << endl;
    BST<int>* intBST3 = new BST<int>();
    intBST3->insert(1000);
    intBST3->insert(2000);
    intBST3->insert(3000);
    cout << "BST1: " << intBST1->getpreorderTransversal() << endl;
    cout << "BST3: " << intBST3->getpreorderTransversal() << endl;
    cout << endl << "After assignment... BST1 = BST3" << endl;
    intBST1 = intBST3;
    cout << "BST1: " << intBST1->getpreorderTransversal() << endl;
    cout << "BST3: " << intBST3->getpreorderTransversal() << endl;
    if (BSTMatch(intBST1, intBST3))
        cout << "** PASS: assignment operator **" << endl << endl;


    //-------------------------------------------------------------------------
    // STRING BST SECTION
    //-------------------------------------------------------------------------
    printHeading(strBSTHeader);
    printSubHeading(create); // print empty BST stats
    printStats(strBST); // print current BST stats

    cout <<"Insert string file: "; // get input file from user
    cin >> filename;

    // TEST INSERT -----------------------------------------------------------
    // read the file, print contents, push to reference vector, insert, reprint
    printSubHeading(insert);
    cout << "Inserting in this order: ";
    ifstream strFile("strings.dat");
    if (strFile.is_open()) {
        while (getline(strFile, line)) {
            cout << line << " ";
            strs.push_back(line);
            strBST->insert(line);
            line.clear();
        }
    }
    else
        cout << "\nUnable to open file provided, only test values will be "
                "incorporated" <<endl;

    strFile.close();
    cout << endl;
    printStats(strBST); // print current BST stats

    // TEST TRAVERSALS --------------------------------------------------------
    printSubHeading(traversals); // print current BST stats
    printTraversals(strBST); // print all three traversal types

    // TEST LEVEL & ANCESTORS -------------------------------------------------
    // level and ancestor testing within function
    printSubHeading(level);
    levelAndAncestorsTest(strBST, strs);
    levelAndAncestorsTest(strBST, strListFAIL);

    // TEST CONTAINS ----------------------------------------------------------
    // contains testing within function
    printSubHeading(contains);
    containsTest(intBST, ints);

    // TEST REMOVE ------------------------------------------------------------
    printSubHeading(remove);
    cout << "Removing in this order: ";
    for (size_t i = 0; i < strs.size(); i++)
        cout << strs.at(i) << " ";
    cout << endl;
    for (size_t i = 0; i < strs.size(); i++) {
        string key = strs.at(i);
        if (strBST->remove(key)) {
            cout << "** PASS - Removal of " << key << " was successful **" <<
                 endl;
        }
        else {
            cout << "** FAIL - Removal of " << key << " was unsuccessful **" <<
                 endl;
        }
    }
    printStats(strBST); // print current BST stats
    printTraversals(strBST); // print all three traversal types

    // TEST INSERT (AGAIN) ----------------------------------------------------
    printSubHeading(insertAgain);
    cout << "Inserting in this order: ";
    for (size_t i = 0; i < strs.size(); i++) {
        cout << strs.at(i) << " ";
        strBST->insert(strs.at(i));
    }
    cout <<endl;

    // ensure inserted nodes are in the BST
//    containsTestBool(strBST, strListFAIL);
    printStats(strBST); // print current BST stats
    printTraversals(strBST); // print all three traversal types

    // TEST COPY CONSTRUCTOR  -------------------------------------------------
    printSubHeading(copyTest);
    BST<string>* strBST1(strBST); // make copy of bst
    BST<string>* strBST2(strBST1); // make copy of bst
    cout << "BST2(BST1)" << endl;
    cout << "BST1: " << strBST1->getpreorderTransversal() << endl;
    cout << "BST2: " << strBST2->getpreorderTransversal() << endl;
    if (BSTMatch(strBST1, strBST2))
        cout << "** PASS: copy constructor **" << endl;

    // TEST ASSIGNMENT OPERATOR -----------------------------------------------
    printSubHeading(assignmentTest);
    cout << "Before assignment..." << endl;
    BST<string>* strBST3 = new BST<string>();
    strBST3->insert("this is a different BST");
    cout << "BST1: " << strBST1->getpreorderTransversal() << endl;
    cout << "BST3: " << strBST3->getpreorderTransversal() << endl;
    cout << endl << "After assignment... BST1 = BST3" << endl;
    strBST1 = strBST3;
    cout << "BST1: " << strBST1->getpreorderTransversal() << endl;
    cout << "BST3: " << strBST3->getpreorderTransversal() << endl;
    if (BSTMatch(strBST1, strBST3))
        cout << "** PASS: assignment operator **" << endl;

    cout << endl << "Goodbye!" << endl;

    delete intBST;
    delete strBST;
    delete strBST1;
    delete strBST2;
    delete strBST3;

    return 0;
}