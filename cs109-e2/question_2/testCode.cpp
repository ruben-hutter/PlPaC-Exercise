#include "DynamicArray.h"
#include <string>
#include <iostream>

class Owner
{
    public:
        std::string name;
};

class Car
{
    private:
        int num_wheels;
        Owner person;

    public:

        void setNumWheels(int numWheels);
        int getNumWheels();
        void setName(std::string name);
        std::string getName();
};

void Car::setNumWheels(int numWheels)
{
    this->num_wheels = numWheels;
}

int Car::getNumWheels()
{
    return num_wheels;
}

void Car::setName(std::string name)
{
    this->person.name = name;
}

std::string Car::getName()
{
    return person.name;
}

int main()
{
    Car car1;
    car1.setNumWheels(5);
    car1.setName("ruben");
    std::cout << car1.getName() << std::endl;
}