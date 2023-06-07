#pragma once
#include <serialib.h>
#include <string>


class ClientComModule {
    serialib serialPort;

    ClientComModule(std::string const &devicePort, unsigned int baudRate);
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
