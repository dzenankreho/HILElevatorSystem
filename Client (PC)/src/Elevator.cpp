#include "Elevator.h"
#include <stdexcept>
#include <iostream>


Elevator::Elevator() : currentFloor{ 0 }, busy{ false }, elevatorNumber{ -1 } {
}


int Elevator::getCurrentFloor() const {
    return currentFloor;
}


int Elevator::getElevatorNumber() const {
    return elevatorNumber;
}


bool operator<(std::reference_wrapper<Elevator> el1, std::reference_wrapper<Elevator> el2) {
    return el1.get().getElevatorNumber() < el2.get().getElevatorNumber();
}


void Elevator::setCurrentFloor(int floorNumber) {
    if (floorNumber < 0) {
        throw std::invalid_argument("Floor number must be >= 0");
    }

    currentFloor = floorNumber;
}


bool Elevator::isBusy() const {
    return busy;
}


void Elevator::setBusy(bool busy) {
    this->busy = busy;
}


void Elevator::setElevatorNumber(int elevatorNumber) {
    if (elevatorNumber < 0) {
        throw std::invalid_argument("Elevator number must be >= 0!");
    }

    this->elevatorNumber = elevatorNumber;
}
