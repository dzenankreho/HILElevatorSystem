#include "ServerController.h"
#include "ServerComModule.h"
#include <algorithm>
#include <cmath>
#include <functional>


ServerController::ServerController() {
    ServerComModule::initializeComModule();
}


int ServerController::elevatorCalled(int floorNumber) {
    int elevator{};
    while (elevators.at(elevator).get().isBusy()) {
        elevator++;
    }

    for (int i{elevator}; i < elevators.size(); i++) {
        const Elevator& el{ elevators.at(i).get() };
        if (!el.isBusy() && std::abs(el.getCurrentFloor() - floorNumber)
                < std::abs(elevators.at(elevator).get().getCurrentFloor() - floorNumber)) {
            elevator = i;
        }
    }

    elevators.at(elevator).get().setBusy(true);
    return elevator;
}


void ServerController::goToFloor(int elevatorNumber, int floorNumber) {
    elevators.at(elevatorNumber).get().setCurrentFloor(floorNumber);
}


void ServerController::freeBusyElevator(int elevatorNumber) {
    elevators.at(elevatorNumber).get().setBusy(false);
}


void ServerController::run() {
    ServerComModule::getAccess().registerFunction<int(int)>
            ("elevatorCalled", [this](int floorNumber) { return elevatorCalled(floorNumber); });

    ServerComModule::getAccess().registerFunction<void(int, int)>
            ("goToFloor", [this](int floorNumber, int elevatorNumber) { goToFloor(elevatorNumber, floorNumber); });

    ServerComModule::getAccess().registerFunction<void(int)>
            ("freeBusyElevator", [this](int elevatorNumber) { return freeBusyElevator(elevatorNumber); });

    ServerComModule::getAccess().runServer();
}


void ServerController::registerElevator(ElevatorRef elevator) {
    if (elevator.get().getElevatorNumber() != -1) {
        throw std::logic_error("Elevator already has an elevator number!");
    }

    elevator.get().setElevatorNumber(elevators.size());
    elevators.push_back(elevator);
}
