#include <string>
#include <iostream>
#include "hourlyemployee.h"
using namespace std;
namespace employeessavitch {

  HourlyEmployee::HourlyEmployee( ) : Employee( ), wageRate(0), hours(0)
  {
    //deliberately empty
  }
  HourlyEmployee::HourlyEmployee(string theName, string theNumber,
                                 double theWageRate, double theHours)
    : Employee(theName, theNumber), wageRate(theWageRate), hours(theHours)
  {
    //deliberately empty
  }
  void HourlyEmployee::setRate(double newWageRate)
  {
    wageRate = newWageRate;
  }

  double HourlyEmployee::getRate( ) const
  {
    return wageRate;
  }

  void HourlyEmployee::setHours(double hoursWorked)
  {
    hours = hoursWorked;
  }

  double HourlyEmployee::getHours( ) const
  {
    return hours;
  }


void HourlyEmployee::printCheck( )
{
  setNetPay (hours * wageRate);
  cout << "\n_____________________________________________\n";
  cout << "Pay to the order of " << getName( ) << endl;
  cout << "The sum of " << getNetPay( ) << " Dollars\n";
  cout << "\n_____________________________________________\n";
  cout << "Check Stub: NOT NEGOTIABLE\n";
  cout << "Employee Number: " << getSSN() << endl;
  cout << "Hourly Employyee. \nHours Worked: " << hours
    << " Rate: " << wageRate << " Pay: " << getNetPay( ) << endl;
  cout << "\n_____________________________________________\n";
}

} // employeessavitch 
