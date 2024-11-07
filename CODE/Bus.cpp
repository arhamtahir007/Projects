#include "Bus.h"

Bus::Bus()
{
    vehicleType = "Bus";
    lcd = 0;
}

void Bus::dataRecord()
{
    fstream ofile("Bus Record.txt", ios::out| ios::app);       //opening bus record file
    ofile<<numPlate<<" "<<noOfDoors<<" "<<noOfTyres<<" "<<noOfSeats<<" "<<engineCC<<" "<<color<<" "
    <<transmissionType<<" "<<vehicleType<<" "<<lcd<<" "<<fault<<endl;                     //writing all data of bus object to file
    ofile.close();          //closing file
}

void Bus::vehicleReturn()
{
    cout<<"\nClassification of Car: "<<vehicleType<<endl;
    cout<<"\nRegistration Number: "<<numPlate<<endl;
    cout<<"\nColor: "<<color<<endl;
}

Bus Bus::dataReading(string plate)
{
    Bus bus;
    string counter;
    ifstream ifile("Bus Record.txt");
    int noOfEntries = 0;
    while (!ifile.eof())
    {
        getline(ifile, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    ifile.close();
    ifile.open("Bus Record.txt");
    for (int i = 0; i < noOfEntries; ++i)
    {
        ifile >> bus.numPlate;
        ifile >> bus.noOfDoors;
        ifile >> bus.noOfTyres;
        ifile >> bus.noOfSeats;
        ifile >> bus.engineCC;
        ifile >> bus.color;
        ifile >> bus.transmissionType;
        ifile >> bus.vehicleType;
        ifile >> bus.lcd;
        getline(ifile, bus.fault);
        if (plate == bus.numPlate)
        {
            return bus;
        }
    }
    cout << "\nRecord Not Found.\n";
    Bus null;
    return null;
}

ostream &operator <<(ostream &out, Bus &a)
{
    a.generalOutput();
    if(a.lcd)
        out<<"\nLCD: Yes";
    else
        out<<"\nLCD: No";
    return out;
}

istream &operator >>(istream &in, Bus &a)
{
    a.generalInput();
    string lcd;
    err0:
    cout<<"\nLCD in bus? ";
    in>>lcd;

    if(lcd == "y" || lcd == "Y")
    {
        a.lcd = true;
    }
    else if (lcd == "n" || lcd == "N")
    {
        a.lcd = false;
    }
    else
    {
        cout<<"Invalid Input. Enter again:\n";
        goto err0;
    }
    err1:
    if (a.noOfDoors <= 0)
    {
        cout<<"Invalid Number of Doors, Enter again";
        cout<<"Enter no of Doors:";
        in>>a.noOfDoors;
        goto err1;             //goes to err1 on line 25
    }

    err2:
    if (a.noOfSeats <= 0 || a.noOfSeats == 10)
    {
        cout<<"Invalid Number of Seats, Enter again\n";
        cout<<"Enter no of Seats:";
        in>>a.noOfSeats;
        goto err2;          //goes to err2 on line 34
    }

    err3:
    if (a.noOfTyres < 4)
    {
        cout<<"Invalid Number of Tyres, Enter again";
        cout<<"Enter no of Tyres:";
        in>>a.noOfTyres;
        goto err3;          //goes to err3 on line 43
    }
    return in;
}
