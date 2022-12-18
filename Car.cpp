#include "Car.h"

void Car::print()
{
	cout << "Car Make: " << carMake << endl;
	cout << "Car Model: " << carModel << endl;
	cout << "Car Vin: " << carVin << endl;
	cout << "Car Price: " << carPrice << endl;
}

string Car::getCarVin()
{
	return carVin;
}

string Car::getCarMake()
{
	return carMake;
}

string Car::getCarModel()
{
	return carModel;
}

void Car::setCarVin(string vin)
{
	carVin = vin;
}

void Car::setCarMake(string make)
{
	carMake = make;
}

void Car::setCarModel(string model)
{
	carModel = model;
}


string Car::getCarPrice()
{
	return carPrice;
}

void Car::setCarPrice(string price)
{
	carPrice = price;
}

bool Car::getIsLeased()
{
	return carLease;
}

void Car::setIsLeased(bool isit)
{
	carLease = isit;
}



Car::Car()
{
	carMake = "Not Assigned";
	carModel = "Not Assigned";
	carVin = "Not Assigned";
	carPrice = "Not Assigned";
}

Car::Car(string CMake, string CModel, string CVin, string CPrice)
{
	carMake = CMake;
	carModel = CModel;
	carVin = CVin;
	carPrice = CPrice;

}