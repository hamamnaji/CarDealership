#pragma once
#include <iostream>
#include <string>
#include "Car.h"
using namespace std;
class OldCar : public Car
{
private:
    string carMileage;

public:
    virtual void print();
    void setCarMileage(string mileage);
    string getCarMileage();

    OldCar(string carMake, string carModel, string carVin, string carPrice, string mileage);
    OldCar();
};

