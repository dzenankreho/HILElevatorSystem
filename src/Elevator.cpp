#include "Elevator.h"
#include <stdexcept>


Elevator::Elevator(int elevatorNumber) {
    if (elevatorNumber < 1) {
        throw std::invalid_argument("Elevator number must be > 1!");
    }

    this->elevatorNumber = elevatorNumber;
    currentFloor = 0;
}


int Elevator::getCurrentFloor() const {
    return currentFloor;
}


int Elevator::getElevatorNumber() const {
    return elevatorNumber;
}


bool operator<(std::reference_wrapper<Elevator> m1, std::reference_wrapper<Elevator> m2) {
    return m1.get().getElevatorNumber() < m2.get().getElevatorNumber();
}
