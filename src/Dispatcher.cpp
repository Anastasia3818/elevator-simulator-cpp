#include "Dispatcher.h"
#include <limits>
#include <iostream>

Dispatcher::Dispatcher(std::vector<Elevator*>& elevators)
{
    this->elevators = elevators;
}

Elevator* Dispatcher::findBestElevator(int floor, Direction direction)
{
    Elevator* best = nullptr;

    int bestDistance = std::numeric_limits<int>::max();

    for(auto elevator : elevators)
    {
        int dist = elevator->distanceTo(floor);

        if(dist < bestDistance)
        {
            bestDistance = dist;
            best = elevator;
        }
    }

    return best;
}

void Dispatcher::handleRequest(const Request& request)
{
    Elevator* best = findBestElevator(
        request.getFloor(),
        request.getDirection()
    );

    if(best)
    {
        std::cout << "[ДИСПЕТЧЕР] "
                  << "Назначен лифт #"
                  << best->getId()
                  << " на этаж "
                  << request.getFloor()
                  << std::endl;

        best->addTarget(request.getFloor());
    }
}