#pragma once
#include <functional>


class Elevator {
    int currentFloor;
    int elevatorNumber;
    bool busy;

public:
    Elevator();
    int getCurrentFloor() const;
    int getElevatorNumber() const;
    friend bool operator<(std::reference_wrapper<Elevator> el1, std::reference_wrapper<Elevator> el2);
    void setCurrentFloor(int floorNumber);
    void setElevatorNumber(int elevatorNumber);
    bool isBusy() const;
    void setBusy(bool busy);
};

bool operator<(std::reference_wrapper<Elevator> el1, std::reference_wrapper<Elevator> el2);
