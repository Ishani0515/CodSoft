#include <iostream>

using namespace std;

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        cout << "Welcome To Console Calculator!" << endl;
        cout << "Choose an Operation: " << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your Choice: " << endl;

        cin >> choice;

        if (choice == 5) {
            cout << "Exiting Calculator. Goodbye!" << endl;
            break;
        }

        cout << "Enter the first number: ";
        cin >> num1;

        cout << "Enter the second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = num1 + num2;
                break;
            case 2:
                result = num1 - num2;
                break;
            case 3:
                result = num1 * num2;
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Cannot divide by zero!" << endl;
                    continue;
                }
                break;
            default:
                cout << "Error: Invalid choice! Please choose again." << endl;
                continue;
        }

        cout << "Result: " << result << endl << endl;
    }

    return 0;
}
