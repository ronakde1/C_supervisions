#include <iostream>
using namespace std;
class Employee{
    private:
    int hours;
    int salary;
    public:
    Employee(int hours_val, int salary_val): hours(hours_val), salary(salary_val){}
    virtual int wage(){
        return hours * salary;
    }
};
class Manager: public Employee{
    private:
    int bonus;
    public:
    Manager(int hours_val, int salary_val, int bonus_val): 
    Employee(hours_val,salary_val), bonus(bonus_val){}
    int wage(){return (Employee::wage() + bonus);}
};

int main(){
    Employee* man =new  Manager(1,2,3);
    cout << man->wage();
    return 0;
}