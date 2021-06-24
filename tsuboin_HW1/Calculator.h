#ifndef HW1_CALCULATOR_H
#define HW1_CALCULATOR_H

#include <string>

/**
 * Contains the basic methods for calculating an expression of two operands and
 * +, -, *, or /.
 *
 * @author Narissa  Tsuboi
 * @version 1.0
 */
class Calculator {
public:
    /**
     * Adds two numbers and returns the result.
     *
     * @param first operand
     * @param second operand
     * @return result
     */
    double Add(const double first, const double second);

    /**
     * Subtracts two numbers and returns the result.
     *
     * @param first operand
     * @param second operand
     * @return result
     */
    double Subtract(const double first, const double second);

    /**
     * Multiplies the number and returns the result.
     *
     * @param first operand
     * @param second operand
     * @return result
     */
    double Multiply(const double first, const double second);

    /**
     * Divides two numbers and returns the result.
     *
     * @param first operand
     * @param second operand
     * @return result
     */
    double Divide(const double first, const double second);

    /**
     * Runs the given calculation and returns the result.
     * @param first operand
     * @param second operand
     * @param operator
     * @return result
     */
    double Calc(const double first, const double second, const char op);
};


#endif //HW1_CALCULATOR_H
