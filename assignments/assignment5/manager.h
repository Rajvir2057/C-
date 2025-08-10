
#ifndef MANAGER_H
#define MANAGER_H
#include "salaryemployee.h"

//namespace listsavich {}
namespace employeessavitch {
class Manager : public SalariedEmployee {
    public:
        Manager( );

        void setSalary(double salary);
        double getSalary( );
        void setBonus(double bonus);
        double getBonus( );

        void printCheck( );
    private:
        double salary;
        double bonus;
};
} // namespace employeessavitch
#endif // MANAGER_H