#include <iostream>
#include "Building.h"
#include "Utils.h"

int main()
{
    setlocale(LC_ALL, "RU");

    Building building(3);

    building.callElevator(7, Direction::UP);
    building.callElevator(2, Direction::DOWN);
    building.callElevator(10, Direction::DOWN);

    for(int i = 0; i < 20; i++)
    {
        building.printStatus();

        building.stepSimulation();

        delay(1000);
    }

    return 0;
}