#include <iostream>

int adjustSpeed(int currentSpeed, char option, int acceleration, int decceleration) {
    if (option == 'a') {
        currentSpeed += acceleration;
    }
    else if (option == 'b') {
        if (currentSpeed > 0) {
            currentSpeed -= decceleration;
        }
        else
        {
            currentSpeed = 0;
        }
    }
        return currentSpeed;
}

int main()
{
    int speedKmph{ 0 };
    int accelerationKmph{10};
    int brake{2};
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
        speedKmph = adjustSpeed(speedKmph, option, accelerationKmph, brake);
        std::cout << "The current speed is " << speedKmph << " km/hr" << std::endl;
    }
}


