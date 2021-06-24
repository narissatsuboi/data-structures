/**
 * HW3 Reverse Vector
 * The Reverse Vector program recursively reverses a vector of any data type,
 * in-place. Functions are demonstrated on an integer and string vector.
 *
 * @author Narissa Tsuboi
 * @version 1.0
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>

/**
 * Recursively reverses a reference to a generic type vector from a starting
 * point to the end of the vector.
 *
 * @tparam T Template class type
 * @param v Reference to vector to be reversed
 * @param swapPos V[i] to start swap from
 * @param size Size of the vector
 */
void reverseVectorT(vector<T> &v, int swapPos, int size);

int main() {
    //Original order of vectors
    vector<int> numbers {1, 5, 6, 7, 10};
    vector<string> strings {"cat", "dog", "bird", "cow", "frog", "horse"};

    cout << "Reverse Vector <T> implementation" << endl << endl;
    cout <<"Integer vector reverse" << endl;
    cout << "Before: { ";
    for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end();
    ++i)
        cout << *i << " ";
    cout << "}" << endl;
    reverseVectorT(numbers, 0, numbers.size() - 1);

    cout << "After:  { ";
    for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end();
         ++i)
        cout << *i << " ";
    cout << "}" <<endl;

    cout << endl;

    cout << "String vector reverse" << endl;
    cout << "Before: { ";
    for (vector<string>::const_iterator i = strings.begin(); i != strings.end();
         ++i)
        cout << *i << " ";
    cout << "}" << endl;
    reverseVectorT(strings, 0, strings.size() - 1);
    cout << "After:  { ";
    for (vector<string>::const_iterator i = strings.begin(); i != strings.end();
         ++i)
        cout << *i << " ";
    cout << "}";


    return 0;
}
template<class T>
void reverseVectorT(vector<T> &v, int swapPos, int size)
{
    typename vector <T>::iterator swapStart;
    typename vector <T>::iterator swapEnd;

    if (size == 0 || size == 1) //Empty or single element, no reverse needed
        return;
    else
    {
        swapStart = v.begin() + (swapPos);
        swapEnd = v.begin() + size;
        iter_swap(swapStart, swapEnd);
        reverseVectorT(v, swapPos + 1, size - 1);
    }
}
