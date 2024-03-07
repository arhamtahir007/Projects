#include "Customer.h"

string Customer::getNumberPlate() {
    return number_plate;
}

string Customer::setNumberPlate(string x) {
    number_plate = x;
    return number_plate;
}

string Customer::getVehicleType() {
    return vehicleType;
}

string Customer::setVehicleType(string x) {
    vehicleType = x;
    return vehicleType;
}

istream &operator>>(istream &input, Customer &person) {
    int i;
    string s;
    cout << "\nEnter Customer First Name: ";
    input >> person.first_name;
    cout << "\nEnter Customer Second Name: ";
    input >> person.second_name;
    cout << "\nEnter Customer Contact Number: ";
    input >> person.contact_no;
    cout << "\nEnter Customer Vehicle Registration Number: ";
    input >> person.number_plate;
    cout << "\nEnter Customer City Name: ";
    input >> s;
    person.address.setCityName(s);
    cout << "\nEnter Customer Area Name: ";
    cin.ignore();
    getline(input, s);
    person.address.setArea(s);
    cout << "\nEnter Customer Street Number: ";
    input >> i;
    person.address.setStreetNumber(i);
    cout << "\nEnter Customer House Number:";
    input >> i;
    person.address.setHouseNumber(i);
    return input;
}

ostream &operator<<(ostream &output, const Customer &person) {
    output << "\nFirst Name: " << person.first_name << endl;
    output << "\nSecond Name: " << person.second_name << endl;
    output << "\nContact Number: " << person.contact_no << endl;
    output << "\nVehicle Registration Number: " << person.number_plate << endl;
    output << "\nCity Name: " << person.address.getCityName() << endl;
    output << "\nArea Name: " << person.address.getArea() << endl;
    output << "\nStreet Number: " << person.address.getStreetNumber() << endl;
    output << "\nHouse Number: " << person.address.getHouseNumber() << endl;
    return output;
}

void Customer::writeToFile() {
    fstream write("Customer Record.txt", ios::out | ios::app);
    write << first_name << " " << second_name << " " << contact_no << " " << number_plate << " " << vehicleType <<
    " " << address.getCityName() << " " << address.getStreetNumber() << " " << address.getHouseNumber()
    << " " << address.getArea() << endl;
}

/*void readFromFileCustomer() {
    Customer temp;
    string counter;
    fstream read("Customer Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    read.close();
    string nameOne, nameTwo;
    cout << "Enter First Name:\n";
    cin >> nameOne;
    cout << "Enter Second Name:\n";
    cin >> nameTwo;
    read.open("Customer Record.txt", ios::in);
    string s;
    int j;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> temp.first_name;
        read >> temp.second_name;
        read >> temp.contact_no;
        read >> temp.number_plate;
        read >> temp.vehicleType;
        read >> s;
        temp.address.setCityName(s);
        read >> j;
        temp.address.setStreetNumber(j);
        read >> j;
        temp.address.setHouseNumber(j);
        getline(read, s);
        temp.address.setArea(s);
        if (temp.first_name == nameOne) {
            if (temp.second_name == nameTwo) {
                cout << temp;
                return;
            }
        }
    }
    cout << "Record Not Found!\n";
}*/
