#include "FloorButton.h"


FloorButton::FloorButton(int floorNumber) : Button(floorNumber) {

}


void FloorButton::buttonPressed() {
    emit turnOnBacklight();
    emit notifyController(getFloorNumber());
}
