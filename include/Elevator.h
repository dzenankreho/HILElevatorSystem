#pragma once
#include <QObject>
#include <functional>

class Elevator : public QObject {
    Q_OBJECT
    int currentFloor;
    int elevatorNumber;

public:
    Elevator(int elevatorNumber);
    int getCurrentFloor() const;
    int getElevatorNumber() const;
    friend bool operator<(std::reference_wrapper<Elevator> m1, std::reference_wrapper<Elevator> m2);

signals:
    void openDoor(int floor);
    void closeDoor(int floor);
    void enableElevatorButtons();
    void disableElevatorButtons();
};

bool operator<(std::reference_wrapper<Elevator> m1, std::reference_wrapper<Elevator> m2);
