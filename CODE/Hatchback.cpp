#include "Hatchback.h"
void Hatchback:: vehicleReturn() {   //virtual function call as in other car classes
    cout<<"Classification of Car: "<<vehicleType<<endl;
    cout<<"Registration Number: "<<numPlate<<endl;
    cout<<"Color: "<<color<<endl;
}

istream & operator >>(istream& in ,Hatchback& obj){
    obj.generalInput();
    cout<<"\nEnter number of airbags: ";
    in>>obj.airBags;

    cout<<"\nEnter type of Power locks: ";  // door locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )
    in>>obj.powerLocks;
    while (true) {
        if (obj.powerLocks != "single" && obj.powerLocks != "Single" && obj.powerLocks != "dual" &&
            obj.powerLocks != "Dual") {
            cout << "Enter \"single \" or \"dual\" only.\n";
            in >> obj.powerLocks;
        }
        else
            break;
    }

    while(true) {
        if (obj.noOfDoors != 4) {
            cout << "Invalid Number of Doors, Enter again.\n";
            cout << "Enter no of Doors:\n";
            in >> obj.noOfDoors;

        }
        else
            break;
    }
    while(true) {
        if (obj.noOfSeats != 5 && obj.noOfSeats != 4) {
            cout << "Invalid Number of Seats, Enter again.\n";
            cout << "Enter no of Seats:\n";
            in >> obj.noOfSeats;

        }
        else
            break;
    }
    while(true) {
        if (obj.noOfTyres != 4) {
            cout << "Invalid Number of Tyres, Enter again.\n";
            cout << "Enter no of Tyres:\n";
            in >> obj.noOfTyres;

        }
        else
            break;
    }
    return in;
}
ostream &operator << (ostream& out,const Hatchback& obj) {
    obj.generalOutput();
    out<<"\nPowerLocks Type: "<<obj.powerLocks<<endl;
    out<<"AirBags Numbers: "<<obj.airBags<<endl;
    return out;
}


void Hatchback::dataRecord(){
    ofstream input("Hatch Back Record.txt",ios::out | ios::app);
    input<<numPlate<<" "<<noOfDoors<<" "<<noOfTyres<<" "<<noOfSeats<<" "<<engineCC<<" "
         <<color<<" "<<transmissionType<<" "<<vehicleType<<" "<<airBags<<" "<<powerLocks<<" "<<fault<<endl;
    input.close();
}

Hatchback Hatchback:: dataReading(string temp) {
    Hatchback car;
    string input;
    ifstream output("Hatch Back Record.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    output.close();
    output.open("Hatch Back Record.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        output >> car.numPlate;
        output >> car.noOfDoors;
        output >> car.noOfTyres;
        output >> car.noOfSeats;
        output >> car.engineCC;
        output >> car.color;
        output >> car.transmissionType;
        output >> car.vehicleType;
        output >> car.airBags;
        output >> car.powerLocks;
        getline(output, car.fault);
        if (car.numPlate == temp) {
            return car;
        }
    }
    cout << "Record Not Found.\n";
    Hatchback null;
    return null;
}