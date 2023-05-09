#include "LocalController.h"
#include "ClientComModule.h"
#include <QTimer>
#include <utility>
#include <iostream>
#include <memory>


LocalController::LocalController() {
     ClientComModule::initializeComModule();
     ClientComModule::getAccess().testConnection();
}


void LocalController::registerElevator(ElevatorRef elevator) {
    if (elevator.get().getElevatorNumber() != -1) {
        throw std::logic_error("Elevator already has an elevator number!");
    }

    elevator.get().setElevatorNumber(elevators.size());
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

     QObject::connect(&floorButton.get(), &FloorButton::notifyController, this,
                      &LocalController::floorButtonClicked, Qt::UniqueConnection);
}


void LocalController::registerCallButton(CallButtonRef callButton) {
    if (std::find_if(callButtons.begin(), callButtons.end(), [callButton](const auto& clb) {
            return clb.get().getFloorNumber() == callButton.get().getFloorNumber(); }) != callButtons.end()) {
        throw std::logic_error("Call butten with the same number registered already!");
    }

     callButtons.push_back(callButton);
     QObject::connect(&callButton.get(), &CallButton::notifyController, this,
                      &LocalController::callButtonClicked, Qt::UniqueConnection);
}


void LocalController::callButtonClicked(int floorNumber) {
    Elevator& elevator{ elevators.at(ClientComModule::getAccess().elevatorCalled(floorNumber)).get() };
    elevator.setBusy(true);

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
    FloorButtonRef floorButton{ *dynamic_cast<FloorButton*>(QObject::sender()) };
    int elevatorNumber{ -1 };
    for (const auto& elevAndFlb: floorButtons) {
        elevatorNumber++;
        if (std::find_if(elevAndFlb.second.begin(), elevAndFlb.second.end(),
                         [floorButton](const FloorButtonRef flb) { return std::addressof(flb.get()) ==
                         std::addressof(floorButton.get()); }) != elevAndFlb.second.end()) {
            break;
        }
    }

    ClientComModule::getAccess().goToFloor(elevatorNumber, floorNumber);
    Elevator& elevator{ elevators.at(elevatorNumber).get() };

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
                elevator.setBusy(false);
                ClientComModule::getAccess().freeBusyElevator(elevator.getElevatorNumber());
                emit elevator.closeDoor(floorNumber);
            });
        });
    });
}
