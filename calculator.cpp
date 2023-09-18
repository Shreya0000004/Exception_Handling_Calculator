#include "calculator.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

// Default constructor
Calculator::Calculator() {
    // Initialize any member variables, if needed
}

// Destructor
Calculator::~Calculator() {
    // Clean up any resources, if needed
}

double Calculator::performOperation(double num1, double num2, char op) {
    double result = NAN; // Initialize result with NaN (error value)
    
    try {
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                assert(num2 != 0 && "Division by zero.");
                result = num1 / num2;
                break;
            case '%':
                assert(num2 != 0 && "Modulo operation with divisor 0.");
                result = (num1 * num2) / 100;
                break;
            default:
                throw invalid_argument("Error: Invalid operator.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return result;
}

double Calculator::squareRoot(double num) {
    double result = NAN; // Initialize result with NaN (error value)

    try {
        if (num >= 0) {
            result = sqrt(num);
        } else {
            throw invalid_argument("Error: Square root of a negative number.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return result;
}

double Calculator::power(double base, double exponent) {
    double result = NAN; // Initialize result with NaN (error value)

    try {
        if (!(base == 0 && exponent < 0)) {
            result = pow(base, exponent);
        } else {
            throw invalid_argument("Error: Undefined result - 0 to the power of a negative exponent.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return result;
}

double Calculator::naturalLog(double num) {
    double result = NAN; // Initialize result with NaN (error value)

    try {
        if (num > 0) {
            result = log(num);
        } else {
            throw invalid_argument("Error: Natural logarithm of a non-positive number.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return result;
}

double Calculator::base10Log(double num) {
    double result = NAN; // Initialize result with NaN (error value)

    try {
        if (num > 0) {
            result = log10(num);
        } else {
            throw invalid_argument("Error: Logarithm of a non-positive number.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return result;
}

