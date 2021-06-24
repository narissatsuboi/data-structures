#include <iostream>
#include <string>
#include "Calculator.h"
#include "CalculatorIO.h"

void testCalc(std::string desc, double expected, double actual) {
    if (expected == actual) {
        std::cout << "PASS: " << desc << std::endl;
    } else {
        std::cerr << "FAIL: " << desc << "; expected: " << expected << ", actual " << actual << std::endl;
    }
}


// Driver program that tests Calculator and CalculatorIO.
// Your code MUST pass these tests.
// But note that we can and will run other tests when grading to ensure that your code meets the requirements.
int main() {
    Calculator calc;
    testCalc("basic add", 5, calc.Add(3, 2));
    testCalc("basic sub", 1, calc.Subtract(3, 2));
    testCalc("basic mult", 6, calc.Multiply(3, 2));
    testCalc("basic div", 1.5, calc.Divide(3, 2));

    CalculatorIO io;
//    io.calculateInteractive(); FUCK FUCK

//    std::cout << "Calculate something that calculates to 5" << std::endl;
//    testCalc("basic calc to 5 interactive", 5, io.calculateInteractive());

//    std::cout << "Enter a string instead of a number" << std::endl;
//    bool caughtException = false;
//    try {
//        io.calculateInteractive();
//    } catch (const std::invalid_argument& err) {
//        caughtException = (std::string(err.what()) == "first number invalid");
//        /*
//         * .what is description of the error
//         * err type (invalid_argument)
//         */
//    }
//    if (caughtException) {
//        std::cout << "PASS: invalid number" << std::endl;
//    } else {
//        std::cerr << "FAIL: invalid number" << std::endl;
//    }

//    io.calculateFile("input.txt", "output.txt");
//
//    caughtException = false;
//    try {
//        io.calculateFile("invalid_first.txt", "output.txt");
//    } catch (const std::invalid_argument& err) {
//        caughtException = (std::string(err.what()) == "first number invalid");
        /*
         * .what is description of the error
         * err type (invalid_argument)
         */
//    }
//    if (caughtException) {
//        std::cout << "PASS: invalid first number" << std::endl;
//    } else {
//        std::cerr << "FAIL: invalid second number" << std::endl;
//    }
//
//    bool caughtException = false;
//    try {
//        io.calculateFile("invalid_first.txt", "invalid_second.txt");
//    } catch (const std::invalid_argument& err) {
//        caughtException = (std::string(err.what()) == "second number invalid");
//        /*
//         * .what is description of the error
//         * err type (invalid_argument)
//         */
//    }
//    if (caughtException) {
//        std::cout << "PASS: second first number" << std::endl;
//    } else {
//        std::cerr << "FAIL: second second number" << std::endl;
//    }
//
//    bool caughtException = false;
//    try {
//        io.calculateFile("bad_op.txt", "output.txt");
//    } catch (const std::invalid_argument& err) {
//        caughtException = (std::string(err.what()) == "invalid operator");
//        /*
//         * .what is description of the error
//         * err type (invalid_argument)
//         */
//    }
//    if (caughtException) {
//        std::cout << "PASS: invalid operator" << std::endl;
//    } else {
//        std::cerr << "FAIL: invalid operator" << std::endl;
//    }
//
//    bool caughtException = false;
//    try {
//        io.calculateFile("bad_op2.txt", "output.txt");
//    } catch (const std::invalid_argument& err) {
//        caughtException = (std::string(err.what()) == "malformed operator");
//        /*
//         * .what is description of the error
//         * err type (invalid_argument)
//         */
//    }
//    if (caughtException) {
//        std::cout << "PASS: malformed operator" << std::endl;
//    } else {
//        std::cerr << "FAIL: malformed operator" << std::endl;
//    }

}
