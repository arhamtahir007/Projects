//
// Created by fajar.pk on 3/21/2023.
//

#ifndef GARAGE_PERSON_H
#define GARAGE_PERSON_H

#include "Address.h"
#include "fstream"
//#pragma once
class Person {
protected:
    string first_name;
    string second_name;
    string  contact_no;
    Address address;
public:
    Person(){
        first_name= "";
        second_name="";
        contact_no="";
    }

    string setFirstName(string n);
    string getFirstName();

    string setSecondName(string m);
    string getSecondName();

    string setContactNo(string y);
    string getContactNo();

};


#endif //GARAGE_PERSON_H
