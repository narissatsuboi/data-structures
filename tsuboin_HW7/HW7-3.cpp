// Narissa Tsuboi
// HW7-3.cpp R0
// purpose: sort an array in O(n) time complexity
// input: size of random array from user
// process: Count Sort method
// output: prints the unsorted and sorted array to console

#include <algorithm>
#include <cstdlib> // srand, rand
#include <iostream>
#include <sstream> // toString fxn
#include <string>

using namespace std;

const int RANGE = 1000;

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

void countSort(int *arrayA, const int &sizeA, const int &sizeC) {
// sort an array of sizeA using the count sort method
// keep a tally of element occurances in arrayC
// reorder arrayA based on the tallies in arrayC
// in: integer array, size of integer array A, size of tally area C
// where sizeC is always 1 + the highest valued integer

    int *arrayC = new int[sizeC]; // array holds tallies

    // initialize c with 0's
    for (int i = 0; i < sizeC; i++)
        arrayC[i] = 0;

    // increase tally in count array for every occurrence of an element
    for (int i = 0; i < sizeA; i++)
        arrayC[arrayA[i]]++;

    int i =0, j = 0; // loop control variables for swap
    while (j < sizeC){
        if (arrayC[j] > 0){
            arrayA[i++] = j;
            arrayC[j]--;
        } else
            j++;
    }
    delete[] arrayC;
}

// program prompts user for an integer representing the desired size of a
// randomly generated array. if a string or char is entered, the size is 0.
// program sorts random array using countSort method and displays the unsorted
// and sorted array to console.
int main() {

    int n; // size of array, from user

    // intro to program message
    cout << "HW7P3\nThis program sorts a randomly generated array of size n "
            "in O(n) time using Count Sort!\n";
    cout << "The range of random numbers is from 1 to 1000.\n";

    // get array size from user and initialize random array A
    cout << "\nEnter array size: ";
    cin >> n;
    int *A = new int[n];

    // generate random array A
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int val = rand() % RANGE + 1;
        A[i] = val;
    }
    cout << "\nrandom array: " << arrayToString(A, n) << endl;

    // find max value in random array
    int max =  *max_element(A, A + n);

    // sort array and display on console
    countSort(A, n, max + 1);
    cout << "sorted array: " << arrayToString(A, n) << endl;
    cout << "\nta-da!\n";

    delete[] A;
}