#include <iostream>
using namespace std;

// Function declarations
void displayMenu();
void depositMoney(double &balance);
void withdrawMoney(double &balance);
void checkBalance(double balance);
void processChoice(int choice, double &balance);

int main() {
    double balance = 0.0;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        processChoice(choice, balance);
    } while (choice != 4);  // 4 = Exit

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\n--- Bank Account Menu ---\n";
    cout << "1. Deposit Money\n";
    cout << "2. Withdraw Money\n";
    cout << "3. Check Balance\n";
    cout << "4. Exit\n";
}

// Function to deposit money
void depositMoney(double &balance) {
    double amount;
    cout << "Enter amount to deposit: $";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid amount. Deposit failed.\n";
    }
}

// Function to withdraw money
void withdrawMoney(double &balance) {
    double amount;
    cout << "Enter amount to withdraw: $";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << balance << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds. Withdrawal failed.\n";
    } else {
        cout << "Invalid amount. Withdrawal failed.\n";
    }
}

// Function to check balance
void checkBalance(double balance) {
    cout << "Your current balance is: $" << balance << endl;
}

// Function to process the user's choice
void processChoice(int choice, double &balance) {
    switch (choice) {
        case 1:
            depositMoney(balance);
            break;
        case 2:
            withdrawMoney(balance);
            break;
        case 3:
            checkBalance(balance);
            break;
        case 4:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}
