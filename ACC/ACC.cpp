#include <iostream>
#include"ACC.h"

int main()
{
    Vehicle vehicle;
    char option{};
 
    while (true) {
        std::cout << "Enter the option you would like to choose 'a', 'b' or 'q'\n";
        std::cin >> option;

        if (option == 'q') {
            break;
        }
        else if((option != 'b') && (option != 'a')){
            std::cout << "Enter a valid command \n";
            continue;
        }
        else if (option == 'a') {
            vehicle.accelerate();
        }
        else if (option == 'b') {
            vehicle.brake();
        }
        vehicle.displayStatus();
    }
}


