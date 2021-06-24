/**
 * HW2 Fibonacci Tester
 * The Fibonacci Tester program compares the performance of Fibonacci sequence
 * functions, iterative, recursive, and memoized.
 *
 * @author Narissa Tsuboi
 * @version 1.0
 */

#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Prints the nth number of the Fibonacci sequence using an iterative
 * implementation.
 *
 * @param num F[n]
 */
void fibIterative(unsigned long num);

/**
 * Prints the nth number of the Fibonacci sequence using a recursive
 * implementation.
 *
 * @param num The nth Fib. index.
 */
void fibRecursive(unsigned long num);

/**
 * Prints the nth number of the Fibonacci sequence using a memoized
 * implementation in which previously calculated F[n]s are stored and
 * accessed again from a vector.
 *
 * @param num The nth Fib. index.
 */
void fibRecursiveBetter(unsigned long num);

/**
 * Helper function to return the nth number of the Fibonacci sequence
 * recursively.
 *
 * @param num The nth Fib. index.
 * @return F[n] The value of the nth Fib. number.
 */
unsigned long getFib(unsigned long n);

const unsigned long N = 45; // Spec'd nth Fib number

void fibIterative(unsigned long num) {
    unsigned long prevPrevN = 0;
    unsigned long prevN = 1;
    unsigned long currN;

    if (num <= 1)
    {
        cout << num;
        return;
    }
    for (unsigned long i = 1; i < num; i++)
    {
        currN = prevPrevN + prevN;
        prevPrevN = prevN;
        prevN = currN;
    }
    cout << currN;
}

void fibRecursive(unsigned long num) {
    unsigned long result = 0; //Accumulator holds total of recursive calls
    for (unsigned long i = 1; i <= num; i++)
        result = getFib(i);
    cout << result;
}

unsigned long getFib(unsigned long n)
{
    if (n <= 1)
        return n;
    return getFib(n - 1) + getFib(n - 2);
}

vector<unsigned long> vMemo(N);
void fibRecursiveBetter(unsigned long num) {
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
    }
    cout << result;
}

/*
 * ANSWER 1 - DID fibRecursive(45) RUN TO COMPLETION ON YOUR SYSTEM, AND IF
 * NOT, HOW LARGE A NUMBER DID YOU TEST?
 * Yes, the recursive function call ran to completion in less than 13,000 ms
 * and had the worst time to execute.
 * ANSWER 2 - TIME FOR fibIterative(45) ON YOUR SYSTEM < 0 ms
 * t < 0 ms (no higher precision available w/o boost library)
 * ANSWER 3 - TIME FOR fibRecursive(45) ON YOUR SYSTEM = 13000 ms
 * t = 13000 ms = 13 s
 * ANSWER 4 - TIME FOR fibRecursiveBetter(45) ON YOUR SYSTEM = < 0 ms
 * t < 0 ms (no higher precision available w/o boost library)
*/

int main() {
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double> exe_time;

    //fibIterative demonstration
    cout << noshowpoint;
    cout << "this is a demonstration of three fibonnaci methods" << endl;
    cout << "n = " << N << endl;

    //fibIterative
    cout << "      fibIterative = ";
    start = std::chrono::high_resolution_clock::now();
    fibIterative(N);
    end = std::chrono::high_resolution_clock::now();
    exe_time = (end - start) * 1000;
    cout << ", " << std::round(exe_time.count()) << " ms" << endl;

    //fibRecursive
    cout << "      fibRecursive = ";
    start = std::chrono::high_resolution_clock::now();
    fibRecursive(N);
    end = std::chrono::high_resolution_clock::now();
    exe_time = (end - start) * 1000;
    cout << ", " << std::round(exe_time.count()) << " ms" << endl;

    //fibRecursiveBetter
    start = std::chrono::high_resolution_clock::now();
    cout <<"fibRecursiveBetter = ";
    end = std::chrono::high_resolution_clock::now();
    fibRecursiveBetter(N);
    exe_time = (end - start) * 1000;
    cout << ", " << std::round(exe_time.count()) << " ms" << endl;

    return 0;
}
