// Narissa Tsuboi
// HW7-2.cpp R0
// purpose: merge sort two files of integer or string data
// input: 2 files containing integer or string data
// process: merge sort
// output: sorted elements in output.txt
/*
 * The time complexity of merge sorting two sorted lists is O(m + n) because
 * mergeSort's traversals happen simultaneously for the list of length m and
 * again for the list of length n. At each traversal, the current pair of
 * elements in compared, were the smallest is selected and the that list's
 * loop control variable is increments. Regardless of which list held the
 * smallest element for that comparision, both lists were traversed. The
 * worst case scenario happens when the last element of one is list greater
 * than the second to last element of the other list, requiring all the
 * elements in both elements to be traversed.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


const char *const LINE_SEQ = "\n\r";       // to trim line sequences from files

void intro() {
// prints a welcome message and program explanation to screen
    cout << "HWP2\nProgram merges the contents of two files together in an "
            "output file!\nAccepts (2) files containing strings OR (2) files "
            "containing integers.\n";
    cout << "The program stores the merged file contents in output.txt\n";
}

void trimLineSeq(std::string &str, const char *t) {
// trim line sequences from right end of string in place
// in: string reference
// modify: string will have no line sequence separators

    str.erase(str.find_last_not_of(t) + 1);
}

void removeSpaces(std::string &str) {
// erase spaces from string
// in: string reference
// modify: string will have  spaces

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

int getCountFromFile(const string& filename) {
// counts the non-blank lines of elements in a file
// in: filename reference
// out: count, number of elements found
    ifstream inFile(filename);
    string line;
    int count = 0;
    while(getline(inFile, line)) {
        if (line.empty())
            continue;
        else
            count++;
    }
    inFile.close();
    return count;
}

string getFirstNonEmptyLine(const string& filename) {
// returns the first nonblank line from file
// in: filename reference
// out: contents of the line

    string line, firstLine;
    ifstream inFile(filename);
    do {
        getline(inFile, line);
    }while(line.empty());

    firstLine = line;
    trimLineSeq(firstLine, LINE_SEQ);
    removeSpaces(firstLine);

    inFile.close();
    return firstLine;
}

bool isNumber(const string& str) {
// returns false if none of the digit parameters are found, true if they are
    return str.find_first_not_of("0123456789") == string::npos;
}

template <class ItemType>
void populateIntArray(const string &filename, ItemType array) {
// reads elements from a file and stores them into a integer array
// throws: invalid argument on mixed data eg "12c3"
// in: filename, array
// modify: array is populated with integer elements from file

    int i = 0; // loop-control variable
    string line;
    ifstream inFile(filename);

    while (getline(inFile, line)) {
        trimLineSeq(line, LINE_SEQ); // allow reading from LF and CRLF
        removeSpaces(line);

        if (line.empty()) // skip blank lines
            continue;

        try {
            array[i] = stoi(line); // store elements
        } catch (invalid_argument &e) {
            throw invalid_argument("invalid data: "
                                   "data cannot be mixed " + line);
        }
        i++;
    }
    inFile.close();
}

template <class ItemType>
void merge(ItemType arr[], int l, int m, int r) {
// merge a single list by splitting into sub arrays
// arr[l+m] and arr[m+1...r]
// in: array pointer, left index, middle index and right index
// modify: array is sorted in ascending order

    int k;
    int n1 = m - l + 1;
    int n2 = r - m;

    auto* L = new ItemType[n1]; // create temp arrays
    auto* R = new ItemType[n2];

    // copy data to temp subarrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // merge the temp subarrays back into the main arr[l..r]
    int i = 0, j = 0; // loop control variables
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

template <class ItemType>
void mergeSort(ItemType arr[], int l, int r) {
// recursively merge sort an array in ascending order
// in: left index, right index
// modify: array is sorted in ascending order

    if (l < r) {

        // Same as (l+r)/2 but avoids
        // overflow for large l & h
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

template <class ItemType>
void mergeSort(ItemType A[], ItemType B[], ItemType C[],
               const int& sizeA, const int& sizeB) {
// merge sorts separate arrays into a single array in ascending order
// in: (2) arrays two be merged, (1) array to hold sorted contents, array sizes
// modify: (2) arrays to be merged are sorted and (1) array to hold content
// is sorted

    int i = 0, j = 0, k = 0;

    // mergeSort A and B individually
    mergeSort(A, 0, sizeA - 1);
    mergeSort(B, 0, sizeB - 1);

    // mergeSort the arrays A and B into C
    while (i < sizeA && j < sizeB) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while (i < sizeA)
        C[k++] = A[i++];
    while (j < sizeB)
        C[k++] = B[j++];
}

template <class ItemType>
void populateStrArray(const string &filename, ItemType array) {
// reads elements from a file and stores them into a string array
// throws: invalid argument on mixed data eg "12c3"
// in: filename, array
// modify: array is populated with string elements from file

    int i = 0; // loop-control variable
    string line;
    ifstream inFile(filename);

    while (getline(inFile, line)) {
        trimLineSeq(line, LINE_SEQ); // allow reading from LF and CRLF
        removeSpaces(line);

        if (line.empty()) // skip blank lines
            continue;

        array[i] = line; // store elements

        i++;
    }
    inFile.close();
}

template <class ItemType>
string arrayToString(ItemType *array, const int &size) {
// toString method for arrays
// in: array pointer and size
// out: string containing array contents

    int i = 0; // loop control variable
    stringstream sso;
    while (i < size) {
        sso << array[i] << " ";
        i++;
    }
    return sso.str();
}


// purpose: program asks user for two files of the same datatype (string or
// integer) and merges them into outputfile.txt
// if a file where the first line is type string and the other type integer
// is found, program throws invalid argument
int main(){
    string inputFile1, inputFile2, line;
    ofstream outFile("output.txt");

    int sizeA, sizeB, sizeC;    // array sizes
    string firstLineA, firstLineB;    // holds 1st nonempty line from each file

    intro();               // welcome the user and explain the program
    cout << "\nEnter the 1st file name: ";               // get files from user
    getline(cin, inputFile1);
    cout << "Enter the 2nd file name: ";
    getline(cin, inputFile2);


    ifstream inFile1(inputFile1);                                 // open files
    ifstream inFile2(inputFile2);
    if (!inFile1.is_open() || !inFile2.is_open()) { // error opening file check
        cerr << "error: could not open file" << endl;
        return (1);
    }

    sizeA = getCountFromFile(inputFile1);             // get number of elements
    sizeB = getCountFromFile(inputFile2);
    sizeC = sizeA + sizeB;

    firstLineA = getFirstNonEmptyLine(inputFile1);   // get first nonempty line
    firstLineB = getFirstNonEmptyLine(inputFile2);

    // populate arrays and merge if both files are type integer
    if (isNumber(firstLineA) && isNumber(firstLineB)) {
        int *intA = new int[sizeA];
        int *intB = new int[sizeB];
        int *intC = new int[sizeC];

        cout << "\n1st line of both files are integers, proceed!\n";
        populateIntArray(inputFile1, intA);
        populateIntArray(inputFile2, intB);

        cout << "1st file: " << arrayToString(intA, sizeA) << endl;
        cout << "2nd file: " << arrayToString(intB, sizeB) << endl;

        cout << "\nMerging files...\n";
        cout << "\nWriting to output.txt...\n";
        mergeSort(intA, intB, intC, sizeA, sizeB);
        cout << "output.txt: " << arrayToString(intC, sizeC) << endl;
        for (int i = 0; i < sizeC; i++) {                      // write to file
            outFile << intC[i] << endl;
        }

        delete[] intA;
        delete[] intB;
        delete[] intC;

    } // populate arrays and merge if both files are type string
    else if (!isNumber(firstLineA) && !isNumber(firstLineB)) {
        auto *strA = new string[sizeA];
        auto *strB = new string[sizeB];
        auto *strC = new string[sizeC];

        cout << "\n1st line of both files are strings, proceed!\n";
        populateStrArray(inputFile1, strA);
        populateStrArray(inputFile2, strB);

        cout << "1st file: " << arrayToString(strA, sizeA) << endl;
        cout << "2nd file: " << arrayToString(strB, sizeB) << endl;

        cout << "\nMerging files...\n";
        cout << "\nWriting to output.txt...\n";
        mergeSort(strA, strB, strC, sizeA, sizeB);
        cout << "output.txt: " << arrayToString(strC, sizeC) << endl;

        for (int i = 0; i < sizeC; i++) {                      // write to file
            outFile << strC[i] << endl;
        }

        delete[] strA;
        delete[] strB;
        delete[] strC;
    }
    else { // type string and type integer not permitted
        cerr << "error: the first line of both files must be string or "
                "integer, not a mix\n";
        return(1);
    }

    inFile1.close();
    inFile2.close();
    outFile.close();

    return (0);
}