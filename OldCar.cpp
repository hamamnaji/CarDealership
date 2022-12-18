#include "OldCar.h"

void OldCar::print()
{
	Car::print();
	cout << "Car Mileage: " << carMileage << endl;
}

void OldCar::setCarMileage(string mileage)
{
	carMileage = mileage;
}

string OldCar::getCarMileage()
{
	return carMileage;
}

OldCar::OldCar(string carMake, string carModel, string carVin, string carPrice, string mileage) : Car(carMake, carModel, carVin, carPrice)
{
	carMileage = mileage;
}

OldCar::OldCar() : Car()
{
	carMileage = "Not Assigned";
}
