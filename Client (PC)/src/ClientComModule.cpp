#include "ClientComModule.h"
#include <algorithm>
#include <stdexcept>
#include "jsonrpcpp.hpp"
#ifndef NDEBUG
#include <iostream>
#endif
#if defined (_WIN32) || defined(_WIN64)
    #define SERIAL_PORT "\\\\.\\COM5"
#endif
#if defined (__linux__)
    #define SERIAL_PORT "/dev/ttyACM0"
#endif
#define MAX_BUFFER_SIZE 100


ClientComModule* ClientComModule::clientComModule{};


ClientComModule::ClientComModule(std::string const &devicePort, unsigned int baudRate) {
    char errorOpening = serialPort.openDevice(devicePort.c_str(), baudRate);

    if (errorOpening != 1) {
        throw std::runtime_error("Unable to open serial prot!");
    }
}


ClientComModule& ClientComModule::getAccess() {
    return *clientComModule;
}


void ClientComModule::initializeComModule() {
    if (clientComModule == nullptr) {
        clientComModule = new ClientComModule(SERIAL_PORT, 9600);
    } else {
        throw std::logic_error("Communication module already initialized!");
    }
}


int ClientComModule::elevatorCalled(int floorNumber) {
#ifndef NDEBUG
    std::cout << "elevatorCalled called from client com. module with floor number: "
              << floorNumber << std::endl;
#endif

    serialPort.writeString((jsonrpcpp::Request
                           (1, "elevatorCalled", Json({{"floorNumber", floorNumber}}))
                           .to_json().dump() + std::string("\n")).c_str());

    char buffer[MAX_BUFFER_SIZE];
    serialPort.readString(buffer, '\n', MAX_BUFFER_SIZE, 1000);

    return std::dynamic_pointer_cast<jsonrpcpp::Response>
            (jsonrpcpp::Parser::do_parse(buffer))->result().get<int>();
}


void ClientComModule::goToFloor(int elevatorNumber, int floorNumber) {
#ifndef NDEBUG
    std::cout << "goToFloor called from client com. module with elevator number: "
              << elevatorNumber << " and floor number: " << floorNumber << std::endl;
#endif
    serialPort.writeString((jsonrpcpp::Notification("goToFloor",
                           Json({{"floorNumber", floorNumber}, {"elevatorNumber", elevatorNumber}}))
                           .to_json().dump() + std::string("\n")).c_str());
}


ClientComModule::~ClientComModule() {
    serialPort.closeDevice();
    delete clientComModule;
}


bool ClientComModule::testConnection() {
    if (clientComModule == nullptr) {
        throw std::logic_error("Communication module not initialized!");
    }

    serialPort.writeString((jsonrpcpp::Request(1, "testConnection")
                            .to_json().dump() + std::string("\n")).c_str());

    char buffer[MAX_BUFFER_SIZE];
    if (serialPort.readString(buffer, '\n', MAX_BUFFER_SIZE, 1000) <= 0) {
        throw std::runtime_error("Connection could not be established!");
    }

    if (!std::dynamic_pointer_cast<jsonrpcpp::Response>
            (jsonrpcpp::Parser::do_parse(buffer))->result().get<bool>()) {
        throw std::runtime_error("Connection could not be established!");
    }

    return true;
}


void ClientComModule::freeBusyElevator(int elevatorNumber) {
#ifndef NDEBUG
    std::cout << "freeBusyElevator called from client com. module with elevator number: "
              << elevatorNumber << std::endl;
#endif
    serialPort.writeString((jsonrpcpp::Notification("freeBusyElevator",
                           Json({{"elevatorNumber", elevatorNumber}}))
                           .to_json().dump() + std::string("\n")).c_str());
}
