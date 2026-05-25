#include "Building.h"
#include <iostream>

Building::Building(int elevatorCount)
{
    for(int i = 0; i < elevatorCount; i++)
    {
        elevators.push_back(new Elevator(i + 1));
    }

    dispatcher = new Dispatcher(elevators);
}

Building::~Building()
{
    for(auto elevator : elevators)
    {
        delete elevator;
    }

    delete dispatcher;
}

void Building::callElevator(int floor, Direction direction)
{
    Request request(floor, direction);

    dispatcher->handleRequest(request);
}

void Building::stepSimulation()
{
    for(auto elevator : elevators)
    {
        elevator->step();
    }
}

void Building::printStatus() const
{
    std::cout << "\n======= СОСТОЯНИЕ ЛИФТОВ =======\n";

    for(auto elevator : elevators)
    {
        elevator->printStatus();
    }

    std::cout << "================================\n";
}