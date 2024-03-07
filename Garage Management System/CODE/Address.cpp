#include "Address.h"
void Address:: setCityName(string x){
    city_name=x;
}
void Address:: setArea(string a){
    area=a;
}
void  Address::setStreetNumber(int c){
    street_number=c;
}
void Address::setHouseNumber(int y){
    house_number=y;
}
string Address:: getCityName() const {
    return city_name;
}
string Address::getArea() const{
    return area;
}
int Address::getStreetNumber() const{
    return street_number;
}
int Address::getHouseNumber() const{
    return house_number;
}
