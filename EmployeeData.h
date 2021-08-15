#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H
#include <string>
#include <list>

/* Интерфейс класса EmployeeData */
class EmployeeData
{
    std::string SNO; /* ФИО сотрудника */
    std::string Position; /* должность */
    std::string Department; /* подразделение */
    int Salary; /* зарплата */
    unsigned int Hash;

    public:
    void SetData(std::string sno,
    std::string position,
    std::string department,
    int salary, unsigned int hash); 
    std::string GetDepartment();
    std::string GetSNO();
    int GetSalary();
    unsigned int GetHash();

	friend bool operator> (const EmployeeData &e1, const EmployeeData &e2);
	friend bool operator<= (const EmployeeData &e1, const EmployeeData &e2);
	friend bool operator< (const EmployeeData &e1, const EmployeeData &e2);
	friend bool operator>= (const EmployeeData &e1, const EmployeeData &e2);
};

class Hash
{
    int BUCKET; 
    std::list<std::string> *table;
public:
    Hash(int V);
    void insertItem(EmployeeData x, unsigned int (*func)(std::string));
    void deleteItem(EmployeeData x, unsigned int (*func)(std::string));
    unsigned int MySimpleHash(std::string str);
    unsigned int BetterHash(std::string s_str);
    std::list <std::string> FindValues(unsigned int hash_val);
    int count(unsigned int hash_val);
};

#endif