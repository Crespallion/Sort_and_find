main: main.o EmployeeData.o
	g++ main.o EmployeeData.o -o main
main.o: main.cpp EmployeeData.h
	g++ -std=c++11 -c main.cpp -o main.o
EmployeeData.o: EmployeeData.h EmployeeData.cpp
	g++ -std=c++11 -c EmployeeData.cpp -o EmployeeData.o
dich: main
	./main