#include "LocalController.h"
#include "ClientComModule.h"
#include <QTimer>
#include <utility>
#include <iostream>


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

     QObject::connect(&floorButton.get(), &FloorButton::notifyController, this, &LocalController::floorButtonClicked);
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
    Elevator& elevator{ elevators.at(ClientComModule::getAccess().elevatorCalled(floorNumber)).get() };


    QTimer::singleShot(std::abs(elevator.getCurrentFloor() - floorNumber) * 1000,
        [&elevator, floorNumber, this]() {
        elevator.setCurrentFloor(floorNumber);

        emit std::find_if(callButtons.begin(), callButtons.end(), [floorNumber](const auto& clb) {
            return clb.get().getFloorNumber() == floorNumber; })->get().turnOffBacklight();

        emit elevator.openDoor(floorNumber);

        emit elevator.enableElevatorButtons();
    });
}


void LocalController::floorButtonClicked(int floorNumber) {
    std::pair<int, int> elevatorAndFloor{ ClientComModule::getAccess().goToFloor(floorNumber) };
    Elevator& elevator{ elevators.at(elevatorAndFloor.first).get() };

    std::cout << "Ovdje " << elevatorAndFloor.first << " " << elevatorAndFloor.second << std::endl;

    QTimer::singleShot(1000, [&elevator, floorNumber, this]() {
        emit std::find_if(floorButtons.at(elevator).begin(), floorButtons.at(elevator).end(),[floorNumber](const auto& flb) {
            return flb.get().getFloorNumber() == floorNumber; })->get().turnOffBacklight();

        emit elevator.closeDoor(elevator.getCurrentFloor());

        emit elevator.disableElevatorButtons();

        QTimer::singleShot(std::abs(elevator.getCurrentFloor() - floorNumber) * 1000,
            [&elevator, floorNumber]() {

            elevator.setCurrentFloor(floorNumber);

            emit elevator.openDoor(floorNumber);

            QTimer::singleShot(1000, [&elevator, floorNumber]() {
                emit elevator.closeDoor(floorNumber);
            });
        });
    });
}
