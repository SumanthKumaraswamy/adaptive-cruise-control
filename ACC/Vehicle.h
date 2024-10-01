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
	double getSpeed() const;

	void setSpeed(double newSpeed);

	double validateInput();

	double getAccelerationIntensity() const;

	void setAccelerationIntensity(double accelerationInput);

	double getBrakeIntensity() const;

	void setBrakeIntensity(double brakeInput);

	virtual void accelerate();

	virtual void brake();

	void displayStatus();
};

