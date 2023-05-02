#include "LocalController.h"
#include "ClientComModule.h"


LocalController::LocalController() {
     ClientComModule::initializeComModule();
}


void LocalController::registerElevator(ElevatorRef elevator) {
    if (std::find_if(elevators.begin(), elevators.end(), [elevator](const auto& elev) {
                     return elev.get().getElevatorNumber() == elevator.get().getElevatorNumber(); }) != elevators.end()) {
        throw std::logic_error("Elevator with the same elevator number registered already!");
    }

     elevators.push_back(elevator);
}


void LocalController::registerFloorButton(ElevatorRef elevator, FloorButtonRef floorButton) {
    try {
        auto& elevatorFloorButtons{ floorButtons.at(elevator) };

        if (std::find_if(elevatorFloorButtons.begin(), elevatorFloorButtons.end(), [floorButton](const auto& flb) {
                return flb.get().getFloorNumber() == floorButton.get().getFloorNumber(); }) != elevatorFloorButtons.end()) {
            throw std::logic_error("Floor button with the same number registered already on this elevator!");
        }

        elevatorFloorButtons.push_back(floorButton);
    } catch(std::out_of_range) {
        floorButtons[elevator].push_back(floorButton);
    }
}


void LocalController::registerCallButton(CallButtonRef callButton) {
    if (std::find_if(callButtons.begin(), callButtons.end(), [callButton](const auto& clb) {
            return clb.get().getFloorNumber() == callButton.get().getFloorNumber(); }) != callButtons.end()) {
        throw std::logic_error("Call butten with the same number registered already!");
    }

     callButtons.push_back(callButton);
     QObject::connect(&callButton.get(), &CallButton::notifyController, this, &LocalController::callButtonClicked);
}


void LocalController::callButtonClicked(int floorNumber) {
    emit elevators.at(0).get().openDoor(floorNumber);
}
