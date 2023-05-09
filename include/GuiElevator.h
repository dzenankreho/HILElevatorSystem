#pragma once
#include "Elevator.h"
#include <QObject>


class GuiElevator : public QObject, public Elevator {
    Q_OBJECT

public:
    friend bool operator<(std::reference_wrapper<GuiElevator> el1, std::reference_wrapper<GuiElevator> el2);

signals:
    void openDoor(int floor);
    void closeDoor(int floor);
    void enableElevatorButtons();
    void disableElevatorButtons();
};

bool operator<(std::reference_wrapper<GuiElevator> el1, std::reference_wrapper<GuiElevator> el2);
