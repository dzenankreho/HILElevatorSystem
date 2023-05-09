#pragma once
#include <rpc/client.h>
#include <string>


class ClientComModule {
    rpc::client client;

    ClientComModule(std::string const &addr, uint16_t port);
    static ClientComModule* clientComModule;

public:
    bool testConnection();
    static void initializeComModule();
    static ClientComModule& getAccess();
    int elevatorCalled(int floorNumber);
    void freeBusyElevator(int elevatorNumber);
    void goToFloor(int elevatorNumber, int floorNumber);
    ~ClientComModule();
};
