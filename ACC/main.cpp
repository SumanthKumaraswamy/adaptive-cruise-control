#include <iostream>
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"

int main()
{
	int selection{};
	while (true) {
		try {
			std::cout << "Select the vehicle: 0-Car, 1-Truck\n";
			std::cin >> selection;
			if (std::cin.fail()) {
				throw std::invalid_argument("Invalid input. Please enter a number. ");
			}
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}
		break;
	}
	Vehicle* vehicle = nullptr;

	if (selection < 0 || selection>1) {
		while ((selection < 0) || (selection > 1)) {
			std::cout << " Enter a valid option: 0-Car, 1-Truck\n";
			std::cin >> selection;
		}
	}
	if (selection == 0) {
		vehicle = new Car();
	}
	else {
		vehicle = new Truck();
	}

	char option{};
	while (true) {
		try {
			std::cout << "Enter the option you would like to choose 'a', 'b' or 'q'\n";
			std::cin >> option;
			if (std::cin.fail()) {
				throw std::invalid_argument("Invalid input. Please enter a number. ");
			}
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

		if (option == 'q') {
			break;
		}
		else if ((option != 'b') && (option != 'a')) {
			std::cout << "Enter a valid command \n";
			continue;
		}
		else if (option == 'a') {
			vehicle->accelerate();
		}
		else if (option == 'b') {
			vehicle->brake();
		}
		vehicle->displayStatus();
	}
	delete vehicle;
}
