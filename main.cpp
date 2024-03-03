#include "System.h"
#include <conio.h>

void waitUser();


int main(){
    Employee employee;
    ListEmployee list;
    Menu menu;
    while(menu.Option != 'o'){
        showMenu(menu);
        switch(menu.Option){
            case '1':
                showConfigOption(menu);
                if(menu.configOption == '1') addMultiData(employee, list);
                else if(menu.configOption == '2') addMultiSalary(employee, list);
                else if(menu.configOption == '3') configEmployeeInfo(list);
                else if(menu.configOption == '4') configSalaryTabInfo(list);
                waitUser();
                break;
            case '2':
                showDisplayOption(menu);
                if(menu.displayOption =='1') showListEmployee(list);
                else if(menu.displayOption == '2') showListSalary(list);
                waitUser();
                break;
            case '3':
                showEmployeeInfo(list);
                waitUser();
                break;
            case '4':
                removeEmployeeFromList(employee, list);
                waitUser();
                break;
            case 'r':
                break;
        }
        system("cls");
    }
    
    
    // for(int i = 0; i < 2; i++){
    //     employee = initEmployee(employee);
    //     addListEmployee(list, employee);
    // }
    // showListEmployee(list);
    // delete[] list.listEmployee;

    
    
    // removeEmployeeFromList(employee, list);
    // showListEmployee(list);
}

void waitUser(){
    cout << "Nhan 'r' de tro lai MENU !";
    char keyPressed;
    do {
        if (_kbhit()) {
            keyPressed = _getch();
            if (keyPressed == 'r' || keyPressed == 'R') {
                break; 
            }
        }
    } while (true);
}