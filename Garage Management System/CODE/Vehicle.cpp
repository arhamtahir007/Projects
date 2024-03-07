#include "Vehicle.h"

void Vehicle::generalInput(){
    cout<<"\nEnter no of Doors: ";//bat suno apni apni Car k operator overloading m apni car k mutabik
    cin>>noOfDoors;                // doors, seats, or tyres k check laga dena refrence k liye SportsCar ki cpp
    cout<<"\nEnter no of Seats: ";  // file m cin ki operator over loading check karo....
    cin>>noOfSeats;                // :D I believe in you ( ´･･)ﾉ(._.`)
    cout<<"\nEnter no of Tyres: ";
    cin>>noOfTyres;
    cout<<"\nEnter Engine Capacity: ";
    cin>>engineCC;
    gI:
    cout<<"\nEnter Transmission Type: ";
    cin>>transmissionType;
    if (transmissionType != "auto" && transmissionType != "Auto" && transmissionType != "manual" && transmissionType != "Manual"){
        cout<<"Enter \"Auto\" or \"Manual\" only.\n";
        goto gI;
    }
    cout<<"\nEnter Color: ";
    cin>>color;
    cin.ignore();
    cout<<"\nEnter briefly about Faults in "<<vehicleType<<": ";
    getline(cin,fault);
}

void Vehicle::generalOutput() const {
    cout<<"\n\nVehicle Type: "<<vehicleType;
    cout<<"\n\nEngine Capacity: "<<engineCC<<" CC";
    cout<<"\n\nTransmission Type: "<<transmissionType;
    cout<<"\n\nNumber of Doors: "<<noOfDoors;
    cout<<"\n\nNumber of Seats: "<<noOfSeats;
    cout<<"\n\nNumber of Tyres: "<<noOfTyres;
    cout<<"\n\nRegistration Number: "<<numPlate;
    cout<<"\n\nFaults: "<<fault<<endl<<endl;
}

string Vehicle::getVehicleType() {
    return vehicleType;
}

string Vehicle::setNumPlate(string x) {
    numPlate = x;
    return numPlate;
}



