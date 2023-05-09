#include "ClientComModule.h"
#include <algorithm>
#include <stdexcept>
#ifndef NDEBUG
#include <iostream>
#endif


ClientComModule* ClientComModule::clientComModule{};


ClientComModule::ClientComModule(std::string const &addr, uint16_t port) : client(addr, port) {

}


ClientComModule& ClientComModule::getAccess() {
    return *clientComModule;
}


void ClientComModule::initializeComModule() {
    if (clientComModule == nullptr) {
        clientComModule = new ClientComModule("localhost", 8080);
    } else {
        throw std::logic_error("Communication module already initialized!");
    }
}


int ClientComModule::elevatorCalled(int floorNumber) {
#ifndef NDEBUG
    std::cout << "elevatorCalled called from client com. module with floor number: "
              << floorNumber << std::endl;
#endif
    return client.call("elevatorCalled", floorNumber).as<int>();
}


void ClientComModule::goToFloor(int elevatorNumber, int floorNumber) {
#ifndef NDEBUG
    std::cout << "goToFloor called from client com. module with elevator number: "
              << elevatorNumber << " and floor number: " << floorNumber << std::endl;
#endif
    client.call("goToFloor", floorNumber, elevatorNumber);
}


ClientComModule::~ClientComModule() {
    delete clientComModule;
}


bool ClientComModule::testConnection() {
    if (clientComModule == nullptr) {
        throw std::logic_error("Communication module not initialized!");
    }

    try {
        return client.call("testConnection").as<bool>();
    } catch(...) {
        throw std::runtime_error("Connection could not be established!");
    }
}


void ClientComModule::freeBusyElevator(int elevatorNumber) {
#ifndef NDEBUG
    std::cout << "freeBusyElevator called from client com. module with elevator number: "
              << elevatorNumber << std::endl;
#endif
     client.call("freeBusyElevator", elevatorNumber);
}
