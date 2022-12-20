#include "Car.h"
#include "NewCar.h"
#include "OldCar.h"
#include <vector>
int main()
{

	OldCar* veryoldcar1 = new OldCar("Chevrolet", "Camaro", "1298233021", "$5,000", "95,000");
	OldCar* veryoldcar2 = new OldCar("Ford", "Bronco", "987423321", "$10,000", "22,000");
	OldCar* veryoldcar3 = new OldCar("Toyota", "Camry", "87324902", "$25,000", "5,000");
	OldCar* veryoldcar4 = new OldCar("Dodge", "Camaro", "12983021", "$5,000", "95,000");
	OldCar* veryoldcar5 = new OldCar("Chevrolet", "Charger", "82319732", "$20,000", "32,238");
	NewCar* verynewcar1 = new NewCar("Tesla", "Cybertruck", "39217321", "$52,420", "6");
	NewCar* verynewcar2 = new NewCar("RollsRoyce", "Dawn", "65444356", "$100,000", "3");
	NewCar* verynewcar3 = new NewCar("Nissan", "Altima", "65235234", "$69,000", "2");
	NewCar* verynewcar4 = new NewCar("Maserati", "Ghibli", "57243212", "$120,000", "4");
	NewCar* verynewcar5 = new NewCar("Subaru", "Outback", "66366722", "$80,000", "4");


	vector <Car*> list;
	list.push_back(veryoldcar1);
	list.push_back(veryoldcar2);
	list.push_back(veryoldcar3);
	list.push_back(veryoldcar4);
	list.push_back(veryoldcar5);
	list.push_back(verynewcar1);
	list.push_back(verynewcar2);
	list.push_back(verynewcar3);
	list.push_back(verynewcar4);
	list.push_back(verynewcar5);

	int exit = 0;
	while (exit == 0) {

		int userChoice;
		cout << "\nPlease enter a number to select a option below" << endl;
		cout << "1. Search Inventory." << endl;
		cout << "2. Sell/Lease cars." << endl;
		cout << "3. Return a leased car." << endl;
		cout << "4. Add cars to inventory." << endl;
		cout << "5. Exit\n" << endl;
		cin >> userChoice;

		if (userChoice == 5) {
			exit = 1;
		}


		bool brk = 0;

		if (userChoice == 1) {
			while (brk == 0) {
				int userinpp = 0;
				int userinplock = 1;
				while (userinplock == 1) {
					cout << "\nWhat would you like to search for: " << endl;
					cout << "1. Make." << endl;
					cout << "2. Model." << endl;
					cout << "3. Category." << endl;
					cin >> userinpp;
					if (userinpp == 1 || userinpp == 2 || userinpp == 3) {
						userinplock = 0;
					}
				}

				if (userinpp == 1) {
					string carmakee;
					cout << "\nPlease enter car Make (EX: Nissan): " << endl;
					cin >> carmakee;


					for (int i = 0; i < list.size(); i++) {

						if (i > list.size() - 1) {
							cout << "\nThat is not in the system" << endl;
						}
						else if (list[i]->getCarMake() == carmakee) {

							cout << "Car: \n";
							list[i]->print();
							cout << endl;
						}

					}

				}

				if (userinpp == 2) {
					string carmodell;
					cout << "\nPlease enter car Model (EX: Altima): " << endl;
					cin >> carmodell;


					for (int i = 0; i < list.size(); i++) {

						if (i > list.size() - 1) {
							cout << "\nThat is not in the system" << endl;
						}
						else if (list[i]->getCarModel() == carmodell) {

							cout << "Car: \n";
							list[i]->print();
							cout << endl;
						}
					}

				}

				if (userinpp == 3) {
					string categoryy;
					cout << "\nPlease enter either new or used: " << endl;
					cin >> categoryy;
					for (auto o : list)
					{
						if ("new" == categoryy || "New" == categoryy) {

							if (NewCar* necar = dynamic_cast<NewCar*>(o)) {
								o->print();
								cout << endl;
							}

						}
						else if ("used" == categoryy || "Used" == categoryy) {

							if (OldCar* olcar = dynamic_cast<OldCar*>(o)) {
								o->print();
								cout << endl;
							}


						}
					}
				}
				string yorn;
				cout << "\nWould you like to search for another car? (y/n): ";
				cin >> yorn;
				cout << endl;

				if (yorn == "n" || yorn == "N") {

					brk = 1;
				}


			}
		}


		if (userChoice == 2) {
			int choice;
			int essit = 0;
			while (essit == 0) {
				cout << "\nChoose a vehicle 1 - " << list.size() << endl;
				for (int i = 0; i < list.size(); i++) {
					cout << "Car #" << i + 1 << ": " << endl;
					list[i]->print();
					cout << endl;
				}
				cin >> choice;

				string sellorlease;
				cout << "\nWould you like to sell the car or lease it? (sell/lease):" << endl;
				cin >> sellorlease;

				if (sellorlease == "sell" || sellorlease == "Sell") {

					list.erase(list.begin() + choice - 1);
					cout << "Sold!" << endl;
				}
				else if (list[choice - 1]->getIsLeased() == true) {

					cout << "This car is already being leased!" << endl;

				}
				else if ((sellorlease == "lease" || sellorlease == "Lease")) {
					list[choice - 1]->setIsLeased(true);
					cout << "Car is now being leased." << endl;
				}

				string YORN;
				cout << "\nWould you like to Sell/Lease another car? (y/n): ";
				cin >> YORN;

				if (YORN == "n" || YORN == "N") {

					essit = 1;
				}
			}

		}//exits sell/lease

		if (userChoice == 3) {
			int cary = 0;
			while (cary == 0) {
				cout << "\nWhich leased car would you like to return? (choose #):\n";
				int count = 0;
				for (int i = 0; i < list.size(); i++) {
					count;
					if (list[i]->getIsLeased() == true) {
						cout << "#" << i << " ";
						list[i]->print();
						cout << endl;
						count++;
					}
				}
				if (count == 0) {
					cout << "There is no cars being leased right now" << endl;
				}
				else {
					int carchoice;
					cin >> carchoice;
					list[carchoice]->setIsLeased(0);
				}

				//add would you like to do another one here
				string YON;
				cout << "\nWould you like to return another car? (y/n): ";
				cin >> YON;


				if (YON == "n" || YON == "N") {

					cary = 1;
				}


			}

		}// break out of return leased cars


		if (userChoice == 4) {
			string NOO;
			int veri = 0;
			while (veri == 0) {
				cout << "\nWould you like to add a used or new car? (used/new): ";
				cin >> NOO;

				if (NOO == "new" || NOO == "New") {
					string warranty1;
					string make1;
					string model1;
					string vin1;
					string price1;
					cout << "\nEnter warrenty in years (EX:5): ";
					cin >> warranty1;
					cout << "\nEnter make of car: ";
					cin >> make1;
					cout << "\nEnter model of car: ";
					cin >> model1;
					cout << "\nEnter vin of car: ";
					cin >> vin1;
					cout << "\nEnter price of car(EX:$100): ";
					cin >> price1;

					NewCar* newcarr = new NewCar(make1, model1, vin1, price1, warranty1);
					list.push_back(newcarr);
				}
				else if (NOO == "used" || NOO == "Used") {
					string mileage;
					string make;
					string model;
					string vin;
					string price;
					cout << "\nEnter car mileage: ";
					cin >> mileage;
					cout << "\nEnter make of car: ";
					cin >> make;
					cout << "\nEnter model of car: ";
					cin >> model;
					cout << "\nEnter vin of car: ";
					cin >> vin;
					cout << "\nEnter price of car(EX:$100): ";
					cin >> price;

					OldCar* oldcarrr = new OldCar(make, model, vin, price, mileage);
					list.push_back(oldcarrr);
				}

				string YOON;
				cout << "\nWould you like to add another car? (y/n): ";
				cin >> YOON;


				if (YOON == "n" || YOON == "N") {

					veri = 1;
				}
			}

		}

	} // Main while loop


}//int main()

