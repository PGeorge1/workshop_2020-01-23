#include "solut.h"

Employee *EmployeeRegister::create_new_employee (
                               const std::string &name,
                               int age,
                               const std::vector<double> &wages)
{
    Employee *ptr = new Employee (name, age, wages);
    employees[name] = ptr;
    return ptr;
}

void EmployeeRegister::freeAll ()
{
    for (const std::pair<std::string, Employee *> element : employees)
    {
        delete element.second;
    }

    employees.clear ();
}
