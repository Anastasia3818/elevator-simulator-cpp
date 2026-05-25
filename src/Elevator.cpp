#include "Elevator.h"
#include <iostream>
#include <algorithm>

Elevator::Elevator(int id)
{
    this->id = id;
    currentFloor = 1;
    direction = Direction::IDLE;
    moving = false;
}

void Elevator::addTarget(int floor)
{
    if(std::find(targets.begin(), targets.end(), floor) == targets.end())
    {
        targets.push_back(floor);
    }
}

bool Elevator::isIdle() const
{
    return targets.empty();
}

int Elevator::getCurrentFloor() const
{
    return currentFloor;
}

Direction Elevator::getDirection() const
{
    return direction;
}

int Elevator::getId() const
{
    return id;
}

int Elevator::distanceTo(int floor) const
{
    return abs(currentFloor - floor);
}

void Elevator::step()
{
    if(targets.empty())
    {
        direction = Direction::IDLE;
        moving = false;
        return;
    }

    moving = true;

    int target = targets.front();

    if(currentFloor < target)
    {
        direction = Direction::UP;
        currentFloor++;
    }
    else if(currentFloor > target)
    {
        direction = Direction::DOWN;
        currentFloor--;
    }
    else
    {
        std::cout << "[ЛИФТ " << id << "] "
                  << "Прибыл на этаж "
                  << currentFloor << std::endl;

        targets.erase(targets.begin());

        if(targets.empty())
        {
            direction = Direction::IDLE;
            moving = false;
        }
    }
}

void Elevator::printStatus() const
{
    std::cout << "Лифт #" << id
              << " | Этаж: " << currentFloor
              << " | ";

    switch(direction)
    {
        case Direction::UP:
            std::cout << "ВВЕРХ";
            break;

        case Direction::DOWN:
            std::cout << "ВНИЗ";
            break;

        case Direction::IDLE:
            std::cout << "ОЖИДАНИЕ";
            break;
    }

    std::cout << std::endl;
}