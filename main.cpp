#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <limits.h>
#include <list>
#include "functions.cpp"
#include "EmployeeData.h"

/* Сортировка данных указанного объёма указанным методом */
void operation(int amount, unsigned int (*func)(std::string)){
	EmployeeData* ED = new EmployeeData[amount];
	std::string s, data[4];
	std::string sno, position, department;
	int pos;
	std::list<std::string> EDlist;
	std::ifstream fin("ListLab.txt");
	if (!fin) {std::cout << "No data.\n"; return;}
	for (int counter = 0; counter < amount; ++counter){
        std::getline(fin, s); /* Получение данных из файла ListLab.txt */
    	std::istringstream iss(s);
    	for (int i = 0; i < 4; ++i) std::getline(iss, data[i], ';');
    	ED[counter].SetData(data[0], data[1], data[2], atoi(data[3].c_str()), func(data[0]));
    	//std::cout<<ED[counter].GetHash()<<'\n';
    }
    fin.close();
    Hash HashTable(2000000);
    for (int counter = 0; counter < amount; ++counter)
    	HashTable.insertItem(ED[counter], func);
    //for (int counter = 0; counter < amount; ++counter) std::cout<<ED[counter].GetSNO()<<'\n';

    unsigned int hash_f[10] = {ED[amount/2 + 7].GetHash(), ED[amount/6 + 4].GetHash(), 
    ED[amount*5/7 - 2].GetHash(), ED[amount*8/11 + 3].GetHash(), ED[amount*3/5].GetHash(),
    ED[amount/2 + 6].GetHash(), ED[amount/6 + 3].GetHash(), 
    ED[amount*5/7 - 1].GetHash(), ED[amount*8/11 + 2].GetHash(), ED[amount*4/5].GetHash()};
    auto beg = std::chrono::high_resolution_clock::now(); /* Начало замера врмени */
    float collisions = 0;
    for (int i = 0; i < 10; ++i)
    	EDlist = HashTable.FindValues(hash_f[i]); /* Вызов указанного метода сортировки для указанных данных */
    auto end = std::chrono::high_resolution_clock::now();
    /*for (auto x : EDlist)
    	std::cout << x << " | ";
    	std::cout << '\n';*/
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-beg);
    for (int i = 0; i < 10; ++i)
    	collisions += HashTable.count(hash_f[i]);
    std::cout << duration.count() << " ns; collisions: " << collisions/10 << '\n';
    delete[] ED;
    //std::cout << ED[pos].GetSNO() << '_' << ED[pos].GetSalary() << '\n';
}	/* Вывод засечённого времени в миллисекундах */

int main(int argc, char* argv[])
{	/* Вызовы функций сортировок для объёмов 10000, 20000 ... 100000 */
	for (int i = 1; i < 11; ++i){
		std::cout<<i*10000<<" elements;\nSimple hash: ";
		operation(i*10000, MySimpleHash);
		std::cout<<"Better hash: ";
		operation(i*10000, BetterHash);
	}
    return 0;
}