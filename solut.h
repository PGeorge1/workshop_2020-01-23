#include <iostream>
#include <vector>
#include <map>

struct Employee
{
    Employee (const std::string &name,
              int age,
              const std::vector<double> &wages) :
        name (name), age (age), wages (wages)
    {
    }

    std::string name;
    int age;
    std::vector<double> wages;
};

class EmployeeRegister
{
    std::map<std::string, Employee *> employees;
public:
    Employee *create_new_employee (const std::string &name,
                                   int age,
                                   const std::vector<double> &wages);
    void freeAll ();
};
