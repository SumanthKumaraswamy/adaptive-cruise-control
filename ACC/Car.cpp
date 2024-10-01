#include<iostream>
#include"Car.h"

void Car::accelerate() {
	double accelerationInput{};
	while (true) {
		std::cout << "Enter the acceleration intensity (press 0 to use default) max:30\n";
		accelerationInput = validateInput();

		if ((accelerationInput > 0) && (accelerationInput <= 30)) {
			setAccelerationIntensity(accelerationInput);
			break;
		}
		else if (accelerationInput > 30) {
			setAccelerationIntensity(30);
			break;
		}
		else if (accelerationInput == 0) {
			setAccelerationIntensity(15);
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
		std::cout << "Car accelerating...\n";
		speed += getAccelerationIntensity();
		setSpeed(speed);
	}
	setAccelerationIntensity(0);
}

void Car::brake() {
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
		std::cout << "Car braking...\n";
		setSpeed(speed);
	}
	else {
		speed = 0;
		std::cout << "Car is standing still...\n";
		setSpeed(speed);
	}
	setBrakeIntensity(0);
}

