#include <iostream>

class BankAccount {
public:
    // Constructor with account number and balance
    BankAccount(int accountNumber, double balance) {
        m_accountNumber = accountNumber;
        m_balance = balance;
    }

    // Constructor that holds money (balance only)
    BankAccount(double balance) {
        m_accountNumber = 0;  // Default account number
        m_balance = balance;
    }

    // Default constructor
    BankAccount() {
        m_accountNumber = 0;
        m_balance = 0.0;
    }

    // Setter and getter methods
    void setAccountNumber(int accountNumber) {
        m_accountNumber = accountNumber;
    }

    int getAccountNumber() const {
        return m_accountNumber;
    }

    void setBalance(double balance) {
        m_balance = balance;
    }

    double getBalance() const {
        return m_balance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            m_balance += amount;
        }
    }

    // Method to withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && m_balance >= amount) {
            m_balance -= amount;
            return true;
        }
        return false;
    }

private:
    int m_accountNumber;
    double m_balance;
    // Removed m_money as it's redundant - balance already tracks the money
};