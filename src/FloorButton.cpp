#include "FloorButton.h"
#include <iostream>
#include <QTimer>

//#include "ClientComModule.h"

FloorButton::FloorButton(int floorNumber) : Button(floorNumber) {

}


void FloorButton::buttonPressed() {
//    std::cout << "Elevator going to floor " << number << std::endl;

    emit turnOnBacklight();
//    QTimer::singleShot(2000, [this]() {
//        ClientComModule::getAccess().goToFloor(number);
//        emit toggleBacklight();
//        std::cout << "Elevator arrived on floor " << number << std::endl;
//    });
}
