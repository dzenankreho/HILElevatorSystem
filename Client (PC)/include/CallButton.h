#pragma once
#include "Button.h"

class CallButton : public Button {
    Q_OBJECT
    static bool areElevatorsFree;

public:
    CallButton(int floorNumber);
    Q_INVOKABLE void buttonPressed() override;
    static void setAreElevatorsFree(bool areElevatorsFree);

signals:
    void checkForFreeElevators();
};
