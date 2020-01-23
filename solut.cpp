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
    for (const std::pair<std::string, Employee *> &element : employees)
    {
        delete element.second;
    }

    employees.clear ();
}

Employee *EmployeeRegister::findEmployee (const std::string &name)
{
    std::map<std::string, Employee *>::iterator it = employees.find(name);
    if (it != employees.end ())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

Employee **EmployeeRegister::exportEmployeesAsArray()
{
    if (employees.empty ())
        return nullptr;

    Employee ** result;
    result = new Employee *[employees.size ()];
    size_t counter = 0;
    for (const std::pair<std::string, Employee *> element : employees)
    {
        result[counter++] = element.second;
    }

//    for (std::map<std::string, Employee *>::iterator it = employees.begin(); it != employees.end (); ++it)
//    {
//        result[std::distance (employees.begin(), it)] = (*it).second;
//    }
    return result;
}

