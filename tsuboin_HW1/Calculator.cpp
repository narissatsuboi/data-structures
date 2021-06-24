
#include "Calculator.h"
#include <stdexcept>


double Calculator::Add(const double first, const double second)
{
    return first + second;
}

double Calculator::Subtract(const double first, const double second)
{
    return first - second;
}

double Calculator::Multiply(const double first, const double second)
{
    return first * second;
}

double Calculator::Divide(const double first, const double second)
{
    std::string exceptionString = "divide by zero error\n";
    if (second == 0.0)
        throw std::logic_error(exceptionString);
    return first / second;
}

double Calculator::Calc(const double first, const double second,
                        const char op)
{
    double result = 0.0;
    if (op == '+')
        result = Add(first, second);
    else if (op == '-')
        result = Subtract(first, second);
    else if (op == '*')
        result = Multiply(first, second);
    else if (op == '/')
        result = Divide(first, second);

    return result;
}