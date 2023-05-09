#include "ClientComModule.h"
#include <algorithm>
#include <stdexcept>


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
    return client.call("elevatorCalled", floorNumber).as<int>();
}


void ClientComModule::goToFloor(int elevatorNumber, int floorNumber) {
    client.call("goToFloor", elevatorNumber, floorNumber);
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
     client.call("freeBusyElevator", elevatorNumber);
}
