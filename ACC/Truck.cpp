#include<iostream>
#include"Truck.h"

    void Truck::accelerate(){
        std::cout << "Enter the acceleration intensity (press 0 to use default) \n";
        double accelarationInput{};
        std::cin >> accelarationInput;
        std::cout << "Truck accelerating...\n";
        if (accelarationInput > 0) {
            setAccelerationIntensity(accelarationInput);
        }
        else {
            setAccelerationIntensity(10);
        }
        double speed{ getSpeed() };
        speed += getAccelerationIntensity();
        setSpeed(speed);
        setAccelerationIntensity(0);
    }


    void Truck::brake(){
        std::cout << "Enter the brake intensity (press 0 to use default) \n";
        double brakeInput{};
        std::cin >> brakeInput;
        if (brakeInput > 0) {
            setBrakeIntensity(brakeInput);
        }
        else {
            setBrakeIntensity(1);
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
