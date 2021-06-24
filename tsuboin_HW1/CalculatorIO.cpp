// TOOO: CalculatorIO implementation goes in this file.

#include "CalculatorIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

/*
 * Errors:
 * Invalid format (too few or too many args)
 * Invalid operator
 * Malformed operator
 *
 */

void CalculatorIO::calculateFile(const std::string &inputFilePath,
                                 const std::string &outputFilePath)
{
    std::ifstream inFile;
    std::ofstream outFile;
    std::string line;
    double firstOperand, secondOperand, result;
    char op;
    int lineNum = 1; //Current line
    std::vector<std::string> lineVector;

    //Open IO files
    inFile.open(inputFilePath);
    outFile.open(outputFilePath);

    //Check if input file is empty
    if (isEmpty(inFile))
    {
        outFile << FILE_EMPTY << std::endl;
        throw std::logic_error(FILE_EMPTY);
    }

    if (inFile.is_open()) {
        while(getline(inFile, line))
        {
            lineVector = lineToVector(line);
            //Check size of expression
            if (lineVector.size() != MAX_TOK)
            {
                outFile << "line " << lineNum << ": " << INVALID_EXPR <<
                std::endl;
                throw std::logic_error(INVALID_EXPR);
            }
            //Check length of op string
            if (lineVector[1].length() != 1)
            {
                outFile << "line " << lineNum << ": " << INVALID_OPERATOR <<
                        std::endl;
                throw std::invalid_argument(INVALID_OPERATOR);
            }
            op = lineVector[1][0];
            //Check op is valid
            if (!isValidOp(op))
            {
                outFile << "line " << lineNum << ": " << INVALID_OPERATOR <<
                        std::endl;
                throw std::invalid_argument(INVALID_OPERATOR);
            }
            //Assign values, complete calculation and write to file
            firstOperand = firstOperandSTOD(lineVector[0]);
            secondOperand = secondOperandSTOD(lineVector[2]);
            result = calc.Calc(firstOperand, secondOperand, op);
            outFile << result << std::endl;
        }
        lineNum++;
    }

    //Close IO files.
    inFile.close();
    outFile.close();
}


double CalculatorIO::calculateInteractive()
{
    std::string line;
    double firstOperand, secondOperand, result;
    char op;
    std::vector<std::string> lineVector;

    std::cout << "Enter expression using +, -, *, /: ";
    getline(std::cin, line);
    lineVector = lineToVector(line);

//    //Check size of expression
    if (lineVector.size() != MAX_TOK)
        throw std::logic_error("Error: invalid expression");
    //Check length of op string
    if (lineVector[1].length() != 1)
        throw std::invalid_argument(INVALID_OPERATOR);
    op = lineVector[1][0];
    //Check op is valid
    if (!isValidOp(op))
        throw std::invalid_argument(INVALID_OPERATOR);

    //Assign values, complete calculation and write to file
    firstOperand = firstOperandSTOD(lineVector[0]);
    secondOperand = secondOperandSTOD(lineVector[2]);
    result = calc.Calc(firstOperand, secondOperand, op);
    std::cout << result << std::endl;

    return result;
}

bool CalculatorIO::isValidOp(char c)
{
    switch(c)
    {
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '/':
            return true;
    }
    return false;
}

bool CalculatorIO::isEmpty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

std::vector<std::string> CalculatorIO::lineToVector(std::string line)
{
    int tokCount = 0; //Accumulator holds number of tokens in the string.
    std::string tok; //Holds the current token.
    std::vector <std::string> lineVector; //Holds all tokens from the string.
    std::stringstream sso(line);

    while(sso >> tok)
    {
        lineVector.push_back(tok);
        tokCount++;
    }
    return lineVector;
}

double CalculatorIO::firstOperandSTOD(std::string s)
{
    double newDouble;
    try
    {
        newDouble = std::stod(s);
    }
    catch(std::invalid_argument& err)
    {
        throw std::invalid_argument(INVALID_OP_FIRST);
    }
    return newDouble;
}

double CalculatorIO::secondOperandSTOD(std::string s)
{
    double newDouble;
    try
    {
        newDouble = std::stod(s);
    }
    catch(std::invalid_argument& err)
    {
        throw std::invalid_argument(INVALID_OP_SECOND);
    }
    return newDouble;
}







