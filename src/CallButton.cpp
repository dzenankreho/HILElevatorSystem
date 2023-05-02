#include "CallButton.h"
#include <iostream>
#include <QTimer>


CallButton::CallButton(int floorNumber) : Button(floorNumber) {

}


void CallButton::buttonPressed() {
//    std::cout << "Elevator called on floor " << floorNumber << std::endl;

    emit turnOnBacklight();
    emit notifyController(getFloorNumber());
//    QTimer::singleShot(2000, [this]() {
//        ClientComModule::getAccess().callElevator(floorNumber);
//        emit toggleBacklight();
//        std::cout << "Elevator arrived on floor " << floorNumber << std::endl;
//    });
}
