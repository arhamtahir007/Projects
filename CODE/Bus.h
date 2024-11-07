#ifndef GARAGE_BUS_H
#define GARAGE_BUS_H


#include "Vehicle.h"

class Bus : public Vehicle
{
    bool lcd;

public:
    Bus();

    void vehicleReturn() override;
    void dataRecord();
    Bus dataReading(string);

    friend ostream &operator <<(ostream &, Bus &);
    friend istream &operator >>(istream &, Bus &);

    friend void removeBus(string, string, int);
    friend void busEdit(Bus*, int, int);
};

#endif //GARAGE_BUS_H
