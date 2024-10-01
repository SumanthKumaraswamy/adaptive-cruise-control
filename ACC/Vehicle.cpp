#include <iostream>
#include"Vehicle.h"

//getSpeed is made const since it doesn't modify the object(Won't modify any member variables).
double Vehicle::getSpeed() const {
	return speedKmph;
}

void Vehicle::setSpeed(double newSpeed) {
	speedKmph = newSpeed;
}

double Vehicle::validateInput() {
	double input{};
	while (true) {
		try {
			std::cin >> input;
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
	return input;
}

double Vehicle::getAccelerationIntensity() const {
	return accelerationIntensity;
}

void Vehicle::setAccelerationIntensity(double accelerationInput) {
	accelerationIntensity = accelerationInput;
}

double Vehicle::getBrakeIntensity() const {
	return brakeIntensity;
}

void Vehicle::setBrakeIntensity(double brakeInput) {
	brakeIntensity = brakeInput;
}

void Vehicle::accelerate() {
	while (true) {
		std::cout << "Enter the acceleration input\n";
		std::cin >> accelerationIntensity;
		if (accelerationIntensity > 30) {
			accelerationIntensity = 30;
			speedKmph += 30;
			std::cout << "Vehicle accelerating...\n";
			break;
		}
		if (accelerationIntensity >= 0 && accelerationIntensity <= 30) {
			speedKmph += accelerationIntensity;
			std::cout << "Vehicle accelerating...\n";
			break;
		}
		else {
			std::cout << "Enter a valid value\n";
		}
	}
	accelerationIntensity = 0;
}

void Vehicle::brake() {

	while (true) {
		try {
			std::cout << "Enter the brake intensity\n";
			std::cin >> brakeIntensity;
			if (std::cin.fail()) {
				throw std::invalid_argument("Invalid input. Please enter a number. ");
			}
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '/n');
			continue;
		}

		if (brakeIntensity < 0) {
			std::cout << "Enter a valid value\n";
			continue;
		}
		break;
	}
	if ((speedKmph - brakeIntensity) > 0) {
		if (brakeIntensity >= 0 && brakeIntensity <= 20) {
			speedKmph -= brakeIntensity;
			std::cout << "Vehicle braking...\n";
		}
		else {
			speedKmph -= 20;
		}
	}
	else {
		speedKmph = 0;
		std::cout << "Vehicle is standing still...\n";
	}
	brakeIntensity = 0;
}

void Vehicle::displayStatus() {
	std::cout << "The current speed is " << speedKmph << " km/hr" << std::endl;
}