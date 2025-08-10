#include <iostream>
#include "hourlyemployee.h"
#include "salaryemployee.h"
#include "manager.h"
using std::cout;
using std::endl;
using namespace employeessavitch;  // Fixed namespace (original had typos: "employeesawitch")

int main()
{
    HourlyEmployee joe;
    joe.setName("Mighty Joe");
    joe.setSSN("123-45-6789");
    joe.setRate(20.50);
    joe.setHours(40);

    cout << "Check for " << joe.getName()
         << " for " << joe.getHours() << " hours.\n";
    joe.printCheck();
    cout << endl;

    SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
    cout << "Check for " << boss.getName() << endl;
    boss.printCheck();

    Manager rajvir;
    rajvir.setName("Rajvir Kaur");
    rajvir.setSSN("222-33-4444");
    rajvir.setSalary(8000.00);   // Base salary
    rajvir.setBonus(1500.00);    // Bonus

    cout << "\nCheck for " << rajvir.getName() << endl;
    rajvir.printCheck();

    return 0;  // Added for completeness (though not strictly necessary in C++)
}