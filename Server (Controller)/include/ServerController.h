#pragma once
#include "Elevator.h"
#include <vector>
#include <utility>


class ServerController {
    using ElevatorRef = std::reference_wrapper<Elevator>;

    std::vector<ElevatorRef> elevators;

    int elevatorCalled(int floorNumber);
    void goToFloor(int elevatorNumber, int floorNumber);
    void freeBusyElevator(int elevatorNumber);
public:
    ServerController();
    void registerElevator(ElevatorRef elevator);
    void run();
};
