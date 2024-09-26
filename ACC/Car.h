#pragma once
#include<iostream>
#include"Vehicle.h"

class Car : public Vehicle {
public:
    void accelerate() override;

    void brake() override;
};