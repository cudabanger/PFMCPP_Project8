#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

// I need one out-of-line virtual function definition to avoid weak vtables warning
SemiTruck::~SemiTruck()
{

}

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << ": hello officer, what seems to be the problem?" << std::endl;
}

void SemiTruck::getOnHighway(int speed)
{
    Vehicle::setSpeed(speed);    
}
