#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    // Constructors
    Calculator(); // Default constructor

    // Destructor
    ~Calculator();

    // Member functions
    double performOperation(double num1, double num2, char op);
    double squareRoot(double num);
    double power(double base, double exponent);
    double naturalLog(double num);
    double base10Log(double num);

private:
    // Private member variables or functions, if needed
};

#endif

