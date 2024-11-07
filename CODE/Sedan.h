#ifndef GARAGE_SEDAN_H
#define GARAGE_SEDAN_H

#include "SportsCar.h"

class Sedan: public Vehicle{
protected:
    int airBags ;
    string powerLocks;
    string powerWindows;
public:
    Sedan(){ // default constructor
        airBags=0;
        powerLocks="";
        powerWindows="";
        vehicleType = "Sedan";
    }

    void vehicleReturn(); // polymirization virtual function
    Sedan dataReading(string temp); //filing data reading function
    void dataRecord();// storing data

    friend void removeSedan(string,string,int);
    friend void sedanEdit(Sedan*,int,int);


    friend istream &operator >> (istream& ,Sedan&);
    friend ostream &operator << (ostream& ,const Sedan& );

};




#endif //GARAGE_SEDAN_H
