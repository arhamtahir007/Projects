#include "Sedan.h"

void Sedan::vehicleReturn() {   //virtual function call as in other car classes
    cout << "Classification of Car: " << vehicleType << endl;
    cout << "Registration Number: " << numPlate << endl;
    cout << "Color: " << color << endl;
}

Sedan Sedan::dataReading(string temp) {
    Sedan car;
    string input;
    ifstream output("Sedan Record.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    output.close();
    output.open("Sedan Record.txt", ios::in);
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
        output >> car.powerWindows;
        getline(output, car.fault);
        if (car.numPlate == temp) {
            return car;
        }
    }
    cout << "Record Not Found.\n";
    Sedan null;
    return null;
}

void Sedan::dataRecord() {
    ofstream input("Sedan Record.txt", ios::out | ios::app);
    input << numPlate << " " << noOfDoors << " " << noOfTyres << " " << noOfSeats << " " << engineCC << " " << color
          << " "
          << transmissionType << " " << vehicleType << " " << airBags << " " << powerLocks << " " << powerWindows << " "
          << fault << endl;

    input.close();
}


istream &operator>>(istream &input, Sedan &car) {
    car.generalInput();
    cout << "Enter number of Airbags:" << endl;
    input >> car.airBags;

    cout << "Enter type of Power locks:"
         << endl;  // door locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )
    input >> car.powerLocks;
    while (true) {
        if (car.powerLocks != "single" && car.powerLocks != "Single" && car.powerLocks != "dual" &&
            car.powerLocks != "Dual") {
            cout << "Enter \"single \" or \"dual\" only.\n";
            input >> car.powerLocks;
        }
        else
            break;
    }

        cout<<"Type of Power Windows:\n";
        input>> car.powerWindows;// window locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )
    while (true) {
        if (car.powerWindows != "single" && car.powerWindows != "Single" && car.powerWindows != "dual" &&
            car.powerWindows != "Dual") {
            cout << "Enter \"single \" or \"dual\" only.\n";
            input >> car.powerWindows;
        }
        else
            break;
    }
    while (true) {
        if (car.noOfDoors != 4) {
            cout << "Invalid Number of Doors, Enter again.\n";
            cout << "Enter no of Doors:\n";
            input >> car.noOfDoors;

        } else
            break;
    }
    while (true) {
        if (car.noOfSeats != 5 && car.noOfSeats != 4) {
            cout << "Invalid Number of Seats, Enter again.\n";
            cout << "Enter no of Seats:\n";
            input >> car.noOfSeats;

        } else
            break;
    }
    while (true) {
        if (car.noOfTyres != 4) {
            cout << "Invalid Number of Tyres, Enter again.\n";
            cout << "Enter no of Tyres:\n";
            input >> car.noOfTyres;

        } else
            break;
    }
    return input;
}

ostream &operator<<(ostream &out, const Sedan &obj) {
    obj.generalOutput();
    out << "PowerLocks Type: " << obj.powerLocks << endl;
    out << "PowerWindows Type: " << obj.powerWindows << endl;
    out << "AirBags Numbers: " << obj.airBags << endl;
    return out;
}