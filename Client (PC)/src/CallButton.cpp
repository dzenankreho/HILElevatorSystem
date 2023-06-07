#include "CallButton.h"
#ifndef NDEBUG
#include <iostream>
#endif


CallButton::CallButton(int floorNumber) : Button(floorNumber) {

}


void CallButton::buttonPressed() {
#ifndef NDEBUG
    std::cout << "Call button pressed on floor: " << getFloorNumber() << std::endl;
#endif
    emit turnOnBacklight();
    emit notifyController(getFloorNumber());
}
