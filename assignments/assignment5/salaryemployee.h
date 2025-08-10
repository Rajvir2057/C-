
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;
namespace employeessavitch
{
class SalariedEmployee : public Employee
{
  public:
    SalariedEmployee();
    SalariedEmployee(string theName, string theSSN,
                           double theWeeklySalary);

    double getSalary( ) const;
    void setSalary(double newSalary);

    void printCheck( );
  private:
    double salary;//weekly
};
} //employeesavitch

#endif // SALARIEDEMPLOYEE_H
