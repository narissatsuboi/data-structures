#ifndef HW1_CALCULATORIO_H
#define HW1_CALCULATORIO_H

#include <string>
#include "Calculator.h"
#include <vector>

/**
 * Command-line and file-based interfaces for the Calculator.
 * Throws appropriate exceptions for invalid calculations or file operations.
 *
 * @author Narissa Tsuboi
 * @version 1.0
 */
class CalculatorIO {
public:
    /**
     * calculateFile reads calculations line by line from input file and writes
     * the results line by line. If an error occurs, the output includes a
     * description of the error and the line number the error occurred on and
     * continues processing the rest of the file.
     *
     * If an output file is not found, a new file will be created. Overwrites
     * reused files.
     *
     * @param inputFilePath  Leads to file with expressions to be calculated.
     * @param outputFilePath Leads to file for results to be written to.
     */
    void calculateFile(const std::string& inputFilePath,
                       const std::string& outputFilePath);

     /**
      * calculateInteractive prompts the user for:
      * 1. First number.
      * 2. Operation (+, -, *, /).
      * 3. Second number.
      * In this order, and uses the Calculator to calculate and return the result.
      *
      * @return result The result of the math expression.
      */
    double calculateInteractive();

private:
    Calculator calc;     // A calculator instance for you to use.
    const unsigned long MAX_TOK = 3; //Max number of tokens accepted in an expr.

    //Error messages
    const std::string INVALID_OPERATOR = "invalid operator";
    const std::string INVALID_EXPR = "invalid expression";
    const std::string INVALID_OP_FIRST = "first number invalid";
    const std::string INVALID_OP_SECOND = "second number invalid";
    const std::string FILE_EMPTY = "file is empty";
    const std::string FILE_NOT_FOUND = "file not found";

    /**
     * isEmpty returns true if input file is empty.
     *
     * @param Input file stream
     * @return True if file is empty
     */
    bool isEmpty(std::ifstream &file);

    /**
     * lineToVector converts a the tokens of a string to a vector.
     * @return vector
     */
    std::vector<std::string> lineToVector(std::string);

    /**
     * isValidOp returns true if the operator is +, -, *, or *.
     *
     * @param char
     * @return True if valid operator
     */
    bool isValidOp(char c);

    /**
     * firstOperandSTOD converts a string to a double.
     * @param string
     * @return double
     */
    double firstOperandSTOD(std::string s);

    /**
     * secondOperandSTOD converts a string to a double.
     * @param string
     * @return double
     */
    double secondOperandSTOD(std::string s);


};

#endif //HW1_CALCULATORIO_H
