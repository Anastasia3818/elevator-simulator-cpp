#include "Request.h"

Request::Request(int floor, Direction direction)
{
    this->floor = floor;
    this->direction = direction;
}

int Request::getFloor() const
{
    return floor;
}

Direction Request::getDirection() const
{
    return direction;
}