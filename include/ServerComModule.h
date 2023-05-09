#pragma once
#include <rpc/server.h>
#include <string>
#include <functional>


class ServerComModule {
    rpc::server server;

    ServerComModule(uint16_t port);
    static ServerComModule* serverComModule;

public:
    static void initializeComModule();
    static ServerComModule& getAccess();
    ~ServerComModule();
    void runServer();
    template <typename fun> void registerFunction(const std::string& name,
                                                  std::function<fun> function);
};


template <typename fun> void ServerComModule::registerFunction(const std::string& name,
                                                               std::function<fun> function) {
    server.bind(name, function);
}
