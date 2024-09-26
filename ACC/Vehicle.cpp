#include <iostream>
#include"Vehicle.h"

//getSpeed is made const since it doesn't modify the object(Won't modify any member variables).
double Vehicle::getSpeed() const {
    return speedKmph;
}

void Vehicle::setSpeed(double newSpeed) {
    speedKmph = newSpeed;
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
    std::cout << "Enter the acceleration intensity \n";
    std::cin >> accelerationIntensity;
    speedKmph += accelerationIntensity;
    std::cout << "Vehicle accelerating...\n";
    accelerationIntensity = 0;
}

void Vehicle::brake() {
    std::cout << "Enter the brake intensity \n";
    std::cin >> brakeIntensity;
    if ((speedKmph - brakeIntensity) > 0) {
        speedKmph -= brakeIntensity;
        std::cout << "Vehicle braking...\n";
    }
    else
    {
        speedKmph = 0;
        std::cout << "Vehicle is standing still...\n";
    }
    brakeIntensity = 0;
}

void Vehicle::displayStatus() {
    std::cout << "The current speed is " << speedKmph << " km/hr" << std::endl;
}