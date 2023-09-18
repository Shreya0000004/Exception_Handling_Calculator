#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    Calculator calculator;
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
                result = calculator.squareRoot(num1);
            } else if (op == 'q') {
                result = num1 * num1;
            } else if (op == '^') {
                // Only ask for num2 when calculating with '^' operator
                cout << "Enter second number: ";
                cin >> num2;
                result = calculator.power(num1, num2);
            } else if (op == 'l') {
                result = calculator.naturalLog(num1);
            } else if (op == 'g') {
                result = calculator.base10Log(num1);
            } else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
                cout << "Enter second number: ";
                cin >> num2;
                result = calculator.performOperation(num1, num2, op);
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

