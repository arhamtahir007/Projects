#ifndef MAIN_CPP_CUSTOMERLINKVEHICLE_H
#define MAIN_CPP_CUSTOMERLINKVEHICLE_H

#endif //MAIN_CPP_CUSTOMERLINKVEHICLE_H
#include "Hatchback.h"
#include "Bus.h"

template<typename T>
class CusVeh{                                       //This class will be used for association and aggregation
    Customer* customer;
    T* vehicle;
public:
    CusVeh()
    {
        customer = nullptr;
        vehicle = nullptr;
    }
    explicit CusVeh(Customer* cus, T* veh)
    {
        customer = cus;
        vehicle = veh;
    }

    void setCustomer(Customer* cus)
    {
        customer = cus;
    }

    void setVehicle(T* veh)
    {
        vehicle = veh;
    }

    void filing()
    {
        customer->setVehicleType(vehicle->getVehicleType());                    //adds vehicle type to customer info
        customer->writeToFile();            //saves  customer info in file
        vehicle->setNumPlate(customer->getNumberPlate());           //adds number plate to vehicle
        vehicle->dataRecord();              //saves vehicle info in file
    }
};

