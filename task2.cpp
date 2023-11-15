#include<iostream>
using namespace std;

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers, with error handling for division by zero
double divide(double num1, double num2) {
    if (num2 == 0) {
        cout << "Division by 0 is not possible!";
        return 0;
    } else {
        return num1 / num2;
    }
}

int main() {
    double num1, num2;
    int choice;

    cout << "Welcome to Calculator!";
    cout << "\nEnter first number: ";
    cin >> num1;
    cout << "\nEnter second number: ";
    cin >> num2;

    do {
        cout << "\nEnter operation: 1-Addition 2-Subtraction 3-Multiplication 4-Division 5-Enter numbers again 6-exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Result of addition is: " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result of subtraction is: " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result of multiplication is: " << multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result of division is: " << divide(num1, num2) << endl;
                break;
            case 5:
                cout << "\nEnter first number: ";
                cin >> num1;
                cout << "\nEnter second number: ";
                cin >> num2;
                break;
            case 6:
                cout << "Exiting the calculator. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
