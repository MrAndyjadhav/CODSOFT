#include<iostream>
using namespace std;

int main() {
    char opn;
    float value1, value2;
    
    cout << "Welcome to Simple Calculator" << endl;
    cout << "-------------------------------" << endl;
    
    cout << "Enter Operator (+ - * /): ";
    cin >> opn;
    
    cout << "Enter first value: ";
    cin >> value1;
    
    cout << "Enter second value: ";
    cin >> value2;
    
    cout << "-------------------------------" << endl;
    
    switch(opn) {
        case '+':
            cout << "Addition: " << value1 + value2 << endl;
            break;
        case '-':
            cout << "Subtraction: " << value1 - value2 << endl;
            break;
        case '*':
            cout << "Multiplication: " << value1 * value2 << endl;
            break;
        case '/':
            if (value2 != 0)
                cout << "Division: " << value1 / value2 << endl;
            else
                cout << "Cannot divide by zero!" << endl;
            break;
        default:
            cout << "Invalid Operator" << endl;
    }

    return 0;
}
