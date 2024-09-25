#pragma once
#include<iostream>

class Vehicle {
private:
    double speedKmph{ 0 };
    int position{ 0 };
    double brakeIntensity{};
    double accelerationIntensity{};
public:

    //getSpeed is made const since it doesn't modify the object(Won't modify any member variables).
    double getSpeed() const{
        return speedKmph;
    }

    void setSpeed(double newSpeed) {
        speedKmph = newSpeed;
    }

    void accelerate() {
        std::cout << "Enter the acceleration intensity \n";
        std::cin >> accelerationIntensity;
        speedKmph += accelerationIntensity;
        std::cout << "Vehicle accelerating...\n";
        accelerationIntensity = 0;
    }

    void brake() {
        std::cout << "Enter the brake intensity \n";
        std::cin >> brakeIntensity;
        if (speedKmph > 0) {
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

    void displayStatus() {
        std::cout << "The current speed is " << speedKmph << " km/hr" << std::endl;
    }
};