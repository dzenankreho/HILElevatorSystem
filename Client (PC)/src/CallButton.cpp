#include "CallButton.h"
#ifndef NDEBUG
#include <iostream>
#endif


bool CallButton::areElevatorsFree{ false };


CallButton::CallButton(int floorNumber) : Button(floorNumber) {

}


void CallButton::buttonPressed() {
    emit checkForFreeElevators();
    if (!areElevatorsFree) {
        return;
    }

#ifndef NDEBUG
    std::cout << "Call button pressed on floor: " << getFloorNumber() << std::endl;
#endif
    emit turnOnBacklight();
    emit notifyController(getFloorNumber());
}


void CallButton::setAreElevatorsFree(bool areElevatorsFree) {
    CallButton::areElevatorsFree = areElevatorsFree;
}
