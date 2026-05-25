#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <vector>
#include "Elevator.h"
#include "Request.h"

class Dispatcher
{
private:
    std::vector<Elevator*> elevators;

public:
    Dispatcher(std::vector<Elevator*>& elevators);

    void handleRequest(const Request& request);

    Elevator* findBestElevator(int floor, Direction direction);
};

#endif