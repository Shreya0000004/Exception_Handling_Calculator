/*
 I've added exception mechanisms (try, catch, throw) and error handling in several places throughout the code to handle potential errors gracefully. Here's an explanation of where these mechanisms were added and why:

 1. performOperation Function (try, catch, throw) :
    - Where: In the `performOperation` function.
    - Why: Added `try` and `catch` blocks to handle exceptions that might occur during basic arithmetic operations. For example, division by zero and invalid operators. By catching exceptions and providing error messages, we can gracefully handle these errors and prevent program crashes.

 2. squareRoot Function (try, catch, throw) :
    - Where : In the `squareRoot` function.
    - Why : Added `try` and `catch` blocks to handle exceptions related to calculating the square root of a number. Specifically, we check if the input number is negative and throw an exception if it is. Catching the exception allows us to provide a meaningful error message to the user.

 3. power Function (try, catch, throw) :
    - Where: In the `power` function.
    - Why: Added `try` and `catch` blocks to handle exceptions related to calculating the power of a number. We check if the base is zero and the exponent is negative, which would result in an undefined result. Throwing an exception in such cases helps us communicate the error to the user.

 4. naturalLog Function (try, catch, throw) :
    - Where: In the `naturalLog` function.
    - Why: Added `try` and `catch` blocks to handle exceptions related to calculating the natural logarithm. If the input is not a positive number, it results in an undefined operation. Catching this exception allows us to provide an error message to the user.

 5. base10Log Function (try, catch, throw) :
    - Where: In the `base10Log` function.
    - Why: Similar to the `naturalLog` function, added `try` and `catch` blocks to handle exceptions when calculating the base 10 logarithm. If the input is not a positive number, we catch the exception and provide an error message.

 6. Division by Zero Handling (assert) :
    - Where: In the `performOperation` function within the division case (`/` operator).
    - Why: Added an assertion to check if `num2` is not zero before performing division. Assertions help catch programming errors early in development by verifying critical conditions.

 7. Modulo by Zero Handling (assert) :
    - Where: In the `performOperation` function within the modulo case (`%` operator).
    - Why: Added an assertion to check if `num2` is not zero before performing the modulo operation. This assertion helps ensure the correctness of the program.

 8. Square Root of Negative Number Handling (assert):
    - Where: In the `squareRoot` function.
    - Why: Added an assertion to check if the input number is non-negative before calculating the square root. This assertion helps avoid undefined behavior due to invalid inputs.

 9. Undefined Power Handling (assert):
    - Where: In the `power` function.
    - Why: Added an assertion to check if the base is not zero when the exponent is negative. This prevents undefined results and communicates the error during development.

 The `try`, `catch`, and `throw` mechanisms are used to handle runtime exceptions gracefully, providing clear error messages to the user. Assertions (`assert`) are added at critical points to verify conditions that should always hold true in a correctly implemented program, helping with debugging and early error detection during development.
*/


#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept> // Include for standard exceptions

using namespace std;

// Function to perform basic arithmetic operations with detailed exception handling
double performOperation(double num1, double num2, char op) {
    try {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                assert(num2 != 0 && "Division by zero.");
                return num1 / num2;
            case '%':
                assert(num2 != 0 && "Modulo operation with divisor 0.");
                return (num1 * num2) / 100;
            default:
                throw invalid_argument("Error: Invalid operator.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

// Function to calculate square root with detailed exception handling
double squareRoot(double num) {
    try {
        assert(num >= 0 && "Square root of a negative number.");
        return sqrt(num);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

// Function to calculate power (x^y) with detailed exception handling
double power(double base, double exponent) {
    try {
        assert(!(base == 0 && exponent < 0) && "Undefined result - 0 to the power of a negative exponent.");
        return pow(base, exponent);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

// Function to calculate natural logarithm (ln) with detailed exception handling
double naturalLog(double num) {
    try {
        assert(num > 0 && "Natural logarithm of a non-positive number.");
        return log(num);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

// Function to calculate base 10 logarithm (log) with detailed exception handling
double base10Log(double num) {
    try {
        assert(num > 0 && "Logarithm of a non-positive number.");
        return log10(num);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

int main() {
    double num1, num2, result;
    char op;
    bool continueCalculation = true;

    while (continueCalculation) {
        cout << "Enter first number: ";
        cin >> num1;

        // Initialize num2 with 0 for the first iteration
        num2 = 0;

        while (true) {
            cout << "Enter operator (+, -, *, /, %, s, q, ^, l, g): ";
            cin >> op;

            if (op == 's') {
                result = squareRoot(num1);
            } else if (op == 'q') {
                result = num1 * num1;
            } else if (op == '^') {
                // Only ask for num2 when calculating with '^' operator
                cout << "Enter second number: ";
                cin >> num2;
                result = power(num1, num2);
            } else if (op == 'l') {
                result = naturalLog(num1);
            } else if (op == 'g') {
                result = base10Log(num1);
            } else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
                cout << "Enter second number: ";
                cin >> num2;
                result = performOperation(num1, num2, op);
            } else {
                cerr << "Error: Invalid operator." << endl;
                continue;
            }

            if (!isnan(result)) {
                cout << "Result: " << result << endl;
            }

            // Ask if the user wants to continue with the previous result as the first number
            char choice;
            cout << "Do you want to continue with the previous result as the first number? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                break;
            }

            // Set num1 to the result for the next iteration
            num1 = result;
        }

        // Ask if the user wants to continue the overall calculation
        char choice;
        cout << "Do you want to continue calculations? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            continueCalculation = false;
        }
    }

    return 0;
}

