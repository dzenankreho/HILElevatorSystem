#pragma once
#include "Button.h"

class CallButton : public Button {
public:
    CallButton(int floorNumber);
    Q_INVOKABLE void buttonPressed() override;
};
