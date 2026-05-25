#ifndef REQUEST_H
#define REQUEST_H

enum class Direction
{
    UP,
    DOWN,
    IDLE
};

class Request
{
private:
    int floor;
    Direction direction;

public:
    Request(int floor, Direction direction);

    int getFloor() const;
    Direction getDirection() const;
};

#endif