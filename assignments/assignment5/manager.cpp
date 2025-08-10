// This is the file manager.cpp
// This is the implementation for the class Manager.
// The interface for the class Manager is in the header file manager.h.

#include <iostream>
#include <string>
#include "manager.h"

using namespace std;
namespace employeessavitch {

// Default constructor
Manager::Manager() : SalariedEmployee(), salary(0), bonus(0) 
{
    // deliberately empty
}

// Set salary (overrides SalariedEmployee's setSalary if needed)
void Manager::setSalary(double newSalary) 
{
    salary = newSalary;
}

// Get salary
double Manager::getSalary() 
{
    return salary;
}

// Set bonus
void Manager::setBonus(double newBonus) 
{
    bonus = newBonus;
}

// Get bonus
double Manager::getBonus() 
{
    return bonus;
}

// Print check (redefined from SalariedEmployee)
void Manager::printCheck() 
{
    setNetPay(salary + bonus);  // Assuming setNetPay is inherited from Employee
    cout << "\n______\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "______\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << getSSN() << endl;
    cout << "Manager. Base Pay: " << salary << endl;
    cout << "Bonus: " << bonus << endl;
    cout << "______\n";
}

} // namespace employeessavitch