#include<iostream>
#include"Truck.h"

void Truck::accelerate() {
	double accelarationInput{};
	while (true) {
		std::cout << "Enter the acceleration input (press 0 to use default) max:30\n";
		accelarationInput = validateInput();

		if ((accelarationInput > 0) && (accelarationInput <= 30)) {
			setAccelerationIntensity(accelarationInput);
			break;
		}
		else if (accelarationInput > 30) {
			setAccelerationIntensity(30);
			break;
		}
		else if (accelarationInput == 0) {
			setAccelerationIntensity(10);
			break;
		}
		else {
			std::cout << "Enter a valid value\n";
		}
	}

	double speed{ getSpeed() };
	if (getAccelerationIntensity() + speed > 200) {
		setSpeed(200);
		std::cout << "Overspeed...Capped to 200km/hr\n";
	}
	else {
		std::cout << "Truck accelerating...\n";
		speed += getAccelerationIntensity();
		setSpeed(speed);
	}
	setAccelerationIntensity(0);
}


void Truck::brake() {
	double brakeInput{};
	while (true) {
		std::cout << "Enter the brake intensity (press 0 to use default) max:20\n";
		brakeInput = validateInput();

		if (brakeInput > 0 && brakeInput <= 20) {
			setBrakeIntensity(brakeInput);
			break;
		}
		else if (brakeInput > 20) {
			setBrakeIntensity(20);
			break;
		}
		else if (brakeInput == 0) {
			setBrakeIntensity(1);
			break;
		}
		else {
			std::cout << "Enter a valid value\n";
		}
	}

	double speed{ getSpeed() };
	if ((speed - getBrakeIntensity()) > 0) {
		speed -= getBrakeIntensity();
		std::cout << "Truck braking...\n";
		setSpeed(speed);
	}
	else {
		speed = 0;
		std::cout << "Truck is standing still...\n";
		setSpeed(speed);
	}
	setBrakeIntensity(0);
}
