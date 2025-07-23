#include <iostream>
#include <string>
#include <utility>


class Employee {
    public:
    Employee(std :: string id, int id_num=0) : m_id(id), m_id_num(id_num) {
        //this is the constructor.
    }

    void set_employee_id(std :: string id,int id_num){
        m_id = id;
        m_id_num = id_num;
    }

    std::pair<std :: string,int> get_employee_id() const {
        return {m_id,m_id_num};
    }


    protected:
    std :: string m_id;
    int m_id_num;
};
//inheritance
class Manager : public Employee{
    public:
    Manager(std :: string id, int id_num=0,float salary=0) : Employee(id, id_num){
        M_salary = salary;
    }


    void set_pay(float salary){
        M_salary = salary;
    }
    float get_pay()const{
        return M_salary;
    }
    private:
    float M_salary;
};
    

int main() {
    Employee dave("CA");
    std :: cout << "Dave "<< dave.get_employee_id().first << dave.get_employee_id().second << '\n';

    dave.set_employee_id("CA",5678);

    std :: cout << "Dave has changed his ID.\n";

    std :: cout << "Dave "<< dave.get_employee_id().first << dave.get_employee_id().second << '\n';

    Manager violet("CB",2345,20000);
    std :: cout << "Manager Violet : "<< violet.get_employee_id().first<< violet.get_employee_id().second <<" gets cad "<< violet.get_pay();


    return 0;
}