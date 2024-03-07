#include "Person.h"

string Person::setFirstName( string n) {
    first_name =n;
    return first_name;
}

string Person::setSecondName(string m) {
    second_name=m;
    return second_name;
}

string Person::setContactNo(string y){
    contact_no=y;
    return contact_no;
}

string Person::getFirstName(){
    return first_name;
}

string Person::getSecondName(){
    return second_name;
}

string Person::getContactNo(){
    return contact_no;
}