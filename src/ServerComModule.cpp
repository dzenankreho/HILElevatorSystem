#include "ServerComModule.h"
#include <algorithm>
#include <stdexcept>
#ifndef NDEBUG
#include <iostream>
#endif


ServerComModule* ServerComModule::serverComModule{};


ServerComModule::ServerComModule(uint16_t port) : server(port) {
    server.bind("testConnection", [](){ return true; });
}


ServerComModule& ServerComModule::getAccess() {
    return *serverComModule;
}


void ServerComModule::initializeComModule() {
    if (serverComModule == nullptr) {
        serverComModule = new ServerComModule(8080);
    } else {
        throw std::logic_error("Communication module already initialized!");
    }
}


ServerComModule::~ServerComModule() {
    delete serverComModule;
}


void ServerComModule::runServer() {
    server.run();
}
