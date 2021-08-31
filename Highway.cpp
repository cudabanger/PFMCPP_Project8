#include "Highway.h"

#include <cassert>
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    //assert(false);

    /*
    depending on the derived type, call the member function that doesn't evade the cops. 

    this function should call the non-evasive member function of the derived class
    */
    if ( auto* car = dynamic_cast<Car*>(v))
    {
        car->closeWindows();
    }
    else if ( Motorcycle* bike = dynamic_cast<Motorcycle*>(v))
    {
        // the member function that doesn't evade the cops
        bike->lanesplitAndRace(90);
    }
    else if ( SemiTruck* truck = dynamic_cast<SemiTruck*>(v))
    {
        truck->getOnHighway(speedLimit);
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    //assert(false);

    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
    if ( Car* car = dynamic_cast<Car*>(v))
    {
        v->tryToEvade();
    }
    else if (Motorcycle* bike = dynamic_cast<Motorcycle*>(v))
    {
        bike->tryToEvade();
    }
    else if (SemiTruck* truck = dynamic_cast<SemiTruck*>(v))
    {
        truck->pullOver();
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
