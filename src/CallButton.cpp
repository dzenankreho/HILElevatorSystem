#include "CallButton.h"


CallButton::CallButton(int floorNumber) : Button(floorNumber) {

}


void CallButton::buttonPressed() {
    emit turnOnBacklight();
    emit notifyController(getFloorNumber());
}
