#pragma once
#include "Elevator.h"
#include "FloorButton.h"
#include "CallButton.h"
#include <vector>
#include <map>
#include <functional>
#include <QObject>

class LocalController : public QObject {
    using ElevatorRef = std::reference_wrapper<Elevator>;
    using FloorButtonRef = std::reference_wrapper<FloorButton>;
    using CallButtonRef = std::reference_wrapper<CallButton>;

    std::vector<ElevatorRef> elevators;
    std::map<ElevatorRef, std::vector<FloorButtonRef>> floorButtons;
    std::vector<CallButtonRef> callButtons;

public:
    LocalController();
    void registerElevator(ElevatorRef elevator);
    void registerFloorButton(ElevatorRef elevator, FloorButtonRef floorButton);
    void registerCallButton(CallButtonRef callButton);

public slots:
    void callButtonClicked(int floorNumber);
    void floorButtonClicked(int floorNumber);
};
