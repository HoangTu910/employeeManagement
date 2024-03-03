#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct Employee {
    char employeeID[8];
    char employeeName[20];
    char familyState;
    int childNumber;
    char socialState[2];
    int basicSalary;

    int legalDayOff;
    int illDayOff;
    int overtimeWork;
    char workResult[2];
    int realSalary;
};

struct ListEmployee{
    int size;
    int sizeSalary;
    Employee* listEmployee = nullptr;
    Employee* listSalary;
    Employee salaryPerMonth[120][120];
};

struct Menu{
    char Option;
    char configOption;
    char displayOption;
};

int getRealSalary(Employee& employee);
Employee initEmployee(Employee& Employee);
Employee initSalary(Employee& Employee);
void addListEmployee(ListEmployee& ListEmployee, Employee& employee);
void addListSalary(ListEmployee& ListEmployee, Employee& employee);
void showStat();
void showEmployee(Employee& employee);
void showSingleEmployee(Employee& employee);
void showListEmployee(ListEmployee& ListEmployee);
void showMenu(Menu& menu);
void addMultiData(Employee& employee, ListEmployee& list);
int findFromList(ListEmployee& list, char id[]);
void removeEmployeeFromList(Employee& employee, ListEmployee& list);
void showSingleSalary(Employee& employee);
void showListSalary(ListEmployee& ListEmployee);
void addMultiSalary(Employee& employee, ListEmployee& list);
void showConfigOption(Menu& menu);
void showDisplayOption(Menu& menu);
void showEmployeeInfo(ListEmployee& list);
void configEmployeeInfo(ListEmployee& list);
void configSalaryTabInfo(ListEmployee& list);
void updateDataFromList(Employee& currentData, Employee& updateData);