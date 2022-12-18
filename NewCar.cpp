#include "NewCar.h"

void NewCar::print()
{
	Car::print();
	cout << "Car Warranty: " << carWarranty << endl;
}

void NewCar::setCarWarranty(string warranty)
{
	carWarranty = warranty;
}

string NewCar::getCarWarranty()
{
	return carWarranty;
}

NewCar::NewCar(string CMake, string CModel, string CVin, string CPrice, string CWarranty) : Car(CMake, CModel, CVin, CPrice)
{
	carWarranty = CWarranty;

}

NewCar::NewCar() : Car()
{
	carWarranty = "0";

}
