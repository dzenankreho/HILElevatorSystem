#include "ServerController.h"
#include "ServerComModule.h"
#include <algorithm>
#include <cmath>
#include <functional>
#ifndef NDEBUG
#include <iostream>
#endif


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

#ifndef NDEBUG
    std::cout << "Server selected elevator with elevator number: " << elevator << std::endl;
#endif

    elevators.at(elevator).get().setBusy(true);
    return elevator;
}


void ServerController::goToFloor(int elevatorNumber, int floorNumber) {
#ifndef NDEBUG
    std::cout << "Elevator with elevator number: " << elevatorNumber
              << " is going to floor: " << floorNumber << std::endl;
#endif
    elevators.at(elevatorNumber).get().setCurrentFloor(floorNumber);
}


void ServerController::freeBusyElevator(int elevatorNumber) {
#ifndef NDEBUG
    std::cout << "Elevator with elevator number: " << elevatorNumber
              << " is freed" << std::endl;
#endif
    elevators.at(elevatorNumber).get().setBusy(false);
}


void ServerController::run() {
    ServerComModule::getAccess().registerFunction("elevatorCalled",
    	[this](const jsonrpcpp::Id& id, const jsonrpcpp::Parameter& params) {
    		return std::make_shared<jsonrpcpp::Response>(id,
    			elevatorCalled(params.get<int>("floorNumber")));
        });

    ServerComModule::getAccess().registerFunction("goToFloor",
    	[this](const jsonrpcpp::Parameter& params) {
    		goToFloor(params.get<int>("elevatorNumber"), params.get<int>("floorNumber"));
        });
      
      
    ServerComModule::getAccess().registerFunction("freeBusyElevator",
    	[this](const jsonrpcpp::Parameter& params) {
    		freeBusyElevator(params.get<int>("elevatorNumber"));
        });
              
    ServerComModule::getAccess().runServer();
}


void ServerController::registerElevator(ElevatorRef elevator) {
    if (elevator.get().getElevatorNumber() != -1) {
        throw std::logic_error("Elevator already has an elevator number!");
    }

    elevator.get().setElevatorNumber(elevators.size());
    elevators.push_back(elevator);
}

