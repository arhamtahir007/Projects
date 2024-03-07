#ifndef GARAGE_ADDRESS_H
#define GARAGE_ADDRESS_H



#include <iostream>
using namespace std;

class Address {
private:
    string city_name;
    string area;
    int street_number;
    int house_number;

public:
    Address(){
        city_name="";
        area="";
        street_number=0;
        house_number=0;
    }
    void setCityName(string x);
    void setArea(string a);
    void setStreetNumber(int c);
    void setHouseNumber(int y);
    string getCityName() const;
    string getArea() const;
    int getStreetNumber() const;
    int getHouseNumber() const;

};


#endif //GARAGE_ADDRESS_H
