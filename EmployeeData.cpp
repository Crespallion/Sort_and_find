#include "EmployeeData.h"
#include <string>
#include <list>
#include <iostream>

/* Установить значения объекту */
void EmployeeData::SetData(std::string sno,
    std::string position,
    std::string department,
    int salary, unsigned int hash)
{
    SNO = sno;
    Position = position;
    Department = department;
    Salary = salary;
    Hash = hash;
}

/* Получить значения объекта */
std::string EmployeeData::GetDepartment()
{
    return Department;
}

std::string EmployeeData::GetSNO()
{
    return SNO;
}

int EmployeeData::GetSalary()
{
    return Salary;
}

unsigned int EmployeeData::GetHash()
{
    return Hash;
}

/* Перегрузка операторов сравнения */
bool operator > (const EmployeeData &e1, const EmployeeData &e2)
{
return e1.SNO > e2.SNO;
}
/*{
	if (e1.Department == e2.Department){
		if (e1.SNO == e2.SNO){
			return e1.Salary > e2.Salary;
		}
		else return e1.SNO > e2.SNO;
	}
    else return e1.Department > e2.Department;
}*/

bool operator <= (const EmployeeData &e1, const EmployeeData &e2)
{
	return !(e1 > e2);
}

bool operator < (const EmployeeData &e1, const EmployeeData &e2)
{
return e1.SNO < e2.SNO;
}
/*{
	if (e1.Department == e2.Department){
		if (e1.SNO == e2.SNO){
			return e1.Salary < e2.Salary;
		}
		else return e1.SNO < e2.SNO;
	}
    else return e1.Department < e2.Department;
}*/

bool operator >= (const EmployeeData &e1, const EmployeeData &e2)
{
	return !(e1 < e2);
}


Hash::Hash(int V)
{
    this->BUCKET = V;
    table = new std::list<std::string>[BUCKET];
}
  
void Hash::insertItem(EmployeeData ED, unsigned int (*func)(std::string))
{
    int index = func(ED.GetSNO());
    for (auto x : table[index])
    	if (x == ED.GetSNO())
    		return;
	table[index].push_back(ED.GetSNO()); 
}
  
void Hash::deleteItem(EmployeeData ED, unsigned int (*func)(std::string))
{
  int index = func(ED.GetSNO());
  std::list <std::string> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == ED.GetSNO())
      break;
  }
  if (i != table[index].end())
    table[index].erase(i);
}

unsigned int Hash::MySimpleHash(std::string str)
{
    unsigned int hash = 0;
 	int* ascii_str = new int[str.length()];
	for (int i = 0; i < str.length(); ++i){
		ascii_str[i] = str[i];
		hash += ascii_str[i];
	}
	return hash % 2000000;
}

unsigned int Hash::BetterHash(std::string s_str)
{
    unsigned int b = 498791;
	unsigned int a = 83117;
	unsigned int hash = 0;
	unsigned int i = 0, len = s_str.length();
	const char *str = s_str.c_str();
	for (i = 0; i < len; str++, i++) {
		hash = hash * a + (unsigned char)(*str);
		a = a * b;
	}
	return hash % 2000000;
}

std::list <std::string> Hash::FindValues(unsigned int hash_val) {
    return table[hash_val];
}

int Hash::count(unsigned int hash_val) {
	int c = 0;
	for (auto x : table[hash_val])
    	++c;
    return c;
}