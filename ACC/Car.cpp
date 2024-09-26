#include<iostream>
#include"Car.h"

    void Car::accelerate()  {
        std::cout << "Enter the acceleration intensity (press 0 to use default) \n";
        double accelarationInput{};
        std::cin >> accelarationInput;
        std::cout << "Car accelerating...\n";
        if (accelarationInput > 0) {
            setAccelerationIntensity(accelarationInput);
        }
        else {
            setAccelerationIntensity(15);
        }
        double speed{ getSpeed() };
        speed += getAccelerationIntensity();
        setSpeed(speed);
        setAccelerationIntensity(0);
    }

    void Car::brake(){
        std::cout << "Enter the brake intensity (press 0 to use default)\n";
        double brakeInput{};
        std::cin >> brakeInput;
        if (brakeInput > 0) {
            setBrakeIntensity(brakeInput);
        }
        else {
            setBrakeIntensity(5);
        }
        double speed{ getSpeed() };
        if ((speed - getBrakeIntensity()) > 0) {
            speed -= getBrakeIntensity();
            setSpeed(speed);
            std::cout << "Car braking...\n";
        }
        else
        {
            setSpeed(0);
            std::cout << "Car is standing still...\n";
        }
        brakeInput = 0;
    }
