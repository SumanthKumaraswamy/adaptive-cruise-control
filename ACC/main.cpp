#include <iostream>
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"

int main()
{
    std::cout << "Select the vehicle: 0-Car, 1-Truck\n";
    int selection{};
    std::cin >> selection;
    Vehicle* vehicle = nullptr;

    if (selection < 0 || selection>1) {
        while ((selection < 0) || (selection > 1)) {
            std::cout << " Enter a valid option: 0-Car, 1-Truck\n";
            std::cin >> selection;
        }
    }
    else if (selection == 0) {
        vehicle = new Car();
    }
    else {
        vehicle = new Truck();
    }

    char option{};

    while (true) {
        std::cout << "Enter the option you would like to choose 'a', 'b' or 'q'\n";
        std::cin >> option;

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
