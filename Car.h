#pragma once
#include <iostream>
#include <string>
using namespace std;



class Car
{
private:
	string carVin;
	string carMake;
	string carModel;
	string carPrice;
	bool carLease;

public:
	virtual void print();
	string getCarVin();
	string getCarMake();
	string getCarModel();
	string getCarPrice();


	void setCarModel(string model);
	void setCarVin(string vin);
	void setCarMake(string make);
	void setCarPrice(string price);

	bool getIsLeased();
	void setIsLeased(bool isit);



	Car();
	Car(string, string carModel, string carVin, string carPrice);
};
