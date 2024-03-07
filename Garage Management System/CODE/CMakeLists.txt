cmake_minimum_required(VERSION 3.23)
project(Garage)

set(CMAKE_CXX_STANDARD 14)

add_executable(Garage Functions.h Functions.cpp main.cpp Customer.cpp Customer.h Employee.cpp Employee.h Address.cpp Address.h Hatchback.cpp Hatchback.h LogIn.cpp LogIn.h Sedan.cpp Sedan.h CustomerLinkVehicle.cpp CustomerLinkVehicle.h Person.cpp Person.h SportsCar.cpp SportsCar.h Vehicle.cpp Vehicle.h Bus.cpp)
