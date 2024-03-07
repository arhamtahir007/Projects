#include "SportsCar.h"

ostream &operator << (ostream& o,const SportsCar& temp) {
    temp.generalOutput();
    o<<"Turbo Type: "<<temp.turboType<<endl;
    o<<"Spoiler Type: "<<temp.spoilerType<<endl;
    return o;
}

istream &operator >> (istream& i,SportsCar& temp) {
    temp.generalInput();
    cout<<"\nEnter Turbo Type: ";
    i>>temp.turboType;
    cout<<"\nEnter Spoiler Type: ";
    i>>temp.spoilerType;

    sc0:
    if (temp.noOfDoors <= 0 || temp.noOfDoors == 3 || temp.noOfDoors > 4){
        cout<<"Invalid Number of Doors, Enter again.\n";
        cout<<"Enter no of Doors:\n";
        i>>temp.noOfDoors;
        goto sc0;
    }

    sc1:
    if (temp.noOfSeats <= 0 || temp.noOfSeats == 3 || temp.noOfSeats > 4){
        cout<<"Invalid Number of Seats, Enter again.\n";
        cout<<"Enter no of Seats:\n";
        i>>temp.noOfSeats;
        goto sc1;
    }

    sc2:
    if (temp.noOfTyres != 4){
        cout<<"Invalid Number of Tyres, Enter again.\n";
        cout<<"Enter no of Tyres:\n";
        i>>temp.noOfTyres;
        goto sc2;
    }
    return i;
}

void SportsCar::vehicleReturn() {
    cout<<"Classification of Car: "<<vehicleType<<endl;
    cout<<"Registration Number: "<<numPlate<<endl;
    cout<<"Color: "<<color<<endl;
}


void SportsCar::dataRecord() {
    fstream in("Sports Car Record.txt",ios::out | ios::app);
    in<<numPlate<<" "<<noOfDoors<<" "<<noOfTyres<<" "<<noOfSeats<<" "<<engineCC<<" "<<color<<" "
    <<transmissionType<<" "<<vehicleType<<" "<<turboType<<" "<<spoilerType<<" "<<fault<<endl;
    in.close();
}

SportsCar SportsCar::dataReading(string temp) {
    SportsCar sc;
    string counter;
    fstream out("Sports Car Record.txt", ios::in);
    int noOfEntries = 0;
    while (!out.eof()) {
        getline(out, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    out.close();
    out.open("Sports Car Record.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        out >> sc.numPlate;
        out >> sc.noOfDoors;
        out >> sc.noOfTyres;
        out >> sc.noOfSeats;
        out >> sc.engineCC;
        out >> sc.color;
        out >> sc.transmissionType;
        out >> sc.vehicleType;
        out >> sc.turboType;
        out >> sc.spoilerType;
        getline(out, sc.fault);
        if (temp == sc.numPlate) {
            return sc;
        }
    }
    cout << "Record Not Found.\n";
    SportsCar null;
    return null;
}
