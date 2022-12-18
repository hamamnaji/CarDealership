#pragma once
#include <string>
#include <iostream>
#include "Car.h"
using namespace std;

class NewCar : public Car
{
private:
    string carWarranty;

public:

    virtual void print();
    void setCarWarranty(string warranty);
    string getCarWarranty();

    NewCar(string CMake, string CModel, string CVin, string CPrice, string CWarranty);
    NewCar();

};