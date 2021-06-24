// Narissa Tsuboi
// HW7-1.cpp R0
// purpose: find the kth integer in a sorted vector, from data from file
// input: file containing integer data, kth largest integer
// process: quicksort the data in O(nlogn) time
// output: prints the kth largest integer in the file

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const char *const LINE_SEQ = "\n\r";
const int MIN_SIZE = 3;

bool fileIsEmpty(ifstream &file) {
// check if a file is empty
// in: ifstream reference
// out: true if file is empty

    return file.peek() == ifstream::traits_type::eof();
}

bool isNumber(const string &s) {
// check if a string is an integer
// in: string reference
// out: true if string is an digit

    for (char i : s)
        if (isdigit(i) == false)
            return false;
    return true;
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
// modify: string will have no extra spaces

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

template<class ItemType>
void insertionSort(vector<ItemType> &theVector, int n) {
// sorts a vector in ascending order by separating into two partitions, in place
// in: vector reference, size of the vector n
// modify: the order of the elements in the vector

    for (int unsorted = 1; unsorted < n; unsorted++) {
        ItemType nextItem = theVector[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (theVector[loc - 1] > nextItem)) {
            theVector[loc] = theVector[loc - 1];
            loc--;
        }
        theVector[loc] = nextItem;
    }
}

template<class ItemType>
int partition(vector<ItemType> &vect, int low, int high) {
// quicksort helper function, places pivot value at end of vector, in place
// in: vector reference, range of current partition
// modify: pivot is in the end position

    int pivot = vect[high];    // pivot
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (vect[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(vect[i], vect[j]);
        }
    }
    swap(vect[i + 1], vect[high]);
    return (i + 1);
}

template<class ItemType>
void quickSort(vector<ItemType> &theVector, int first, int last) {
// sorts a vector in ascending order. uses quick sort with
// median-of-three pivot selection for arrays of at least MIN_SIZE
// entries, and uses the insertion sort for other arrays
// program assumes user knows the number of elements in the file
// in: vector reference, range of vector to be sorted
// modify: sorts vector in place

     if ((last - first + 1) < MIN_SIZE) {
        insertionSort(theVector, last - first);
    } else {
        // create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theVector, first, last);

        // sort subarrays S1 and S2
        quickSort(theVector, first, pivotIndex - 1);

        quickSort(theVector, pivotIndex + 1, last);
    }
}

// program sorts the data from file and prints the kth largest integer of
// the file using Quicksort
// program assumes user knows the number of elements in the file
int main() {
    string inputFileName, line;
    string temp;
    int k;                                      // kth integer of file to print
    int size = 0;
    vector<int> ints;                               // holds integers from file
    ifstream inFile;

    // intro to program message, get file and kth element from user
    cout << "HW7P1\nUse Quicksort to fine the kth largest integer in a "
            "file!\n";
    cout << "This program only considers the integers in a file "
            "and\nwill skip any other type of data (ie. strings).\n";
    cout << "\nEnter a filename containing integers: ";
    getline(cin, inputFileName);
    cout << "Enter the kth largest integer in the file to print: ";
    cin >> temp;

    if (isNumber(temp)) // check for integer input
        k = stoi(temp);
    else
        throw invalid_argument("error: enter integer for kth largest value");

    inFile.open(inputFileName); // open inFile

    // print error message if file is empty
    if (inFile.is_open() && fileIsEmpty(inFile))
        cerr << "error: file is empty, no results to return" << endl;

    // quicksort on open file
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            trimLineSeq(line, LINE_SEQ); // format data
            removeSpaces(line);

            // skip blank lines and non-integer data
            if (line.empty() || !isNumber(line))
                continue;

            ints.push_back(stoi(line)); // store ints in vector
            size++;
        }
        if (k > size) {
            cerr << "kth largest integer from file is: k out of range.\n";
            return (1);
        }
            // display unsorted, sorted, an k largest integer to console
        cout << "\nReading file " << inputFileName << "..." << endl;
        cout << "File contents:\t\t  ";
        for(std::vector<int>::iterator it = ints.begin(); it != ints.end();
        it++) {
            std::cout << *it <<" ";
        }
        quickSort(ints, 0, ints.size() - 1);
        cout << "\nSorted file contents: ";
        for(std::vector<int>::iterator it = ints.begin(); it != ints.end();
            it++) {
            std::cout << *it <<" ";
        }
        if (k > 0 && k < size) {
            cout << "\n\nkth largest integer from file is: " << ints[k - 1]
                 << ".\n";
        }
    }
    else {
        cerr << "error: file could not be opened" << endl;
        return (1);
    }

    inFile.close();

    return 0;
    }


