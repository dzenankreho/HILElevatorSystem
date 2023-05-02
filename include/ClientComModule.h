#pragma once
#include <rpc/client.h>
#include <string>


class ClientComModule {
    rpc::client client;


    ClientComModule(std::string const &, uint16_t);
    static ClientComModule* clientComModule;

public:
    static void initializeComModule();
    static ClientComModule& getAccess();
};
