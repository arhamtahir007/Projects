#include "Employee.h"

istream &operator>>(istream &input, Employee &person) {
    int i;string s;
    cout<<"\nEnter Employee First Name: ";
    input>>person.first_name;
    cout<<"\nEnter Employee Second Name: ";
    input>>person.second_name;
    cout<<"\nEnter Employee Contact Number: ";
    input>>person.contact_no;
    cout<<"\nEnter Employee Monthly Salary: ";
    input>>person.salary;
    cout<<"\nEnter Employee City Name: ";
    input>>s; person.address.setCityName(s);
    cout<<"\nEnter Employee Area Name: ";
    cin.ignore();
    getline(input,s); person.address.setArea(s);
    cout<<"\nEnter Employee Street Number: ";
    input>>i; person.address.setStreetNumber(i);
    cout<<"\nEnter Customer House Number: ";
    input>>i; person.address.setHouseNumber(i);
    return input;
}

ostream &operator<<(ostream &output, const Employee &person) {
    output<<"\nFirst Name: "<<person.first_name<<endl;
    output<<"\nSecond Name: "<<person.second_name<<endl;
    output<<"\nContact Number: "<<person.contact_no<<endl;
    output<<"\nSalary: "<<person.salary<<" $"<<endl;
    output<<"\nCity Name: "<<person.address.getCityName()<<endl;
    output<<"\nArea Name: "<<person.address.getArea()<<endl;
    output<<"\nStreet Number: "<<person.address.getStreetNumber()<<endl;
    output<<"\nHouse Number: "<<person.address.getHouseNumber()<<endl;
    return output;
}

void Employee::writeToFile() {
    fstream write("Employee Record.txt",ios::out | ios::app);
    write<<first_name<<" "<<second_name<<" "<<contact_no<<" "<<salary<<" "<<address.getCityName()
         <<" "<<address.getStreetNumber()<<" "<<address.getHouseNumber()<<" "<<address.getArea()<<endl;
}


void readFromFileEmployee() {
    Employee temp;
    string counter;
    fstream read("Employee Record.txt",ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    read.close();
    read.open("Employee Record.txt",ios::in);
    string s;int j;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> temp.first_name;
        read >> temp.second_name;
        read >> temp.contact_no;
        read >> temp.salary;
        read >> s; temp.address.setCityName(s);
        read >> j; temp.address.setStreetNumber(j);
        read >> j; temp.address.setHouseNumber(j);
        getline(read,s);
        temp.address.setArea(s);
        cout<<temp<<endl;
    }
}
