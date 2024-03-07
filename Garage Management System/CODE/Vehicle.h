#ifndef GARAGE_VEHICLE_H
#define GARAGE_VEHICLE_H

#endif //GARAGE_VEHICLE_H
#pragma once
#include<iostream>
#include <fstream>
#include "Customer.h"
using namespace std;

class Vehicle{
protected:
    int noOfDoors;
    int noOfTyres;
    int noOfSeats;
    int engineCC;

    string numPlate;
    string color;
    string transmissionType;
    string fault;
    string vehicleType;
public:
    Vehicle(){
        noOfDoors = 0;
        noOfSeats = 0;
        noOfTyres = 0;
        engineCC = 0;
        numPlate = "";
        color = "";
        transmissionType = "";
        fault = "";
        vehicleType = "";
    }

    string setNumPlate(string);

    void generalInput();
    void generalOutput() const;

    virtual void vehicleReturn() = 0;//ye polymorphism k liye hai sab apni spni class m is ka
                                     //function bananah. Refrence k liye SportsCar dekh lena
    string getVehicleType();
};