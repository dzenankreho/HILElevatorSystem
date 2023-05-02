#pragma once
#include "Elevator.h"
#include "FloorButton.h"
#include "CallButton.h"

#include <rpc/client.h>
#include <vector>
#include <string>
#include <functional>
#include <map>


class ClientComModule {
    using ElevatorRef = std::reference_wrapper<Elevator>;
    using FloorButtonRef = std::reference_wrapper<FloorButton>;
    using CallButtonRef = std::reference_wrapper<CallButton>;

    rpc::client client;
    std::vector<ElevatorRef> elevators;
    std::map<ElevatorRef, std::vector<FloorButtonRef>> floorButtons;
    std::vector<CallButtonRef> callButtons;

    ClientComModule(std::string const &, uint16_t);
    static ClientComModule* clientComModule;

    template <typename Container, typename Ref, typename RefNumFun>
    bool isNumberUnique(Container cont, Ref ref, RefNumFun refNumFun);

public:
    static void initializeComModule();
    static ClientComModule& getAccess();
    void registerElevator(ElevatorRef elevator);
    void registerFloorButton(ElevatorRef elevator, FloorButtonRef floorButton);
    void registerCallButton(CallButtonRef callButton);
};
