#include "System.h"


int getRealSalary(Employee& employee){
    int bonus = 1;
    int totalSalary = 0;

    int overtimeSalary = 4/100 * employee.basicSalary;
    int fineSalary = 5/100 * employee.basicSalary;

    if(employee.childNumber > 2){
        bonus = bonus + 5/100;
    }
    if(strcmp(employee.socialState, "CH") == 0){
        bonus = bonus + 10/100;
    }
    
    totalSalary = employee.basicSalary * bonus + overtimeSalary * employee.overtimeWork - fineSalary * employee.illDayOff;
    return totalSalary;    
}


Employee initEmployee(Employee& Employee){
    cout << "Ma so nhan vien: ";
    (cin>>ws).getline(Employee.employeeID, sizeof(Employee.employeeID)+1); 
    cout << "Ten nhan vien: ";
    (cin>>ws).getline(Employee.employeeName, sizeof(Employee.employeeName)+1); 
    cout << "Tinh trang gia dinh: ";
    cin >> Employee.familyState;
    cout << "So con: ";
    cin >> Employee.childNumber;
    cout << "Trinh do van hoa: ";
    // cin.ignore();
    (cin>>ws).getline(Employee.socialState, sizeof(Employee.socialState)+1);
    cout << "Luong can ban: ";
    cin >> Employee.basicSalary;

    return Employee;
}


Employee initSalary(Employee& Employee){
    cout << "So ngay nghi co phep: ";
    cin >> Employee.legalDayOff;
    cout << "So ngay nghi khong phep: ";
    cin >> Employee.illDayOff;
    cout << "So ngay lam them: ";
    cin >> Employee.overtimeWork;
    cout << "Ket qua lam viec: ";
    (cin>>ws).getline(Employee.workResult, sizeof(Employee.workResult)+1);
    Employee.realSalary = getRealSalary(Employee);
    return Employee;
}


void addListEmployee(ListEmployee& ListEmployee, Employee& employee){
    Employee* tempList = new Employee[ListEmployee.size+1]; 
    
    for(int i = 0; i < ListEmployee.size; i++){
        tempList[i] = ListEmployee.listEmployee[i];
    }

    tempList[ListEmployee.size] = employee;

    delete[] ListEmployee.listEmployee;
    ListEmployee.listEmployee = tempList;
    ListEmployee.size++;
}


void addListSalary(ListEmployee& ListEmployee, Employee& employee){
    // Employee* tempList = new Employee[ListEmployee.sizeSalary+1]; 

    // for(int i = 0; i < ListEmployee.sizeSalary; i++){
    //     tempList[i] = ListEmployee.listSalary[i];
    // }

    // tempList[ListEmployee.sizeSalary] = employee;

    // delete[] ListEmployee.listSalary;
    // ListEmployee.listSalary = tempList;
    // ListEmployee.sizeSalary++;
    employee = initSalary(employee);
}


void showStat(){
    cout << setw(20) << left << "| ID " ; 
    cout << setw(20) << left << "| Ten ";
    cout << setw(20) << left << "| Gia dinh ";
    cout << setw(20) << left << "| So con ";
    cout << setw(20) << left << "| Xa hoi ";
    cout << setw(20) << left << "| Luong "<< endl;
}


void showEmployee(Employee& employee){
    cout << "| " << setw(18) << left << employee.employeeID; 
    cout << "| " << setw(18) << left << employee.employeeName;
    cout << "| " << setw(18) << left << employee.familyState;
    cout << "| " << setw(18) << left << employee.childNumber;
    cout << "| " << setw(18) << left << employee.socialState;
    cout << "| " << setw(18) << left << employee.basicSalary << endl;
}


void showSingleEmployee(Employee& employee){
    cout << "==Thong Tin Nhan Vien==" << endl;
    showStat();
    showEmployee(employee);
}


void showListEmployee(ListEmployee& ListEmployee){
    cout << "==Thong Tin Nhan Vien==" << endl;
    showStat();
    for(int i = 0; i < ListEmployee.size; i++){
        showEmployee(ListEmployee.listEmployee[i]);
    }
}


void showSingleSalary(Employee& employee){
    cout << setw(20) << left << "| ID " ; 
    cout << setw(20) << left << "| Ten ";
    cout << setw(20) << left << "| Nghi co phep ";
    cout << setw(20) << left << "| Nghi khong phep ";
    cout << setw(20) << left << "| So ngay lam them ";
    cout << setw(20) << left << "| Ket qua lam viec ";
    cout << setw(20) << left << "| TONG LUONG "<< endl;

    cout << "| " << setw(18) << left << employee.employeeID; 
    cout << "| " << setw(18) << left << employee.employeeName;
    cout << "| " << setw(18) << left << employee.legalDayOff;
    cout << "| " << setw(18) << left << employee.illDayOff;
    cout << "| " << setw(18) << left << employee.overtimeWork;
    cout << "| " << setw(18) << left << employee.workResult;
    cout << "| " << setw(18) << left << employee.realSalary << endl;
}


void showListSalary(ListEmployee& ListEmployee){
    int month;
    cout << "==Bang luong nhan vien==" << endl;
    cout << "Bang luong thang (1->12): ";
    cin >> month;
    
    for(int i = 0; i < ListEmployee.size; i++){
        updateDataFromList(ListEmployee.salaryPerMonth[i][month-1], ListEmployee.listEmployee[i]);
        showSingleSalary(ListEmployee.salaryPerMonth[i][month-1]);
    }
}


void showMenu(Menu& menu){
    char option;
    bool error; 
        cout << "===MENU===" << endl;
        cout << "1. Cap nhat ly lich, bang cham cong." << endl;
        cout << "2. Xem thong tin nhan vien." << endl;
        cout << "3. Tim thong tin nhan vien." << endl; 
        cout << "4. Xoa thong tin nhan vien. " << endl;
        cout << "Nhap chuc nang: ";
        cin >> option;
    do{
        error = false;
        // while(option>='1' && option <='6')
        switch (option)
        {
        case '1':
            menu.Option = '1';
            break;
        case '2':
            menu.Option = '2';
            break;
        case '3':
            menu.Option = '3';
            break;
        case '4':
            menu.Option = '4';
            break;
        case 'o':
            menu.Option = 'o';
            break;
        default:
            system("cls");
            menu.Option = 'e';
            error = true;
            cout << "===MENU===" << endl;
            cout << "1. Cap nhat ly lich, bang cham cong." << endl;
            cout << "2. Xuat thong tin nhan vien." << endl;
            cout << "3. Tim thong tin nhan vien." << endl; 
            cout << "4. Xoa thong tin nhan vien. " << endl;
            cout << "Sai chuc nang, vui long nhap lai: ";
            cin >> option;
            break;
        }
    }while(error);
}


void showConfigOption(Menu& menu){
    char option;
    bool error; 
        cout << "===Chon noi dung cap nhat===" << endl;
        cout << "1. Them ly lich nhan vien." << endl;
        cout << "2. Them bang cham cong." << endl;
        cout << "3. Cap nhat ly lich nhan vien." << endl;
        cout << "4. Cap nhat bang cham cong." << endl;
        cout << "Nhap chuc nang: ";
        cin >> option;
    do{
        error = false;
        // while(option>='1' && option <='6')
        switch (option)
        {
        case '1':
            menu.configOption = '1';
            break;
        case '2':
            menu.configOption = '2';
            break;
        case '3':
            menu.configOption = '3';
            break;
        default:
            system("cls");
            menu.Option = 'e';
            error = true;
            cout << "===Chon noi dung cap nhat===" << endl;
            cout << "1. Them ly lich nhan vien." << endl;
            cout << "2. Them bang cham cong." << endl;
            cout << "3. Cap nhat ly lich nhan vien." << endl;
            cout << "4. Cap nhat bang cham cong." << endl;
            cout << "Sai chuc nang, vui long nhap lai: ";
            cin >> option;
            break;
        }
    }while(error);
}


void showDisplayOption(Menu& menu){
    char option;
    bool error; 
        cout << "===Chon noi dung xuat thong tin===" << endl;
        cout << "1. Xuat ly lich nhan vien." << endl;
        cout << "2. Xuat bang luong." << endl;
        cout << "Nhap chuc nang: ";
        cin >> option;
    do{
        error = false;
        // while(option>='1' && option <='6')
        switch (option)
        {
        case '1':
            menu.displayOption = '1';
            break;
        case '2':
            menu.displayOption = '2';
            break;
        default:
            system("cls");
            menu.Option = 'e';
            error = true;
            cout << "===Chon noi dung xuat thong tin===" << endl;
            cout << "1. Xuat ly lich nhan vien." << endl;
            cout << "2. Xuat bang luong." << endl;
            cout << "Sai chuc nang, vui long nhap lai: ";
            cin >> option;
            break;
        }
    }while(error);
}


void addMultiData(Employee& employee, ListEmployee& list){
    int numberData;
    cout << "So luong nhan vien muon them: ";
    cin >> numberData;
    // list.size = 0;
    if (list.listEmployee == nullptr) {
        list.listEmployee = new Employee[numberData];
        list.size = 0; 
    }
    else {
        Employee* newList = new Employee[list.size + numberData];
        for (int i = 0; i < list.size; i++) {
            newList[i] = list.listEmployee[i];
        }
        delete[] list.listEmployee; 
        list.listEmployee = newList; 
    }
    for(int i = 0; i < numberData; i++){
        employee = initEmployee(employee);
        addListEmployee(list, employee);
    }
}


void addMultiSalary(Employee& employee, ListEmployee& list){
    int month;
    cout << "Thang cham cong: ";
    cin >> month;
    list.listSalary = nullptr;
    list.sizeSalary = 0;
    for(int i = 0; i < list.size; i++){
        // employee = initSalary(employee);
        addListSalary(list, list.listEmployee[i]);
        list.salaryPerMonth[i][month-1] = list.listEmployee[i];
    }
}


void updateDataFromList(Employee& currentData, Employee& updateData){
    currentData = updateData;
}

int findFromList(ListEmployee& list, char id[]){
    int getElement;
    for(int i = 0; i < list.size; i++){
        if(strcmp(id, list.listEmployee[i].employeeID) == 0){
            getElement = i;
            break;
        }
    }
    return getElement;
}


void showEmployeeInfo(ListEmployee& list){
    char id[8];
    cout << "ID nhan vien : ";
    (cin>>ws).getline(id, sizeof(id)+1);
    int indexToShow = findFromList(list, id);
    showSingleEmployee(list.listEmployee[indexToShow]);
}


void removeEmployeeFromList(Employee& employee, ListEmployee& list){
    char id[8];
    cout << "ID nhan vien muon xoa: ";
    (cin>>ws).getline(id, sizeof(id)+1);
    int indexToRemove = findFromList(list, id);
    Employee* newArr = new Employee[list.size - 1];
    if (indexToRemove != -1) { 
        Employee* newArr = new Employee[list.size - 1];

        for (int i = 0; i < indexToRemove; i++) {
            newArr[i] = list.listEmployee[i];
        }

        for (int i = indexToRemove; i < list.size - 1; i++) {
            newArr[i] = list.listEmployee[i + 1];
        }

        delete[] list.listEmployee;
        list.listEmployee = newArr;
        list.size--;
    } 
    else {
        cout << "Khong tim thay nhan vien." << endl;
    }
    // cout << "Thong tin nhan vien da xoa: " << endl;
    // showSingleEmployee(list.listEmployee[indexToRemove]);
}


void configEmployeeInfo(ListEmployee& list){
    char id[8];
    char configOption;
    cout << "ID nhan vien muon chinh sua: ";
    (cin>>ws).getline(id, sizeof(id)+1);
    int indexToConfig = findFromList(list, id);
    cout << "==Chon thong tin muon chinh sua==" << endl;
    cout << "1. Ma nhan vien. " << endl;
    cout << "2. Ho ten. " << endl;
    cout << "3. Tinh trang gia dinh. " << endl;
    cout << "4. So con. " << endl;
    cout << "5. Trinh do van hoa. " << endl;
    cout << "6. Luong co ban. " << endl;
    cout << "Chon thong tin: ";
    cin >> configOption;
    switch (configOption)
    {
    case '1':
        cout << "Nhap ID moi: ";
        (cin>>ws).getline(list.listEmployee[indexToConfig].employeeID, sizeof(list.listEmployee[indexToConfig].employeeID)+1);
        break;
    case '2':
        cout << "Nhap ho ten moi: ";
        (cin>>ws).getline(list.listEmployee[indexToConfig].employeeName, sizeof(list.listEmployee[indexToConfig].employeeName)+1);
        break;
    case '3':
        cout << "Nhap tinh trang gia dinh moi: ";
        cin >> list.listEmployee[indexToConfig].familyState;
        break;
    case '4':
        cout << "Nhap so con moi: ";
        cin >> list.listEmployee[indexToConfig].childNumber;
        break;
    case '5':
        cout << "Nhap trinh do van hoa moi: ";
        (cin>>ws).getline(list.listEmployee[indexToConfig].socialState, sizeof(list.listEmployee[indexToConfig].socialState));
        break;
    case '6':
        cout << "Luong co ban moi: ";
        cin >> list.listEmployee[indexToConfig].basicSalary;
        break;
    default:
        cout << "Khong co thong tin nay !";
        break;
    }
}


void configSalaryTabInfo(ListEmployee& list){
    char id[8];
    char configOption;
    int month;
    cout << "Thang cham cong (1->12)";
    cin >> month;
    cout << "ID nhan vien muon chinh sua: ";
    (cin>>ws).getline(id, sizeof(id)+1);
    int indexToConfig = findFromList(list, id);
    cout << "==Chon thong tin muon chinh sua==" << endl;
    cout << "1. So ngay nghi co phep. " << endl;
    cout << "2. So ngay nghi khong phep. " << endl;
    cout << "3. So ngay lam them. " << endl;
    cout << "4. Ket qua lam viec. " << endl;
    cout << "Chon thong tin: ";
    cin >> configOption;
    switch (configOption)
    {
    case '1':
        cout << "Nhap so ngay nghi co phep: ";
        cin >> list.salaryPerMonth[indexToConfig][month-1].legalDayOff;
        break;
    case '2':
        cout << "Nhap so ngay nghi khong phep: ";
        cin >> list.salaryPerMonth[indexToConfig][month-1].illDayOff;
        break;
    case '3':
        cout << "Nhap so ngay lam them: ";
        cin >> list.salaryPerMonth[indexToConfig][month-1].overtimeWork;
        break;
    case '4':
        cout << "Nhap ket qua lam viec: ";
        cin >> list.salaryPerMonth[indexToConfig][month-1].workResult;
        break;
    default:
        cout << "Khong co thong tin nay !";
        break;
    }
    list.salaryPerMonth[indexToConfig][month-1].realSalary = getRealSalary(list.salaryPerMonth[indexToConfig][month-1]);
}   


