// Narissa Tsuboi
// fib.cpp R1
// Purpose: Compares the execution time of the iterative and recursive
//          solutions to the fibonnaci sequence. Implements a recursive
//          function that eliminates duplicate computation.
/*
 * ANSWER 1 - DID fibRecursive(45) RUN TO COMPLETION ON YOUR SYSTEM, AND IF
 * NOT, HOW LARGE A NUMBER DID YOU TEST?
 * I was able to run up to n = 40 my machine without causing a stack dump.
 * ANSWER 2 - TIME FOR fibIterative(40) ON YOUR SYSTEM = 12 ms
 * ANSWER 3 - TIME FOR fibRecursive(40) ON YOUR SYSTEM = 1552 ms
 * ANSWER 4 - TIME FOR fibRecursiveBetter(40) ON YOUR SYSTEM = 1555 ms
*/

#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const unsigned long N = 40; // max fib number per program specs

void fibIterative(unsigned long num);
// displays the nth number of the fib sequence using iterative implementation

void fibRecursive(unsigned long num);
// displays the nth number of the fib sequence using recursive implementation

void fibRecursiveBetter(unsigned long num);
// displays the nth fib number of the fib sequence using memoized recursive
// implementation

unsigned long getFib(unsigned long i);
// returns the nth fib number given its place in the sequence

// displays fib numbers thru F(45) using iterative, recursive, and an
// improved recursive function
int main() {
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double> exe_time;
    double iterativeTime, recursiveTime, recursiveBetterTime;

    //fibIterative demonstration
    cout << noshowpoint;
    cout << "Fibonacci Number Implementation Demo" << endl;
    cout << "All timings conducted to n = " << N << endl << endl;

    //fibIterative
    cout << "Timing fibIterative of n = 45..." << endl;
    start = std::chrono::high_resolution_clock::now();
    fibIterative(N);
    end = std::chrono::high_resolution_clock::now();
    exe_time = (end - start) * 1000;
    iterativeTime = std::round(exe_time.count());
    cout << "fibIterative(" << N << ") time elapsed = " << iterativeTime <<
    " ms" << endl << endl;

    //fibRecursive
    cout << "Timing fibRecursive of n = 45..." << endl;
    start = std::chrono::high_resolution_clock::now();
    fibRecursive(N);
    end = std::chrono::high_resolution_clock::now();
    exe_time = (end - start) * 1000;
    recursiveTime = std::round(exe_time.count());
    cout << "fibRecursive(" << N << ") time elapsed = " << recursiveTime<< " ms"
    << endl << endl;

    //fibRecursiveBetter
    cout << "Timing fibRecursiveBetter of n = 45..." << endl;
    start = std::chrono::high_resolution_clock::now();
    fibRecursiveBetter(N);
    end = std::chrono::high_resolution_clock::now();
    exe_time = (end - start) * 1000;
    recursiveBetterTime = std::round(exe_time.count());
    cout << "fibRecursiveBetter(" << N << ") time elapsed = " <<
    recursiveBetterTime << " ms" << endl;

    cout << "Summary of Times..." << endl;
    cout << "fibIterative(" << N << ") - " << iterativeTime << " ms" << endl;
    cout << "fibRecursive(" << N << ") - " << recursiveTime << " ms" << endl;
    cout << "fibRecursiveBetter(" << N << ") - " << recursiveBetterTime << " ms"
    << endl << endl;

    return 0;
}

void fibIterative(unsigned long num) {
// displays the nth number of the fib sequence using iterative implementation
// in: nth fib number to print
    unsigned long prevPrevN = 0;
    unsigned long prevN = 1;
    unsigned long currN;

    if (num <= 1)
    {
        cout << num;
        return;
    }
    for (unsigned long i = 1; i <= num; i++)
    {
        currN = prevPrevN + prevN;
        prevPrevN = prevN;
        prevN = currN;
        cout << "n=" << i << ", " << currN << endl;
    }
}

void fibRecursive(unsigned long num) {
// displays the nth number of the fib sequence using recursive implementation
// in: nth fib number to print
    unsigned long result = 0; //Accumulator holds total of recursive calls
    for (unsigned long i = 1; i <= num; i++) {
        result = getFib(i);
        cout << "n=" << i << ", " << result << endl;
    }
}

unsigned long getFib(unsigned long i)
{
// returns the nth fib number given its place in the sequence
// in: ith fib number sequence
    if (i <= 1)
        return i;
    return getFib(i - 1) + getFib(i - 2);
}

vector<unsigned long> vMemo(N);
void fibRecursiveBetter(unsigned long num) {
// displays the nth fib number of the fib sequence using memoized recursive
// implementation
// in: nth fib number to print
    unsigned long result = 0; //Accumulator holds total of recursive calls
    if (num <= 1)
    {
        cout << num;
        return;
    }
    if (vMemo[num - 1] != 0) //If F[n] prev calculated, get from vector
    {
        cout << vMemo[num];
        return;
    }
    for (unsigned long i = 1; i <= num; i++) //Else use recursion
    {
        result = getFib(i);
        vMemo[num] = result;
        cout << "n=" << i << ", " << result << endl;
    }
}
