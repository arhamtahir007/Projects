#ifndef SEDAN_CPP_FUNCTIONS_H
#define SEDAN_CPP_FUNCTIONS_H

#endif //SEDAN_CPP_FUNCTIONS_H
#include "LogIn.h"
#include "CustomerLinkVehicle.h"

void addVehicle(Customer temp);

void returningVehicle();

Customer searchCustomer();

Employee searchEmployee();

void payment();

void employeeManagement();

void removeEmployee(int mode);

void removeCustomer(int);

void customerManagement();

void removeSedan(string regNum,string numPlateChange,int);

void removeHatchBack(string regNum,string numPlateChange,int);

void removeSportsCar(string regNum,string numPlateChange,int);

void removeBus(string, string, int);

void viewAllCusVeh();

void customerEdit(Customer*,int,int);

void sedanEdit(Sedan*,int,int);

void hatchBackEdit(Hatchback*,int,int);

void sportsCarEdit(SportsCar*,int,int);

void busEdit(Bus*, int, int);

void employeeEdit(Employee*,int,int);