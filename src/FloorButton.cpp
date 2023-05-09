#include "FloorButton.h"
#ifndef NDEBUG
#include <iostream>
#endif


FloorButton::FloorButton(int floorNumber) : Button(floorNumber) {

}


void FloorButton::buttonPressed() {
#ifndef NDEBUG
    std::cout << "Floor button pressed to go on floor: " << getFloorNumber() << std::endl;
#endif
    emit turnOnBacklight();
    emit notifyController(getFloorNumber());
}
