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


std::pair<int, int> ClientComModule::goToFloor(int floorNumber) {
    return client.call("goToFloor", floorNumber).as<std::pair<int, int>>();
}
