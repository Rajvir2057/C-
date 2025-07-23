#include <iostream>

class BankAccount{

    public:

    //constructor with account number and balance..
    BankAccount(int accountNumber=0, double balance){

       m_accountNumber = accountNumber;
       m_balance = balance; 

    }

    // contructor that holds money..
    BankAccount(double balance){
       m_balance = balance; 
    }

    // default constructor..
    BankAccount();

    // get and set methods..
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
    
    //creating methods..
    void deposit(double amount){
        if(amount > 0){
            m_balance = m_balance + amount;
        }
    }

    bool withdraw(double amount){
        if(amount > 0 &&  m_balance > amount){
            m_balance = m_balance - amount;
            return true;
        }
        return false;
    }
    private:
    // declaring...
    int m_accountNumber;
    double m_balance;

};