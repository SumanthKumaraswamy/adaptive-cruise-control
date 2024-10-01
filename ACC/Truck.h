#pragma once
#include<iostream>
#include"Vehicle.h"

class Truck : public Vehicle {
public:
	void accelerate() override;

	void brake() override;
};