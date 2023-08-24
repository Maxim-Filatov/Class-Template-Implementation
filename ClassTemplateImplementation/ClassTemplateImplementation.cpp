/* Menu and the entry point to the program.
   Press 1 to calculate the total purchase sum or the amount of goods of a certain manufacturer (1 - sum, 2 - amount of goods)
   Press 2 to quit the program */

#include <iostream>
#include "Product.h"

using namespace std;

// Objects for calculating sum;
Product<float> product1(100);
Product<float> product2(200);
Product<float> product3(300);

// Objects for counting the amount of goods
Product<int> product4(1);
Product<int> product5(1);
Product<int> product6(2);

// Checks if the value entered by the user is appropriate
void validateInput() {
    int ignoreValue = 1024;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(ignoreValue, '\n');
    }
}

// Assign values to private data member of objects
void assignValues() {
    product1.setPresence(true);
    product2.setPresence(false);
    product3.setPresence(true);
    product4.setPresence(false);
    product5.setPresence(true);
    product6.setPresence(true);
    product4.setId(1);
    product5.setId(1);
    product6.setId(2);
}

// Calculate the total purchase sum
float calculateSum() {
    return product1.getRequestedValue() + product3.getRequestedValue();
}

// Count the amount of goods of a certain manufacturer
void countQuantity(int id) {
    if (id == 1) {
       cout << "Manufacturer_" << id << " has " << product5.getRequestedValue() << " product(s)" << endl;
    }
    else if (id == 2) {
        cout << "Manufacturer_" << id << " has " << product6.getRequestedValue() << " product(s)" << endl;
    }
}

int main() {
    // Boolean variable to check if the user wants to quit the program or is continuing interaction with it
    bool loop = true;
    // Boolean variable to check if the user wants to calculate the purchase sum or to count the amount of goods
    bool innerLoop;
    // This is a variable to call functions or terminate the program. Variable's value is modified by the user in a loop
    int input;
    int innerInput;
    cout << "What do you want to do? Enter a number (1 or 2): ";
    while (loop) {
        innerLoop = true;
        cin >> input;
        validateInput();
        switch (input) {
            // Calculate the total purchase sum or the amount of goods of a certain manufacturer
            case 1:
                while (innerLoop) {
                    cout << "Enter 1 to calculate the total purchase sum or enter 2 to count the amount of goods of a certain manufacturer: ";
                    cin >> innerInput;
                    validateInput();
                    switch (innerInput) {
                        // Calculate sum
                        case 1:
                            cout << "Purchase sum: " << calculateSum() << endl;
                            innerLoop = false;
                        break;
                        // Count quantity
                        case 2:
                            cout << "Amount of goods:" << endl;
                            countQuantity(1);
                            countQuantity(2);
                            innerLoop = false;
                        break;
                        default:
                            cout << "Invalid input." << endl;
                        break;
                    }
                }
                cout << "What do you want to do next? Enter a number (1 or 2): ";
            break;
            // Exit the program
            case 2:
                loop = false;
            break;
            default:
                cout << "Invalid input. Enter only 1 or 2: ";
            break;
        }
    }
}
