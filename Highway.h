#pragma once

#include <vector>
#include <algorithm>
#include "HighwayPatrol.h"

struct Vehicle;
struct Highway
{
    void changeSpeed(int newSpeed);
    void addVehicle(Vehicle* v);
    void removeVehicle(Vehicle* v);

    friend struct HighwayPatrol;
private:
    void addVehicleInternal(Vehicle* v);
    void removeVehicleInternal(Vehicle* v);
    int speedLimit = 65;
    std::vector<Vehicle*> vehicles;
};
