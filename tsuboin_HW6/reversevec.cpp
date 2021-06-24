// Narissa Tsuboi
// reversevec.cpp R1
// purpose: recursively reverse a vector of any data type, in-place

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>

void reverseVectorT(vector<T> &v, int swapPos, int size);
// recursively reverses a reference to a generic type vector from a starting
// point to the end of the vector

int main() {
    //Original order of vectors
    vector<int> numbers {1, 5, 6, 7, 10};
    vector<string> strings {"cat", "dog", "bird", "cow", "frog", "horse"};

    cout << "\nReverse Vector <T> implementation" << endl << endl;
    cout <<"Reverse Integer Vector..." << endl;
    cout << "Before: { ";
    for (int number : numbers)
        cout << number << " ";
    cout << "}" << endl;
    reverseVectorT(numbers, 0, numbers.size() - 1);

    cout << "After:  { ";
    for (int number : numbers)
        cout << number << " ";
    cout << "}" <<endl;

    cout << endl;

    cout << "Reverse String Vector" << endl;
    cout << "Before: { ";
    for (const auto & string : strings)
        cout << string << " ";
    cout << "}" << endl;
    reverseVectorT(strings, 0, strings.size() - 1);
    cout << "After:  { ";
    for (const auto & string : strings)
        cout << string << " ";
    cout << "}" << endl;

    return 0;
}
template<class T>
void reverseVectorT(vector<T> &v, int swapPos, int size)
{
// recursively reverses a reference to a generic type vector from a starting
// point to the end of the vector
// in: vector reference, 0 for starting swapPos, size of the vector
    typename vector <T>::iterator swapStart;
    typename vector <T>::iterator swapEnd;

    // base case: empty or single element, no reverse needed
    if (size == 0 || size == 1)
        return;
    // sub-problem: element size > 1
    else
    {
        swapStart = v.begin() + (swapPos);
        swapEnd = v.begin() + size;
        iter_swap(swapStart, swapEnd);
        reverseVectorT(v, swapPos + 1, size - 1);
    }
}
