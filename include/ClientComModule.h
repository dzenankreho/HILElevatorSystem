#pragma once
#include <rpc/client.h>
#include <string>
#include <utility>


class ClientComModule {
    rpc::client client;

    ClientComModule(std::string const &, uint16_t);
    static ClientComModule* clientComModule;

public:
    static void initializeComModule();
    static ClientComModule& getAccess();
    int elevatorCalled(int floorNumber);
    std::pair<int, int> goToFloor(int floorNumber);
};
