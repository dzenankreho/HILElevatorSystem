#pragma once
#include "GuiElevator.h"
#include "FloorButton.h"
#include "CallButton.h"
#include <vector>
#include <map>
#include <functional>
#include <QObject>


class LocalController : public QObject {
    Q_OBJECT

    using GuiElevatorRef = std::reference_wrapper<GuiElevator>;
    using FloorButtonRef = std::reference_wrapper<FloorButton>;
    using CallButtonRef = std::reference_wrapper<CallButton>;

    std::vector<GuiElevatorRef> elevators;
    std::map<GuiElevatorRef, std::vector<FloorButtonRef>> floorButtons;
    std::vector<CallButtonRef> callButtons;

public:
    LocalController();
    void registerElevator(GuiElevatorRef elevator);
    void registerFloorButton(GuiElevatorRef elevator, FloorButtonRef floorButton);
    void registerCallButton(CallButtonRef callButton);

public slots:
    void callButtonClicked(int floorNumber);
    void floorButtonClicked(int floorNumber);
    void areElevatorsFree();
};
