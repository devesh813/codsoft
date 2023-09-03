#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char op;

    // Input the two numbers and the operator
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;


    // Perform the calculation based on the operator
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
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1;
            }
            break;
        default:
            cout << "Error: Invalid operator." << endl;
            return 1;
    }

    // Display the result
    cout <<"Result: "<< num1<<op<<num2<<" = "<< result << endl;

    return 0;
}
