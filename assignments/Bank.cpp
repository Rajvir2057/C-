#include <iostream>

class BankAccount{

    private:
    // declaring...
    struct details{ 
    int m_accountNumber;
    double m_balance;
    };

    details bank_info; // creating an instance. to store data to be used everywhere.

    public:

    //constructor with account number and balance..
    BankAccount(int accountNumber, double balance){

       bank_info.m_accountNumber = accountNumber;
       bank_info.m_balance = balance; 

    }

    // contructor that holds money..
    BankAccount(double balance){
       bank_info.m_balance = balance; 
    }

    // default constructor..
    BankAccount(){
        bank_info.m_accountNumber = 0;
        bank_info.m_balance = 0.0;
    }

    // get and set methods..
    void setAccountNumber(int accountNumber) {
        bank_info.m_accountNumber = accountNumber;
    }

    int getAccountNumber() const {
        return bank_info.m_accountNumber;
    }

    void setBalance(double balance) {
        bank_info.m_balance = balance;
    }

    double getBalance() const {
        return bank_info.m_balance;
    }
    
    //creating methods..
    void deposit(double amount){
        if(amount > 0){
            bank_info.m_balance = bank_info.m_balance + amount;
        }
    }

    bool withdraw(double amount){
        if(amount > 0 &&  bank_info.m_balance > amount){
            bank_info.m_balance = bank_info.m_balance - amount;
            return true;
        }
        return false;
    }

    //forming a friend fuction to move money from one bank - second bank.
    friend void transferfunds(BankAccount& get , BankAccount& give, double amount);

    //overloading methods.
// + operator to add amount
BankAccount operator+(double amount) {
    BankAccount temp = *this;
    temp.bank_info.m_balance += amount;
    return temp;
}

// - operator to subtract amount
BankAccount operator-(double amount) {
    BankAccount temp = *this;
    if (temp.bank_info.m_balance >= amount) {
        temp.bank_info.m_balance -= amount;
    }
    return temp;
}

// == and != to compare balances
bool operator==(const BankAccount& other) const {
    return bank_info.m_balance == other.bank_info.m_balance;
}

bool operator!=(const BankAccount& other) const {
    return bank_info.m_balance != other.bank_info.m_balance;
}

// << for output
friend std::ostream& operator<<(std::ostream& out, const BankAccount& acc) {
    out << "Account Number: " << acc.bank_info.m_accountNumber
        << ", Balance: $" << acc.bank_info.m_balance;
    return out;
}

// >> for input
friend std::istream& operator>>(std::istream& in, BankAccount& acc) {
    in >> acc.bank_info.m_accountNumber >> acc.bank_info.m_balance;
    return in;
}


};

// using method outside..
void transferfunds(BankAccount& get, BankAccount& give, double amount){
    if(get.bank_info.m_balance >= amount){
        get.bank_info.m_balance = get.bank_info.m_balance - amount;
        give.bank_info.m_balance = give.bank_info.m_balance + amount;
    }
}

//creating objects.

int main() {
    BankAccount Bankaccount1(1111, 1000.0);
    BankAccount Bankaccount2(2222, 500.0);

    // Deposit and Withdraw
    Bankaccount1.deposit(200);
    Bankaccount2.withdraw(100);

    // Display accounts using overloaded <<
    std::cout << "Account 1: " << Bankaccount1 << std::endl;
    std::cout << "Account 2: " << Bankaccount2 << std::endl;

    // Test operator+ and operator-
    BankAccount result1 = Bankaccount1 + 300.0;
    BankAccount result2 = Bankaccount2 - 200.0;

    std::cout << "After +300 to Account 1: " << result1 << std::endl;
    std::cout << "After -200 from Account 2: " << result2 << std::endl;

    // Compare balances
    if (Bankaccount1 == Bankaccount2) {
        std::cout << "Accounts have equal balance.\n";
    } else {
        std::cout << "Accounts have different balances.\n";
    }

    // Transfer funds
    std::cout << "\nTransferring $250 from Account 1 to Account 2...\n";
    transferfunds(Bankaccount1, Bankaccount2, 250.0);

    std::cout << "Account 1: " << Bankaccount1 << std::endl;
    std::cout << "Account 2: " << Bankaccount2 << std::endl;

    return 0;
}

