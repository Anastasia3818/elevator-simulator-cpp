#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <string>
#include "Request.h"

class Elevator
{
private:
    int id;
    int currentFloor;
    Direction direction;
    bool moving;

    std::vector<int> targets;

public:
    Elevator(int id);

    void addTarget(int floor);

    void step();

    bool isIdle() const;

    int getCurrentFloor() const;

    Direction getDirection() const;

    int getId() const;

    int distanceTo(int floor) const;

    void printStatus() const;
};

#endif