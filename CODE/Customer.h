#ifndef MAIN_CPP_CUSTOMER_H
#define MAIN_CPP_CUSTOMER_H

#endif //MAIN_CPP_CUSTOMER_H
#include "Employee.h"

class Customer:public Person{
    string vehicleType;
    string number_plate;
public:
    Customer(){
        number_plate = "";
        vehicleType = "";
    }

    string setNumberPlate(string x);
    string getNumberPlate();

    string setVehicleType(string x);
    string getVehicleType();

    void writeToFile();
//    friend void readFromFileCustomer();

    friend Customer searchCustomer();
    friend void removeCustomer(int);
    friend void viewAllCusVeh();
    friend void customerEdit(Customer*,int,int);

    friend istream &operator >> (istream& input,Customer& person);
    friend ostream &operator << (ostream& output,const Customer& person);
};

//void readFromFileCustomer();