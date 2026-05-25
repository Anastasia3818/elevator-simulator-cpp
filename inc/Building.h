#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Elevator.h"
#include "Dispatcher.h"

class Building
{
private:
    std::vector<Elevator*> elevators;
    Dispatcher* dispatcher;

public:
    Building(int elevatorCount);

    ~Building();

    void callElevator(int floor, Direction direction);

    void stepSimulation();

    void printStatus() const;
};

#endif