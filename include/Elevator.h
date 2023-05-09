#pragma once
#include <QObject>
#include <functional>


class Elevator : public QObject {
    Q_OBJECT
    int currentFloor;
    int elevatorNumber;
    bool busy;

public:
    Elevator();
    int getCurrentFloor() const;
    int getElevatorNumber() const;
    friend bool operator<(std::reference_wrapper<Elevator> m1, std::reference_wrapper<Elevator> m2);
    void setCurrentFloor(int floorNumber);
    void setElevatorNumber(int elevatorNumber);
    bool isBusy() const;
    void setBusy(bool busy);

signals:
    void openDoor(int floor);
    void closeDoor(int floor);
    void enableElevatorButtons();
    void disableElevatorButtons();
};

bool operator<(std::reference_wrapper<Elevator> m1, std::reference_wrapper<Elevator> m2);
